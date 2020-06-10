
#pragma once

#ifndef __STRING_H_INCLUDED__
#define __STRING_H_INCLUDED__

#include <string.h>

#include "types.h"
#include "Vector.h"
//#include "LineStream.h"

// В некоторых случаях мб можно не читать целую строчку? 
// Наверное, нет. Всё равно нужно до конца строки дочитывать - 
// мы не знаем, где строка в потоке заканчивается. Так что 
// на виртуальные строки можно и забить.
// Сначала думал о ситуации, когда регэксп 'AAA...', то есть 
// начинается с терминалов, что позволяет сразу не рассматривать 
// строки, которые не начинаются с 'AAA' (с указанных терминалов). 
// Но всё равно при переходе к следующей строке нужно пробежаться 
// до конца текущей, пусть и уже отвергнутой. При матчинге 
// регексп сразу скажет, что строка не подходит, так что 
// с производительностью и так всё должно быть хорошо.

//class VirtualString
//{
//public:
//  VirtualString(ILineStreamReader* pInputStream)
//  {
//  }
//};

// mb use Vector?
class String : public Vector<char>
{
  //char* m_pChars;
  //Vector<char> m_Chars;
  //size_t m_nLength;
public:

  typedef const char* const_iterator;
  typedef char* iterator;

  String(const char* str) : Vector<char>(str, strlen(str)+1)
  {
    //ptr()[tstrlen(str)] = 0;
  }

  String() : Vector<char>()
  {
    push_back(0);
  }

  String(const String& copy) : Vector<char>(copy.c_str(), copy.length()+1)
  {
  }
  
  static size_t get_length(const char* start, const char* end = NULL)
  {
    return end ? (start <= end ? end-start+1 : 0) : strlen(start);
  }

  // !!! BE CAREFUL WITH ZERO STRINGS HERE !!!
  String(const char* start, const char* end/* = NULL*/) : Vector<char>(get_length(start, end)) // if NULL, searching for 0 (0-terminated end)
  {
    ptr()[get_length(start, end)] = 0;
  }

  virtual ~String()
  {
  }

  String& operator= (const String& right)
  {
    Vector<char>::operator=(right);
    return *this;
  }

  String& operator += (char c)
  {
    ptr()[length()] = c;
    push_back(0);
    return *this;
  }

  size_t length() const
  {
    return size() ? size()-1 : 0;
  }

  char& operator[] (size_t pos)
  {
    return (*this)[pos];
  }

  const char& operator[] (size_t pos) const
  {
    return Vector<char>::operator[] (pos);
  }

  const char* c_str() const
  {
    return ptr();
  }

  bool operator == (const String& right) const
  {
    if (size() != right.size()) return false;
    for (size_t i = 0; i < size(); i++)
      if ((*this)[i] != right[i])
        return false;
    return true;
  }

  bool operator == (const char* right) const
  {
    if (size() != strlen(right)) return false;
    for (size_t i = 0; i < size(); i++)
      if ((*this)[i] != right[i])
        return false;
    return true;
  }

  bool empty() const
  {
    return Vector<char>::isempty();
  }

  // Сравнить начиная с позиции pos. failpos, если не NULL, - позиция первого несоответствия
  bool Match(const String& str, size_t pos, size_t* failpos = NULL) const
  {
    for (size_t i = 0, sp = pos; i < length(); i++, sp++)
    {
      if (str.length() <= sp || (*this)[i] != str[sp])
      {
        if (failpos) *failpos = sp;
        return false;
      }
    }
    return true;
  }
};

#endif // __STRING_H_INCLUDED__