
#pragma once

#ifndef __LINE_STREAM_INCLUDED__
#define __LINE_STREAM_INCLUDED__

#include "types.h"
#include <fstream>
#include "String.h"

class IoException { };
class OpenFailedException : IoException { };

// ��������� ������ ����� (��������� ���������)
interface ILineStreamReader
{
  // �������
  virtual bool open(const tchar* path) = 0;
  // ���������� ��������� �� ������ ������. false ���� �� �������
  virtual bool first() = 0;
  // �������
  virtual void close() = 0;
  // ������� ������ ��� NULL � ������ �����
  virtual const tchar* line() const = 0;
  // ������� � ���������. false ���� �����
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

  // �������
  virtual bool open(const tchar* path)
  {
    if (is_open()) close();
    // ...
    return m_bIsOpen = true;
  }

  // ���������� ��������� �� ������ ������. false ���� �� �������
  virtual bool first() = 0;

  // �������
  virtual void close()
  {
    if (!is_open()) return;
    // ...
    m_bIsOpen = false;
  }

  // ������� ������ ��� NULL � ������ �����
  virtual const tchar* line() const
  {
  }

  // ������� � ���������. false ���� �����
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