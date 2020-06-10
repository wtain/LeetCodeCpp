
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <algorithm>
#include <map>

void QSortImpl(std::vector<int>& v, int l, int r)
{
	int m = l + (r - l) / 2;
	int p = v[m];
	int i = l, j = r;
	do
	{
		while (v[i] < p) ++i;
		while (v[j] > p) --j;
		if (i <= j)
		{
			std::swap(v[i], v[j]);

			i++; j--;
		}
	} 
	while (i < j);
	if (l < j)
		QSortImpl(v, l, j);
	if (i < r)
		QSortImpl(v, i, r);
}

void QSort(std::vector<int>& v)
{
	QSortImpl(v, 0, v.size() - 1);
}

class Random
{
	int m_min, m_max;
public:
	Random(int _min, int _max)
		: m_min(_min)
		, m_max(_max)
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	int operator() () const
	{
		return m_min + rand() % (m_max - m_min + 1);
	}
};

bool IsSorted(const std::vector<int>& v)
{
	for (size_t i = 1, n = v.size() - 1; i != n; ++i)
		if (v[i - 1] > v[i])
			return false;
	return true;
}

std::map<int, int> GetElems(const std::vector<int>& v)
{
	std::map<int, int> m;
	for (const int i : v)
		m[i] ++;
	return m;
}

int main()
{
	std::vector<int> v;

	const int nTests = 1000;

	for (int i = 0; i != nTests; ++i)
	{
		for (int N = 19; N <= 20; ++N)
		{
			v.clear();
			std::generate_n(std::back_inserter(v), N, Random(1, 100));
			const auto m1 = GetElems(v);
			QSort(v);
			const auto m2 = GetElems(v);
			if (!IsSorted(v))
				std::cout << "Failed 1" << std::endl;
			if (m1 != m2)
				std::cout << "Failed 2" << std::endl;
		}
	}

    return 0;
}

