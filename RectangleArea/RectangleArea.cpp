
#include <iostream>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/rectangle-area/

Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Example:

Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45
Note:

Assume that the total area is never beyond the maximum possible value of int.

*/

// WRONG
//class Solution {
//public:
//
//	struct Point {
//
//		int x, y;
//
//		Point(int x, int y) : x(x), y(y) {}
//	};
//
//	static pair<int, int> crossIntervals(const pair<int, int>& i1, const pair<int, int>& i2) {
//		if (i1.first > i2.first)
//			return crossIntervals(i2, i1);
//		return make_pair(i2.first, min(i1.second, i2.second));
//	}
//
//	struct Rectangle {
//
//		Point bottomLeft, topRight;
//
//		Rectangle(const Point& bottomLeft, const Point& topRight) : bottomLeft(bottomLeft), topRight(topRight) {}
//
//		Rectangle(const pair<int, int>& wint, const pair<int, int>& hint) : 
//			Rectangle(Point(wint.first, hint.first),
//				Point(wint.second, hint.second))
//		{}
//
//		int Width() const { return topRight.x - bottomLeft.x; }
//
//		int Height() const { return topRight.y - bottomLeft.y; }
//
//		unsigned long long Area() const { return Width() * Height(); }
//
//		bool isInside(const Point& p) const {
//			return 
//				p.x >= bottomLeft.x && p.x <= topRight.x &&
//				p.y >= bottomLeft.y && p.y <= topRight.y;
//		}
//
//		Point TopLeft() const { return Point(bottomLeft.x, topRight.y); }
//
//		Point BottomRight() const { return Point(topRight.x, bottomLeft.y); }
//
//		bool isAnyVerticleInside(const Rectangle& other) const {
//			return
//				isInside(other.bottomLeft) ||
//				isInside(other.topRight) ||
//				isInside(other.BottomRight()) ||
//				isInside(other.TopLeft());
//		}
//
//		bool isCrossing(const Rectangle& other) const {
//			return 
//				isAnyVerticleInside(other) ||
//				other.isAnyVerticleInside(*this);
//		}
//
//		pair<int, int> widthInterval() const { return make_pair(bottomLeft.x, topRight.x); }
//		
//		pair<int, int> heightInterval() const { return make_pair(bottomLeft.y, topRight.y); }
//
//		Rectangle getCross(const Rectangle& other) const {
//			return Rectangle(crossIntervals(widthInterval(), other.widthInterval()), 
//				crossIntervals(heightInterval(), other.heightInterval()));
//		}
//	};
//
//	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
//		Point p1(A, B), p2(C, D), p3(E, F), p4(G, H);
//		Rectangle r1(p1, p2);
//		Rectangle r2(p3, p4);
//		unsigned long long area = r1.Area() + r2.Area();
//		if (r1.isCrossing(r2))
//			area -= r1.getCross(r2).Area();
//			
//		return area;
//	}
//};

//Runtime: 12 ms, faster than 52.99% of C++ online submissions for Rectangle Area.
//Memory Usage : 6 MB, less than 100.00% of C++ online submissions for Rectangle Area.
class Solution {
public:

	struct Point {

		int x, y;

		Point(int x, int y) : x(x), y(y) {}
	};

	static pair<int, int> crossIntervals(const pair<int, int>& i1, const pair<int, int>& i2) {
		if (i1.first > i2.first)
			return crossIntervals(i2, i1);
		if (i2.first >= i1.second)
			return make_pair(0, 0);
		return make_pair(i2.first, min(i1.second, i2.second));
	}

	struct Rectangle {

		Point bottomLeft, topRight;

		Rectangle(const Point& bottomLeft, const Point& topRight) : bottomLeft(bottomLeft), topRight(topRight) {}

		Rectangle(const pair<int, int>& wint, const pair<int, int>& hint) :
			Rectangle(Point(wint.first, hint.first),
				Point(wint.second, hint.second))
		{}

		int Width() const { return topRight.x - bottomLeft.x; }

		int Height() const { return topRight.y - bottomLeft.y; }

		unsigned long long Area() const { return Width() * Height(); }

		pair<int, int> widthInterval() const { return make_pair(bottomLeft.x, topRight.x); }

		pair<int, int> heightInterval() const { return make_pair(bottomLeft.y, topRight.y); }

		Rectangle getCross(const Rectangle& other) const {
			return Rectangle(crossIntervals(widthInterval(), other.widthInterval()),
				crossIntervals(heightInterval(), other.heightInterval()));
		}
	};

	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		Point p1(A, B), p2(C, D), p3(E, F), p4(G, H);
		Rectangle r1(p1, p2);
		Rectangle r2(p3, p4);
		unsigned long long area = r1.Area() - r1.getCross(r2).Area() + r2.Area();
		
		return area;
	}
};

int main()
{
	cout << Solution().computeArea(-2, -2, 2, 2, 3, 3, 4, 4) << endl; // 17
	cout << Solution().computeArea(-5, -2, 5, 1, -3, -3, 3, 3) << endl; // 48
	cout << Solution().computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl; // 45
	cout << Solution().computeArea(0, 0, 50000, 40000, 0, 0, 50000, 40000) << endl; // 2000000000
	

    return 0;
}

