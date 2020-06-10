#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>
#include <iomanip>

using namespace std;

/*

https://leetcode.com/problems/construct-quad-tree/

We want to use quad trees to store an N x N boolean grid. Each cell in the grid can only be true or false. The root node represents the whole grid. For each node, it will be subdivided into four children nodes until the values in the region it represents are all the same.

Each node has another two boolean attributes : isLeaf and val. isLeaf is true if and only if the node is a leaf node. The val attribute for a leaf node contains the value of the region it represents.

Your task is to use a quad tree to represent a given grid. The following example may help you understand the problem better:

Given the 8 x 8 grid below, we want to construct the corresponding quad tree:



It can be divided according to the definition above:





The corresponding quad tree should be as following, where each node is represented as a (isLeaf, val) pair.

For the non-leaf nodes, val can be arbitrary, so it is represented as *.



Note:

N is less than 1000 and guaranteened to be a power of 2.
If you want to know more about the quad tree, you can refer to its wiki.

*/

/*
// Definition for a QuadTree node.
class Node {
public:
bool val;
bool isLeaf;
Node* topLeft;
Node* topRight;
Node* bottomLeft;
Node* bottomRight;

Node() {}

Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
val = _val;
isLeaf = _isLeaf;
topLeft = _topLeft;
topRight = _topRight;
bottomLeft = _bottomLeft;
bottomRight = _bottomRight;
}
};
*/

class Node {
public:
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;

	Node() {}

	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};

class Solution {
public:

	bool allSame(const vector<vector<int>>& grid, int i1, int j1, int i2, int j2)
	{
		int v = grid[i1][j1];
		for (int i = i1; i < i2; ++i)
		{
			for (int j = j1; j < j2; ++j)
			{
				if (v != grid[i][j])
					return false;
			}
		}
		return true;
	}

	Node* constructImpl(const vector<vector<int>>& grid, int i1, int j1, int i2, int j2)
	{
		if (allSame(grid, i1, j1, i2, j2))
			return new Node(!!grid[i1][j1], true, nullptr, nullptr, nullptr, nullptr);
		int n = i2 - i1;
		int m = j2 - j1;
		int n2 = n >> 1;
		int m2 = m >> 1;
		Node* n11 = constructImpl(grid, i1, j1, i1 + n2, j1 + m2);
		Node* n12 = constructImpl(grid, i1, j1 + m2, i1 + n2, j2);
		Node* n21 = constructImpl(grid, i1 + n2, j1, i2, j1 + m2);
		Node* n22 = constructImpl(grid, i1 + n2, j1 + m2, i2, j2);
		return new Node(false, false, n11, n12, n21, n22);
	}

	Node* construct(vector<vector<int>>& grid) {
		return constructImpl(grid, 0, 0, grid.size(), grid.size());
	}
};

int main()
{
	vector<vector<int>> grid = 
	{
		{ 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 0 },
	};

	Node* root = Solution().construct(grid);

    return 0;
}

