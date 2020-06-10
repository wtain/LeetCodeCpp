
#pragma once

#ifndef __TYPES_H_INCLUDED__
#define __TYPES_H_INCLUDED__

typedef char tchar;
#define tstrlen strlen

#ifndef _SIZE_T_DEFINED
typedef unsigned int size_t;
#define _SIZE_T_DEFINED
#endif // _SIZE_T_DEFINED

#ifndef interface
#define interface struct
#endif // interface

#ifndef NULL
#define NULL 0
#endif // NULL

#ifndef _T
#define _T(x) (x)
#endif // _T

#define INLINE __forceinline

template <class T>
INLINE bool IN(const T& x, const T& a, const T& b)
{
  if (x < a) return false;
  return (x <= b);
}

class AssertionFailedException { };

#ifndef ASSERT
#ifdef _DEBUG
#define ASSERT(x) { if (!(x)) throw AssertionFailedException(); }
#else // _DEBUG
#define ASSERT(x)
#endif // _DEBUG
#endif // ASSERT

#endif // __TYPES_H_INCLUDED__