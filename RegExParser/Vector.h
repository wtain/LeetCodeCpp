
#pragma once

#ifndef __VECTOR_H_INCLUDED__
#define __VECTOR_H_INCLUDED__

#include "types.h"
#include <stdlib.h> // для malloc/realloc/free

// Векторные аллокаторы

template <class T>
class CStyleAllocator
{
public:
  static T* allocate(size_t nCount) // Не вызывает конструкторы!
  {
    return (T*) malloc(nCount * sizeof(T));
  }

  static T* reallocate(T* pPtr, size_t nCount, size_t nOldCount)
  {
    return (T*) realloc(pPtr, nCount);
  }

  static void deallocate(T* pPtr)
  {
    free(pPtr);
  }
};

// copypaste(((
template <class T>
class CStyleAllocatorWithConstructorCall
{
public:
  static T* allocate(size_t nCount)
  {
    T* pPtr = (T*) malloc(nCount * sizeof(T));
    
    for (size_t i = 0, T* p = pPtr;; i < nCount; i++, p++)
      *p = new T();
    return pPtr;
  }

  static T* reallocate(T* pPtr, size_t nCount, size_t nOldCount)
  {
    return (T*) realloc(pPtr, nCount);
  }

  static void deallocate(T* pPtr)
  {
    free(pPtr);
  }
};

template <class T>
class NewAllocator
{
public:
  static T* allocate(size_t nCount) // Не вызывает конструкторы!
  {
    return new T[nCount];
  }

  static T* reallocate(T* pPtr, size_t nCount, size_t nOldCount)
  {
    T* pNewPtr = allocate(nCount);
    memcpy(pNewPtr, pPtr, sizeof(T) * nOldCount);
    delete[] pPtr;
    return pNewPtr;
  }

  static void deallocate(T* pPtr)
  {
    delete[] pPtr;
  }
};

template <class T, template <class> class Allocator = CStyleAllocator >
class Vector
{
  T* m_pValues;
  size_t m_nSize, m_nAlloced;

  static const size_t INIT_SIZE = 16;

protected:
  T* ptr()
  {
    return m_pValues;
  }

  const T* ptr() const
  {
    return m_pValues;
  }

  size_t alloced() const
  {
    return m_nAlloced;
  }

private:
  void _init(size_t size = INIT_SIZE)
  {
    m_nSize = 0;
    m_pValues = Allocator<T>::allocate(m_nAlloced = size);
  }

  template <class Ty>
  void _copy(const Vector<Ty>& copy)
  {
    template <class Ty>
    struct copy_func
    {
      const Vector<Tx>& m_This;
      size_t i;
      copy_func(const Vector<Tx>& This) : m_This(This), i(0) {}
      bool operator() (const Ty& elem)
      {
        m_This[i++] = static_cast<T>(elem);
        return false;
      }
    };
    copy.foreach(copy_func<Ty>());
  }

  /*template <> // todo: Для эффективной реализации через memcpy
                // необходимо распознавание базовых типов. 
                // Для этого нужно взять реализацию списков типов 
                // из Александреску "Современное проектирование на C++", 
                // где-то в начале книги
  void _copy<T>(const Vector<Ty>& copy)
  {
    memcpy();
  }*/

  void _destroy()
  {
    Allocator<T>::deallocate(m_pValues);
  }

  void _destroy_tail(size_t newsize)
  {
    for (size_t i = newsize; i < size(); i++)
      (*this)[i].~T();
    m_nSize = newsize;
  }

public:
  explicit Vector(size_t size = INIT_SIZE)
  {
    _init(size);
  }

  template <class Ty>
  Vector(const Ty* pPtr, size_t n)
  {
    _init(n);
    for (size_t i = 0; i < n; i++)
      m_pValues[i] = static_cast<T>(pPtr[i]);
    m_nSize = n;
  }

  template <class Ty>
  Vector(const Vector<Ty>& copy)
  {
    _init(copy.size());
    _copy(copy);
    m_nSize = copy.size();
  }

  template <class Ty>
  Vector<T>& operator= (const Vector<Ty>& copy)
  {
    if (m_nAlloced >= copy.size())
    {
      _copy(copy);
      _destroy_tail(copy.size());
    }
    else
    {
      _destroy();
      _init(copy.size());
      _copy(copy);
      m_nSize = copy.size();
    }
    return *this;
  }

  virtual ~Vector()
  {
    _destroy();
  }

  void resize(size_t newsize)
  {
    if (newsize == size()) return;
    if (newsize < size())
    {
      _destroy_tail(newsize);
      return;
    }
    if (m_nAlloced < newsize)
      m_pValues = Allocator<T>::reallocate(m_pValues, m_nAlloced = newsize, size());
    m_nSize = newsize;
  }

  void reserve(size_t newsize)
  {
    if (m_nAlloced < newsize)
      m_pValues = Allocator<T>::reallocate(m_pValues, m_nAlloced = newsize, size());
  }

  void push_back(const T& item)
  {
    if (m_nSize == m_nAlloced)
      m_pValues = Allocator<T>::reallocate(m_pValues, m_nAlloced *= 2, m_nAlloced);
    m_pValues[m_nSize++] = item;
  }

  void clear()
  {
    m_nSize = 0;
  }

  size_t size() const
  {
    return m_nSize;
  }

  bool isempty() const
  {
    return !m_nSize;
  }

  T& operator[] (size_t pos)
  {
    return m_pValues[pos];
  }

  const T& operator[] (size_t pos) const
  {
    return m_pValues[pos];
  }

  // copypaste(((
  template<class Func>
  bool foreach(Func& f)
  {
    for (size_t i = 0; i < m_nSize; i++)
      if (f(m_pValues[i]))
        return true;
    return false;
  }

  // Семантика foreach. Если f возвращает true, дальше не итерирует, возвращает true. Иначе false
  template<class Func>
  bool foreach(const Func& f) const
  {
    for (size_t i = 0; i < m_nSize; i++)
      if (f(m_pValues[i]))
        return true;
    return false;
  }
};

#endif // __VECTOR_H_INCLUDED__