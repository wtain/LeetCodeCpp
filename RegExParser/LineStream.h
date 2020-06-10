
#pragma once

#ifndef __LINE_STREAM_INCLUDED__
#define __LINE_STREAM_INCLUDED__

#include "types.h"
#include <fstream>
#include "String.h"

class IoException { };
class OpenFailedException : IoException { };

// Интерфейс потока строк (семантика итератора)
interface ILineStreamReader
{
  // Открыть
  virtual bool open(const tchar* path) = 0;
  // Установить указатель на первую строку. false если не удалось
  virtual bool first() = 0;
  // Закрыть
  virtual void close() = 0;
  // Текущая строка или NULL в случае конца
  virtual const tchar* line() const = 0;
  // Перейти к следующей. false если конец
  virtual bool next() = 0;
};

class StdLineStreamReader : ILineStreamReader
{
  std::ifstream m_Stream;
  String m_String;
  bool m_bIsOpen;

private:
  bool fetch_line()
  {
  }

public:
  StdLineStreamReader() : m_bIsOpen(false)
  {
  }

  StdLineStreamReader(const tchar* path) : m_bIsOpen(false)
  {
    if (!open(path)) throw OpenFailedException();
  }

  virtual ~StdLineStreamReader()
  {
    if (is_open()) close();
  }

  // Открыть
  virtual bool open(const tchar* path)
  {
    if (is_open()) close();
    // ...
    return m_bIsOpen = true;
  }

  // Установить указатель на первую строку. false если не удалось
  virtual bool first() = 0;

  // Закрыть
  virtual void close()
  {
    if (!is_open()) return;
    // ...
    m_bIsOpen = false;
  }

  // Текущая строка или NULL в случае конца
  virtual const tchar* line() const
  {
  }

  // Перейти к следующей. false если конец
  virtual bool next()
  {
  }

  bool is_open() const
  {
    return m_bIsOpen;
  }
};

class CStyleLineStreamReader : ILineStreamReader
{
};

class WinApiLineStreamReader : ILineStreamReader
{
};

#endif // __LINE_STREAM_INCLUDED__