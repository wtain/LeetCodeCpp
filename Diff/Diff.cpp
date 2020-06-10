// Diff.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Matrix
{
	size_t m_width;
	size_t m_height;
	std::vector<size_t> m_data;
public:
	Matrix(size_t w, size_t h)
		: m_width(w)
		, m_height(h)
	{
		m_data.resize(w*h, 0);
	}

	size_t operator() (size_t i, size_t j) const
	{
		return m_data[i*m_width + j];
	}

	size_t& operator() (size_t i, size_t j)
	{
		return m_data[i*m_width + j];
	}
};

std::string LCS(const std::string& s1, const std::string& s2)
{
	Matrix m(s1.length()+1, s2.length()+1);
	std::string rv;
	for (size_t i = 0; i != s1.length(); ++i)
	{
		for (size_t j = 0; j != s2.length(); ++j)
		{
			if (s1[i] == s2[j])
			{
				m(i + 1, j + 1) = m(i, j) + 1;
				rv += s1[i];
			}
			else
				m(i + 1, j + 1) = std::max(m(i, j + 1), m(i + 1, j));
		}
	}
	return rv;
}

int main()
{
	std::string s1 = "abcdef";
	std::string s2 = "xbtcuuf";

	std::cout << LCS(s1, s2) << std::endl;

    return 0;
}

