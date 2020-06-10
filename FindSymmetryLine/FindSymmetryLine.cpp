
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Set of int points. Find a vertical symmetry line which divides the set. If any

struct Point
{
	int x, y;

	Point(int x, int y) : x(x), y(y) {}

	bool operator == (const Point& p) const
	{
		return x == p.x && y == p.y;
	}

	struct Hash
	{
		size_t operator() (const Point& p) const
		{
			return p.x ^ p.y;
		}
	};
};

Point reflect(const double x, const Point& p)
{
	return Point(static_cast<int>(2*x-p.x), p.y);
}

pair<double, bool> findSymmetryLine(const vector<Point>& points)
{
	double x = 0.0;
	const int n = points.size();
	for (int i = 0; i < n; ++i)
		x += points[i].x;
	x /= static_cast<double>(n);

	unordered_set<Point, Point::Hash> phash;
	for (int i = 0; i < n; ++i)
	{
		const auto& p = points[i];
		if (static_cast<double>(p.x) == x)
			continue;
		Point ps = reflect(x, p);
		auto it = phash.find(ps);
		if (it != end(phash))
			phash.erase(it);
		else
			phash.insert(p);
	}
	if (phash.empty())
		return make_pair(x, true);
	return make_pair(0.0, false);
}

int main()
{
	vector<Point> points = 
	{
		{ 6, 6 },
		{ 7, 9 },
		{ 8, 9 },
		{ 9, 6 },
		{ 8, 3 },
		{ 7, 3 }
	};

	auto r = findSymmetryLine(points);
	cout << r.first << " " << boolalpha << r.second << endl; // 7.5

	points.push_back(Point(0, 0));
	r = findSymmetryLine(points);
	cout << r.first << " " << boolalpha << r.second << endl; // false

    return 0;
}

