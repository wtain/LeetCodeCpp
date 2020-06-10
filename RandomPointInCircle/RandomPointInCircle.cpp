
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>

using namespace std;

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

class Solution {
	double r, x, y;
	double r2;

public:
	Solution(double radius, double x_center, double y_center) 
		: r(radius)
		, x(x_center)
		, y(y_center)
	{
		r2 = r*r;
		srand(static_cast<unsigned>(time(nullptr)));
	}

	vector<double> randPoint() 
	{
		/*
		double x1 = random(-1, 1) * r;
		// y1 = -sqrt(r^2-x1^2)..+sqrt(r^2-x1^2)
		double ry = sqrt(r2 - x1*x1);
		double y1 = random(-1, 1) * ry;
		return{ x + x1, y + y1 };
		*/
		double len = sqrt(random(0, 1)) * r;
		double deg = random(0, 1) * 2 * M_PI;
		double x0 = x + len * cos(deg);
		double y0 = y + len * sin(deg);
		return{ x0, y0 };
	}

private:

	double random()
	{
		return static_cast<double>(rand()) / RAND_MAX;
	}

	double random(double a, double b)
	{
		return a + random() * (b - a);
	}
};

int main()
{
	auto p1 = Solution(10, 0, 0).randPoint();
	cout << p1[0] << " " << p1[1] << endl;
    return 0;
}

