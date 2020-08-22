
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3433/
Given a list of non-overlapping axis-aligned rectangles rects, write a function pick which randomly and uniformily picks an integer point in the space covered by the rectangles.

Note:

An integer point is a point that has integer coordinates.
A point on the perimeter of a rectangle is included in the space covered by the rectangles.
ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of the bottom-left corner, and [x2, y2] are the integer coordinates of the top-right corner.
length and width of each rectangle does not exceed 2000.
1 <= rects.length <= 100
pick return a point as an array of integer coordinates [p_x, p_y]
pick is called at most 10000 times.
Example 1:

Input:
["Solution","pick","pick","pick"]
[[[[1,1,5,5]]],[],[],[]]
Output:
[null,[4,1],[4,1],[3,3]]
Example 2:

Input:
["Solution","pick","pick","pick","pick","pick"]
[[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
Output:
[null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array of rectangles rects. pick has no arguments. Arguments are always wrapped with a list, even if there aren't any.
*/

//Runtime: 132 ms, faster than 61.03% of C++ online submissions for Random Point in Non - overlapping Rectangles.
//Memory Usage : 67.1 MB, less than 89.67% of C++ online submissions for Random Point in Non - overlapping Rectangles.
class Solution {
public:

	class Random
	{
	public:
		Random()
		{
			srand(static_cast<unsigned>(time(nullptr)));
		}

		int Next()
		{
			return rand();
		}

		int Next(int a, int b)
		{
			return a + Next() % (b - a + 1);
		}
	};

	Solution(vector<vector<int>>& rects) : rects(rects) {
		squares.reserve(rects.size());
		starts.reserve(rects.size());
		int prevStart = 0;
		for (const auto& r : rects) {
			const auto x1 = r[0];
			const auto y1 = r[1];
			const auto x2 = r[2];
			const auto y2 = r[3];
			squares.emplace_back((x2-x1+1) * (y2-y1)+1);
			prevStart += squares.back();
			starts.emplace_back(prevStart);
		}
		sumS = prevStart;
	}

	vector<int> pick() {
		auto s = rnd.Next(0, sumS-1);
		int idx = upper_bound(begin(starts), end(starts), s) - begin(starts);
		int x = rnd.Next(rects[idx][0], rects[idx][2]);
		int y = rnd.Next(rects[idx][1], rects[idx][3]);
		return{x,y};
	}

private:
	Random rnd;
	vector<vector<int>> rects;
	vector<int> squares;
	vector<int> starts;
	int sumS;
};

/**
* Your Solution object will be instantiated and called as such:
* Solution* obj = new Solution(rects);
* vector<int> param_1 = obj->pick();
*/

void print(const vector<int>& r) {
	cout << r[0] << " " << r[1] << endl;
}

int main()
{
	{
		Solution s(vector<vector<int>>{ {1,1,5,5} });
		print(s.pick());
		print(s.pick());
		print(s.pick());
	}

	{
		Solution s(vector<vector<int>>{ 
			{-2, -2, -1, -1},
			{ 1, 0, 3, 0 },
			{1, 1, 5, 5} 
		});
		print(s.pick());
		print(s.pick());
		print(s.pick());
		print(s.pick());
	}

	cout << endl << endl;

	{
		vector<vector<int>> counts(10, vector<int>(10));
		Solution s(vector<vector<int>>{ {1, 1, 5, 5} });
		const int N = 1000;
		for (int i = 0; i < N; ++i) {
			auto r = s.pick();
			counts[r[0]][r[1]]++;
		}
		for (const auto & row : counts) {
			copy(begin(row), end(row), ostream_iterator<int>(cout, " "));
			cout << endl;
		}
		cout << endl;
	}

	cout << endl << endl;

	{
		vector<vector<int>> counts(10, vector<int>(10));
		Solution s(vector<vector<int>>{ {1, 1, 5, 5}, {6,6,8,8} });
		const int N = 1000;
		for (int i = 0; i < N; ++i) {
			auto r = s.pick();
			counts[r[0]][r[1]]++;
		}
		for (const auto & row : counts) {
			copy(begin(row), end(row), ostream_iterator<int>(cout, " "));
			cout << endl;
		}
		cout << endl;
	}

	{
		vector<vector<int>> counts(10, vector<int>(10));
		Solution s(vector<vector<int>>{ {1, 1, 1, 1}, { 2,2,2,2 }, { 3,3,3,3 }, { 4,4,4,4 }, { 5,5,5,5 } });
		const int N = 10000;
		for (int i = 0; i < N; ++i) {
			auto r = s.pick();
			counts[r[0]][r[1]]++;
		}
		for (const auto & row : counts) {
			copy(begin(row), end(row), ostream_iterator<int>(cout, " "));
			cout << endl;
		}
		cout << endl;
	}

    return 0;
}

