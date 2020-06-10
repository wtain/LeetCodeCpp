#pragma once

#include "Random.h"

struct Generator
{
	Random r;
	int r1;
	int r2;

	Generator(const Random& r, int r1, int r2)
		: r(r)
		, r1(r1)
		, r2(r2)
	{

	}

	int operator() () const
	{
		return r.Generate(r1, r2);
	}
};
