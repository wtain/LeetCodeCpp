#pragma once

#include <cstdlib>
#include <ctime>

class Random
{
public:
	Random()
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	int Generate(int r1, int r2) const
	{
		return r1 + std::rand() % (r2 - r1 + 1);
	}

	double Generate() const
	{
		return static_cast<double>(std::rand()) / RAND_MAX;
	}
};