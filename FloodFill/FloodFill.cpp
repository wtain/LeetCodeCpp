
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stack>

using namespace std;

/*
https://leetcode.com/problems/flood-fill/

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input:
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation:
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].

*/

class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		const int h = image.size();
		const int w = image[0].size();
		vector<vector<int>> result = image;
		vector<vector<bool>> visited(h, vector<bool>(w, false));
		stack<pair<int, int>> toVisit;
		toVisit.emplace(sr, sc);
		const int color0 = image[sr][sc];
		while (!toVisit.empty()) {
			auto p = toVisit.top(); toVisit.pop();
			int y = p.first;
			int x = p.second;
			visited[y][x] = true;
			result[y][x] = newColor;
			if (y > 0 && !visited[y - 1][x] && result[y - 1][x] == color0)
				toVisit.emplace(y - 1, x);
			if (x > 0 && !visited[y][x - 1] && result[y][x - 1] == color0)
				toVisit.emplace(y, x - 1);
			if (y < h-1 && !visited[y + 1][x] && result[y + 1][x] == color0)
				toVisit.emplace(y + 1, x);
			if (x < w-1 && !visited[y][x + 1] && result[y][x + 1] == color0)
				toVisit.emplace(y, x + 1);
		}
		return result;
	}
};

void printImage(const vector<vector<int>>& img) {
	for (const auto& row : img) {
		copy(begin(row), end(row), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	cout << endl;
}

int main()
{
	vector<vector<int>> img = { { 1,1,1}, {1,1,0}, {1,0,1 } };
	printImage(Solution().floodFill(img, 1, 1, 2));
	cout << endl;

    return 0;
}

