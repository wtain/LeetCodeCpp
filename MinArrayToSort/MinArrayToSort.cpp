
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

template <class TIter, class TComp>
size_t MinArrayToSortImpl(const TIter b, const TIter e, const TComp compare)
{
	auto next = b;
	if (next == e)
		return 0;
	const int l = *b;
	auto it = next++;
	for (; next != e; ++it, ++next)
		if (compare(*next, *it))
			break;

	if (next == e)
		return 0;

	const auto w = next;

	const int a = *next++;
	while (next != e && !compare(*next, a))
		++next;

	// todo: remember MAX and do another iteration...

	if (compare(a, l)) // todo: decide from which element to calculate the distance (internal to interval)
		return std::distance(b, next);
	return std::distance(w, next) + 1;
}

size_t MinArrayToSort(const std::vector<int>& v)
{
	size_t m1 = MinArrayToSortImpl(std::begin(v), std::end(v), std::less<int>());
	//return m1;
	size_t m2 = MinArrayToSortImpl(std::rbegin(v), std::rend(v), std::greater<int>());
	return std::min(m1, m2);
}

// b1 b2 b3 ... bK a1 a2 .. aL c1 c2 ... cM
// b1 .. bK (K) a1 .. aL (L) c1 .. cM (M)
// B(K) A(L) C(M) ...
// => min(K+L, M+L)=L+min(K, M)    ++   


/*

 a1..ak b

 ai <= aj <=> i < j

 b > ak, E i0 : a1 <= ... <= b <= .. <= ak

 a1..ak b1 b2

 b1 > ak

 b2 < ak
 b2 <= b1

 b2 >= ak
 b2 < b1

*/

bool IsSorted(const std::vector<int>& v)
{
	const size_t n = v.size();
	for (size_t i = 1; i < n; ++i)
		if (v[i - 1] > v[i])
			return false;
	return true;
}

size_t GetMinArrayToSortCorrect(const std::vector<int>& v)
{
	const int n = v.size();
	if (!n)
		return 0;
	int b = 0, e = n - 1;
	while (b + 1 < n && v[b] < v[b + 1])
		++b;

	if (b == n-1)
		return 0;

	for (e = n - 1; e > 0; e--)
	{
		if (v[e - 1] > v[e])
			break;
	}

	int min = v[b], max = v[b];
	for (size_t i = b + 1; i <= e; ++i)
	{
		if (v[i] < min)
			min = v[i];
		if (v[i] > max)
			max = v[i];
	}
	
	for (size_t i = 0; i < b; ++i)
	{
		if (v[i] > min)
		{
			b = i;
			break;
		}
	}

	for (size_t i = n-1; i > e; --i)
	{
		if (v[i] < max)
		{
			e = i;
			break;
		}
	}

	return e - b + 1;
}

size_t GetMinArrayToSortSlow(const std::vector<int>& v)
{
	const size_t n = v.size();
	if (IsSorted(v))
		return 0;
	if (n < 2)
		return n;
	for (size_t l = 2; l <= n - 1; ++l)
	{
		for (size_t i0 = 0; i0 <= n - l; ++i0)
		{
			std::vector<int> v1 = v;
			std::sort(std::begin(v1) + i0, std::begin(v1) + i0 + l);
			if (IsSorted(v1))
				return l;
		}
	}
	return n;
}

void Test(const std::vector<int>& v, const size_t expected)
{
	//const size_t actual = MinArrayToSort(v);
	const size_t actual = GetMinArrayToSortCorrect(v);
	const size_t slow_result = GetMinArrayToSortSlow(v);
	std::copy(std::begin(v), std::end(v), std::ostream_iterator<int>(std::cout, " "));
	std::cout << " => " << actual << std::endl;
	if (actual == expected)
		std::cout << "OK, slow = " << slow_result;
	else
		std::cout << "FAILED - (expected: " << expected << "), slow = " << slow_result;
	std::cout << std::endl;
}

int main()
{
	std::vector<std::pair<std::vector<int>, size_t>> tests = 
	{
		{ { 5, 1, 2, 3, 4 }, 5 },
		{ { 5, 5, 5, 1, 2, 3, 4 }, 7 },
		{ { 1, 2, 3, 4, 5 }, 0 },
		{ { 1, 2, 3, 5, 4 }, 2 },
		{ { 2, 1, 3, 4, 5 }, 2 },
		{ { 1, 2, 5, 3, 4 }, 3 },
		{ { 2, 3, 1, 4, 5 }, 3 },
		{ {}, 0 },
		{ { 1 }, 0 },
		{ { 2, 1 }, 2 },
		{ { 1, 2 }, 0 },
		{ { 2, 3, 4, 5, 1 }, 5 },
		{ { 1, 2, 3, 1, 2, 5 }, 4 },
		{ { 1, 2, 3, 2, 4, 5 }, 2 },
		{ { 1, 2, 3, 1, 2, 5, 1 }, 6 },
		{ { 1, 2, 3, 4, 2}, 3 },
		{ { 4, 5, 6, 1, 2, 3, 0, 0, 0 }, 9 },
		{ { 1, 2, 2, 3, 2, 1, 0, 0, 0 }, 9 },
		{ { 1, 2, 2, 3, 2, 2, 0, 0, 0 }, 9 },
		/*  0  0  0  0  1
		    1  1  1  1  0*/              
	};

	/*
	const std::vector<int> v1  = { 5, 1, 2, 3, 4};
	const std::vector<int> v2  = { 5, 5, 5, 1, 2, 3, 4 };
	const std::vector<int> v3  = { 1, 2, 3, 4, 5 };
	const std::vector<int> v4  = { 1, 2, 3, 5, 4 };
	const std::vector<int> v5  = { 2, 1, 3, 4, 5 };
	const std::vector<int> v6  = { 1, 2, 5, 3, 4 };
	const std::vector<int> v7  = { 2, 3, 1, 4, 5 };
	const std::vector<int> v8  = {};
	const std::vector<int> v9  = { 1 };
	const std::vector<int> v10 = { 2, 1 };
	const std::vector<int> v11 = { 1, 2 };
	const std::vector<int> v12 = { 2, 3, 4, 5, 1 };
	const std::vector<int> v13 = { 1, 2, 3, 1, 2, 5 };
	const std::vector<int> v14 = { 1, 2, 3, 2, 4, 5 };
	const std::vector<int> v15 = { 1, 2, 3, 1, 2, 5, 1 };
	//const std::vector<int> v16 = { 1, 2, 3, 1, 2, 5 };
	*/

	/*Test(v1, 5);
	Test(v2, 7);
	Test(v3, 0);
	Test(v4, 2);
	Test(v5, 2);
	Test(v6, 3);
	Test(v7, 3);
	Test(v8, 0);
	Test(v9, 0);
	Test(v10, 2);
	Test(v11, 0);
	Test(v12, 5);
	Test(v13, 4);
	Test(v14, 2);
	Test(v15, 6);*/

	for (const auto test: tests)
		Test(test.first, test.second);


    return 0;
}

