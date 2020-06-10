
#include "RegEx.h"
#include "String.h"

class RegExTest
{
  String m_sString;
  RegEx  m_RegEx;
  bool   m_bResult;

public:
  RegExTest(const tchar* str, const tchar* regex, bool result) : 
    m_sString(str), m_RegEx(regex), m_bResult(result)
  {
  }

  bool execute() const
  {
    return (m_bResult == m_RegEx.Match(m_sString));
  }
};

int main(int argc, char* argv[])
{
  //RegEx regex("*Test*");
  //String str;
  
  ASSERT(RegExTest("AAATestAAA", "*Test*", true).execute());
  ASSERT(RegExTest("AAATestAAA", "**Te*st**", true).execute());
  ASSERT(RegExTest("AAATestAAA", "???Test???", true).execute());
  ASSERT(RegExTest("AAATestAAA", "???TestA???", false).execute());
  ASSERT(RegExTest("124", "[0-9][0-9][0-9]", true).execute());
  ASSERT(RegExTest("15h", "([0-9]|[a-f]|[A-F])([0-9]|[a-f]|[A-F])h", true).execute());
  ASSERT(RegExTest("64h", "([0-9]|[a-f]|[A-F])([0-9]|[a-f]|[A-F])h", true).execute());
  ASSERT(RegExTest("AAh", "([0-9]|[a-f]|[A-F])([0-9]|[a-f]|[A-F])h", true).execute());
  ASSERT(RegExTest("1Fh", "([0-9]|[a-f]|[A-F])([0-9]|[a-f]|[A-F])h", true).execute());
  ASSERT(RegExTest("F1h", "([0-9]|[a-f]|[A-F])([0-9]|[a-f]|[A-F])h", true).execute());
  ASSERT(RegExTest("hhh", "([0-9]|[a-f]|[A-F])([0-9]|[a-f]|[A-F])h", false).execute());
  ASSERT(RegExTest("F", "[0-9|a-f|A-F]", true).execute());
  ASSERT(RegExTest("H", "[0-9|a-f|A-F]", false).execute());
  ASSERT(RegExTest("9", "[0-9|a-f|A-F]", true).execute());
  ASSERT(RegExTest("9", "{157\\\\}", false).execute());
  ASSERT(RegExTest("\\", "{157\\\\}", true).execute());
	
  return 0;
}

