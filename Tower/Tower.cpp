
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

struct Compare
{
	bool operator () (const std::pair<int, int>& l, const std::pair<int, int>& r) const
	{
		if (l.first < r.first)
			return true;
		if (l.first > r.first)
			return false;
		return l.second < r.second;
	}
};

void BuildTower(const std::vector<std::pair<int, int>>& a, std::vector<std::pair<int, int>>& b)
{
	b = a;
	std::sort(b.begin(), b.end(), Compare());
}

void PrintTower(const std::vector<std::pair<int, int>>& t)
{
	bool f = true;
	for (const auto& i : t)
	{
		if (!f)
			std::cout << ", ";

		std::cout << "(" << i.first << ", " << i.second << ")";

		if (f) f = false;
	}
	std::cout << std::endl;
}

int main()
{
	//std::vector<std::pair<int, int>> a = { {65, 100}, {70, 150}, {56, 90}, {75, 190}, {60, 95}, {68, 110} };
	std::vector<std::pair<int, int>> a = { { 65, 100 },{ 70, 150 },{ 56, 90 },{ 75, 190 },{ 60, 200 },{ 68, 110 } };
	std::vector<std::pair<int, int>> b;

	PrintTower(a);

	std::cout << std::endl;
	BuildTower(a, b);

	PrintTower(b);

    return 0;
}

