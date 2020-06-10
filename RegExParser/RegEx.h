
#pragma once

#ifndef __REG_EX_H_INCLUDED__
#define __REG_EX_H_INCLUDED__

#include "types.h"
#include "String.h"
#include "Vector.h"
#include <stdarg.h> // Для элипсиса
//#include <string.h> // для strlen
//#include <typeinfo>
//#include <iostream>

class ParserHelpers
{
public:

  static bool is_screenable(tchar c)
  {
    return (c == _T('\\') || 
            c == _T('[') || c == _T(']') || 
            c == _T('(') || c == _T(')') ||
            c == _T('*') || c == _T('?') ||
            c == _T('-') || c == _T('|'));
  }

  static bool is_delim(tchar c)
  {
    return (_T('[') == c) || (_T(']') == c) ||
           (_T('(') == c) || (_T(')') == c) ||
           (_T('*') == c) || (_T('?') == c);
  }

  static bool is_end(const tchar* p, const tchar* end)
  {
    return !p || !*p || p == (end+1);
  }

  static bool is_open_bracket(tchar ch)
  {
    return _T('(') == ch || _T('[') == ch || _T('{') == ch;
  }
};

class RegRuleBase
{
private: 
  RegRuleBase*  m_pNextRule;

protected:

public:
  RegRuleBase() : m_pNextRule(NULL)
  {
  }

  void setnext(RegRuleBase* pNext)
  {
    m_pNextRule = pNext;
  }

  RegRuleBase* next()
  {
    return m_pNextRule;
  }

  const RegRuleBase* next() const
  {
    return m_pNextRule;
  }

  virtual ~RegRuleBase()
  {
  }

  virtual bool Match(const String& str, size_t pos = 0, size_t* failpos = NULL, size_t* endpos = NULL) const = 0;

  bool MatchNext(const String& str, size_t pos = 0, size_t* failpos = NULL, size_t* endpos = NULL) const // mb ref for endpos is better?
  {
    return (next() ? next()->Match(str, pos, failpos, endpos) : true);
  }
};

class TerminalRule : public RegRuleBase
{
  String m_String;
public: 
  TerminalRule(const String& str) : RegRuleBase(), m_String(str)
  {// Проблема в String/Vector (!) - связанная с 0 на конце и длиной!
  }

  TerminalRule(const tchar* start, const tchar* end) : RegRuleBase(), m_String(start, end)
  {
  }

  virtual bool Match(const String& str, size_t pos = 0, size_t* failpos = NULL, size_t* endpos = NULL) const
  {
    if (endpos) *endpos = pos + str.length();
    return m_String.Match(str, pos, failpos) && MatchNext(str, pos + m_String.length(), failpos, endpos);
    //return (str == m_String); // be careful with cases:  Test* and Test for string AAAAATest, TestAAA and AAATestAAA
  }
};

class StarRule : public RegRuleBase
{
public:
  StarRule() : RegRuleBase()
  {
  }

  virtual bool Match(const String& str, size_t pos = 0, size_t* failpos = NULL, size_t* endpos = NULL) const
  {
    size_t start = pos, end = str.length();
    //if (str.empty()) return true;
    if (pos >= end) return true;
    if (!next()) return true;
    while (start < end)
    {
      if (endpos) *endpos = pos;
      if (next()->Match(str, start, failpos, endpos))
        return true;
      //pos ++; // mb increment by offset of the first failed char (it would be faster)
      failpos ? start = *failpos : start++;
    }
    return false;
  }
};

class WildCardRule : public RegRuleBase
{
public: 

  WildCardRule() : RegRuleBase()
  {
  }

  virtual bool Match(const String& str, size_t pos = 0, size_t* failpos = NULL, size_t* endpos = NULL) const
  {
    if (endpos) *endpos = pos + 1;
    return (pos < str.length()) && MatchNext(str, pos+1, failpos, endpos);
  }
};

class EnumRule : public RegRuleBase
{
  Vector<tchar> m_Chars;
public:
  EnumRule(...) : RegRuleBase()
  {
    va_list ap;
    int dummy;
    va_start(ap, dummy);

    for (;;) 
    {
        tchar p = va_arg(ap, tchar);
        if (p == 0) break;
        m_Chars.push_back(p);
    }

    va_end(ap);
  }

  EnumRule(const tchar* begin, const tchar* end) : RegRuleBase()
  {
    for (const tchar* ptr = begin; !ParserHelpers::is_end(ptr, end); ptr++)
      m_Chars.push_back(*ptr);
  }

  struct functor{ 
        tchar m_Char; functor(const String& str, size_t pos) : m_Char(str[pos]) {} 
        bool operator() (const tchar& ch) const 
        { 
          return (m_Char == ch);
        } };

  virtual bool Match(const String& str, size_t pos = 0, size_t* failpos = NULL, size_t* endpos = NULL) const
  {
    if (pos >= str.length()) return false;
    if (endpos) *endpos = pos + 1;
    bool found = m_Chars.foreach(functor(str, pos));
    if (!found && failpos) *failpos = pos;
    return found && MatchNext(str, pos+1, failpos);
  }
};

class RangeRule : public RegRuleBase
{
  tchar lbnd, hbnd;
public:
  RangeRule(tchar low_bound, tchar high_bound) : RegRuleBase(), lbnd(low_bound), hbnd(high_bound)
  {
  }

  virtual bool Match(const String& str, size_t pos = 0, size_t* failpos = NULL, size_t* endpos = NULL) const
  {
    if (pos >= str.length()) return false;
    if (endpos) *endpos = pos + 1;
    return (IN(str[pos], lbnd, hbnd)) && MatchNext(str, pos+1, failpos);
  }
};

class ChoiceRule : public RegRuleBase
{
  Vector<RegRuleBase*> m_Alternatives;
public:
  ChoiceRule() : RegRuleBase()
  {
  }

  void append_alternative(RegRuleBase* alt_rule)
  {
    m_Alternatives.push_back(alt_rule);
  }

  virtual bool Match(const String& str, size_t pos = 0, size_t* failpos = NULL, size_t* endpos = NULL) const
  {
    struct functor{ 
        const String& m_String; size_t m_Pos; size_t* m_Endpos; functor(const String& str, size_t pos, size_t* endpos) : m_String(str), m_Pos(pos), m_Endpos(endpos) {} 
        bool operator() (const RegRuleBase* pRule) const 
        { 
          return pRule->Match(m_String, m_Pos, NULL, m_Endpos);
        } };

    /*bool found =*/return m_Alternatives.foreach(functor(str, pos, endpos));
    // До какого места доматчили?
  }

  // copypaste(((
  template<class Func> 
  bool foreach(Func& F)
  {
    return m_Alternatives.foreach(F);
  }

  template<class Func> 
  bool foreach(const Func& F) const
  {
    return m_Alternatives.foreach(F);
  }
};

class RegExException { };
class RegExBuildException : public RegExException { };

class RegEx
{
  RegRuleBase* m_pRule;
public:

  // special chars: 
  // \  - screen
  // *  - star
  // ?  - wildcard
  // [] - Range definition bounds
  // -  - Range internal separator
  // () - Alternative definition bounds
  // |  - Alternatives separator
  // {} - Enumeration

  // Examples:
  // [0-9a-hA-H] - WRONG //Alternative of 3 ranges
  // (Test1|Test2|Test3) - multiple alternatives
  // \(\) - Two braces
  // ( - Erroneous regexp
  // \\ - ONE slash
  // {a67} - enumeration

  // * (star) is zero or more any characters
  // ? (wild card) is EXACTLY ONE any character

  explicit RegEx(const tchar* str) : m_pRule(NULL)
  {
    init(str);
  }

  explicit RegEx(const String& str) : m_pRule(NULL)
  {
    init(str.c_str());
  }

  virtual ~RegEx()
  {
    // Нужно обойти всё дерево правил и удалить их все
    dispose(m_pRule);
  }

  bool Match(const String& str) const
  {
    return m_pRule ? m_pRule->Match(str) : true;
  }

  struct dispose_each{dispose_each(){} 
        bool operator() (RegRuleBase* pRule) const 
        {
          RegEx::dispose(pRule); 
          return false;
        }
      };

  static void dispose(RegRuleBase* pRoot)
  {
    RegRuleBase* pPtr = pRoot;
    while (pPtr)
    {
      RegRuleBase* pDel = pPtr;  
      //const std::type_info& ti = typeid(*pPtr);
      ChoiceRule* pChoice = dynamic_cast<ChoiceRule*>(pPtr);
      if (pChoice) pChoice->foreach(dispose_each());
      pPtr = pPtr->next();
      delete pDel;
    }
  }

private:
  typedef void (RegEx::*subexpression_parser)(const tchar* begin, const tchar* end, RegRuleBase* pRule);

  const tchar* parse_braces(const tchar* begin, const tchar* end, subexpression_parser parser, RegRuleBase* pRule)
  {
    struct call_wrapper
    { 
      subexpression_parser m_Parser; 
      RegEx* m_pThis;
    
      call_wrapper(RegEx* pThis, subexpression_parser parser) : 
        m_Parser(parser), m_pThis(pThis){} 
        
      void operator() (const tchar* begin, const tchar* end, RegRuleBase* pRule)
      { 
        (m_pThis->*m_Parser)(begin, end, pRule); 
      } 
    };

    return parse_braces(begin, end, call_wrapper(this, parser), pRule);
  }

  template <class TSubExprPar>
  const tchar* parse_braces(const tchar* begin, const tchar* end, TSubExprPar parser, RegRuleBase* pRule)
  {
    int round_cnt = 0, square_cnt = 0, curve_cnt = 0;
    const tchar* ptr = begin;
    while (!ParserHelpers::is_end(ptr, end))
    {
      if (*ptr == _T('\\'))
      {
        ptr ++;
        if (ParserHelpers::is_end(ptr, end)) throw RegExBuildException(); // Unexpected end reached
        if (!ParserHelpers::is_screenable(*ptr)) throw RegExBuildException(); // Unexpected character
      }
      else if (*ptr == _T('(')) round_cnt ++;
      else if (*ptr == _T(')')) round_cnt --;
      else if (*ptr == _T('[')) square_cnt ++;
      else if (*ptr == _T(']')) square_cnt --;
      else if (*ptr == _T('{')) curve_cnt ++;
      else if (*ptr == _T('}')) curve_cnt --;
      ptr ++;
      if (!(round_cnt || square_cnt || curve_cnt))
      {
        parser(begin+1, ptr-1, pRule);
        return ptr;
      }
    }
    if (round_cnt || square_cnt || curve_cnt) throw RegExBuildException(); // Misbalanced bracket
    return ptr;
  }

  void parse_range(const tchar* begin, const tchar* end, RegRuleBase* pRule)
  {
    const tchar* ptr = begin;
    Vector<RangeRule*> rules;
    try
    {
      do
      {
        if (*ptr == _T('\\'))
        {
          ptr ++;
          if (ParserHelpers::is_end(ptr, end)) throw RegExBuildException(); // Unexpected end
          if (!ParserHelpers::is_screenable(*ptr)) throw RegExBuildException(); // Unexpected character
        }
        const tchar* ptr1 = ptr;
        ptr ++;
        if (ParserHelpers::is_end(ptr, end)) throw RegExBuildException(); // Unexpected end
        if (*ptr != _T('-')) throw RegExBuildException(); // Unexpected character
        ptr ++;
        if (*ptr == _T('\\'))
        {
          ptr ++;
          if (ParserHelpers::is_end(ptr, end)) throw RegExBuildException(); // Unexpected end
          if (!ParserHelpers::is_screenable(*ptr)) throw RegExBuildException(); // Unexpected character
        }
        rules.push_back(new RangeRule(*ptr1, *ptr));
        ptr++; 
        //if (_T(']') != *ptr)
        ptr++;
      }
      while (!ParserHelpers::is_end(ptr, end));
    }
    catch (...)
    {
      struct Func1{Func1(){} bool operator() (RangeRule* pRule) const{RegEx::dispose(pRule); return false;}};

      rules.foreach(Func1());
      throw;
    }
    if (!rules.size()) throw RegExBuildException(); // Empty range
    if (1 == rules.size())
      append(pRule, rules[0]);
    else
    {
      struct Func2{ChoiceRule* m_pChoice; Func2(ChoiceRule* pChoice) : m_pChoice(pChoice){} bool operator() (RangeRule* pRule) const{m_pChoice->append_alternative(pRule); return false;}};

      ChoiceRule* pChoice = new ChoiceRule();
      rules.foreach(Func2(pChoice));
      append(pRule, pChoice);
    }
  }

  void parse_alternatives(const tchar* begin, const tchar* end, RegRuleBase* pRule)
  {
    const tchar* ptr = begin;
    const tchar* ptr1 = ptr;
    RegRuleBase* pAlt = new StarRule(); // random rule
    ChoiceRule* pChoiceRule = new ChoiceRule();
    try
    {
      while (!ParserHelpers::is_end(ptr, end))
      {
        if (_T('|') == *ptr)
        {
          parse(ptr1, ptr-1, pAlt);
          pChoiceRule->append_alternative(pAlt->next());
          pAlt->setnext(NULL);
          ptr1 = ptr+1;
        }
        ptr++;
      }
      if (ptr1 < end)
      {
        parse(ptr1, end-1, pAlt);
        pChoiceRule->append_alternative(pAlt->next());
        pAlt->setnext(NULL);
      }
      append(pRule, pChoiceRule);
    }
    catch (...)
    {
      delete pAlt;
      dispose(pChoiceRule);
      throw;
    }
    delete pAlt;
  }

  void parse_enumeration(const tchar* begin, const tchar* end, RegRuleBase* pRule)
  {
    append(pRule, new EnumRule(begin, end));
  }

  subexpression_parser get_parser(tchar ch)
  {
    if (_T('(') == ch) return &RegEx::parse_alternatives;
    if (_T('{') == ch) return &RegEx::parse_enumeration;
    if (_T('[') == ch) return &RegEx::parse_range;
    throw RegExBuildException(); //Unexpected character
  }

  void append(RegRuleBase* pTarget, RegRuleBase* pRule)
  {
    RegRuleBase* pPtr = pTarget ? pTarget : m_pRule;
    if (NULL == pPtr) m_pRule = pRule;
    else
    { 
      while (pPtr->next()) pPtr = pPtr->next();
      pPtr->setnext(pRule);
    }
  }

  void init(const tchar* str)
  {
    try
    {
      parse(str);
    }
    catch (...)
    {
      dispose(m_pRule);
      throw;
    }
  }

  /*void debug_print(const tchar* str, const tchar* end = NULL) const
  {
    for (const tchar* ptr = str; !ParserHelpers::is_end(ptr, end); ptr++)
      std::cout << *ptr;
    std::cout << std::endl;
  }*/

  void parse(const tchar* str, const tchar* end = NULL, RegRuleBase* pRule = NULL)
  {
    //debug_print(str, end);
    if (!str) return;
    // be careful with expcetions and memory leaks
    //size_t n = strlen(str);
    const tchar* ptr = str;
    const tchar* ptr1;
    while (/* *ptr */ !ParserHelpers::is_end(ptr, end))
    {
      if (ParserHelpers::is_open_bracket(*ptr))
      {
        ptr = parse_braces(ptr, end, get_parser(*ptr), pRule);
      }
      /*
      if (_T('[') == *ptr)
      {
        ptr1 = ptr;
        // CAREFUL!
        while (!is_end(ptr1, end) && *ptr1 != ']') ptr1++;
        if (*ptr1 != ']') throw RegExBuildException(); // Unbalanced bracket
        parse_range(ptr+1, ptr1-1, pRule);
        ptr = ptr1 + 1;
      }
      if (_T('(') == *ptr)
      {
        ptr1 = ptr;
        while (!is_end(ptr1, end) && *ptr1 != ')') ptr1++;
        if (*ptr1 != ')') throw RegExBuildException(); // Unbalanced bracket
        parse_alternatives(ptr+1, ptr1-1, pRule);
        ptr = ptr1 + 1;
      }
      if (_T('{') == *ptr)
      {
        ptr1 = ptr;
        while (!is_end(ptr1, end) && *ptr1 != '}') ptr1++;
        if (*ptr1 != '}') throw RegExBuildException(); // Unbalanced bracket
        parse_enumeration(ptr+1, ptr1-1, pRule);
        ptr = ptr1 + 1;
      }*/
      else if (_T('*') == *ptr)
      {
        append(pRule, new StarRule());
        ptr ++;
      }
      else if (_T('?') == *ptr)
      {
        append(pRule, new WildCardRule());
        ptr ++;
      }
      else // if (_T('\\') == *ptr)
      {
        //ptr1 = ptr+1;
        String str;
        //if (is_end(ptr1, end)) throw RegExBuildException(); // Unexpected end reached
        //if (!is_screenable(*ptr1)) throw RegExBuildException(); // Unexpected character
        //ptr1 ++;
        ptr1 = ptr;
        while (!ParserHelpers::is_end(ptr1, end) && !ParserHelpers::is_delim(*ptr1))
        {
          if (_T('\\') != *ptr1) str += *ptr1;
          else
          {
            ptr1++;
            //if (_T('\\') == *ptr1) ptr1++;
            if (ParserHelpers::is_end(ptr1, end)) throw RegExBuildException(); // Unexpected end reached
            if (!ParserHelpers::is_screenable(*ptr1)) throw RegExBuildException(); // Unexpected character
            str += *ptr1;
          }
          ptr1 ++;
        }
        ptr = ptr1;
        ptr1 --;
        append(pRule, new TerminalRule(str));
      }
    }
  }
};

#endif // __REG_EX_H_INCLUDED__