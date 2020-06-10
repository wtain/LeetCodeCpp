// Performance.cpp : Defines the entry point for the console application.
//

#include <chrono>
#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>

class ScopedTimer
{
	std::string m_name;
	std::chrono::high_resolution_clock::time_point m_start;
	
public:

	explicit ScopedTimer(const std::string& name)
		: m_name(name) 
	{
		m_start = std::chrono::high_resolution_clock::now();
	}

	~ScopedTimer()
	{
		const auto n = std::chrono::high_resolution_clock::now();
		std::cout << m_name << ": "
			<< std::chrono::duration_cast<std::chrono::nanoseconds>(n - m_start).count()
			<< "ns" << std::endl;
	}
};

size_t LinearSearch(const std::vector<int>& v, const int val)
{
	/*
	const size_t N = v.size();
	for (size_t i = 0; i < N; ++i)
	{
		if (v[i] == val)
			return i;
	}*/
	for (const auto & vi : v)
	{
		if (vi == val)
			return (&vi - &v[0]);
	}
	return std::numeric_limits<size_t>::max();
}

int main()
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, 100000000);

	const size_t N = 100'000'000;

	std::vector<int> v;
	{
		ScopedTimer timer("Generate");
		std::generate_n(std::back_inserter(v), N, [&] { return distribution(generator); });
	}
	
	const int X = distribution(generator);

	{
		ScopedTimer timer("LinearSearch");
		const size_t idx = LinearSearch(v, X);
	}

	{
		ScopedTimer timer("LinearSearch - std::find");
		std::find(std::begin(v), std::end(v), X);
	}

	{
		ScopedTimer timer("Sort");
		std::sort(std::begin(v), std::end(v));
	}

	{
		ScopedTimer timer("BinSearch");
		std::binary_search(std::begin(v), std::end(v), X);
	}

	//std::copy(std::begin(v), std::end(v), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}

