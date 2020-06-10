
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

/*
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.



Example 1:



Input: [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).
Example 2:



Input: [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report "[1,5,6]", the node value of 5 comes first since 5 is smaller than 6.


Note:

The tree will have between 1 and 1000 nodes.
Each node's value will be between 0 and 1000.

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Runtime: 4 ms, faster than 92.94% of C++ online submissions for Vertical Order Traversal of a Binary Tree.
//Memory Usage : 14.8 MB, less than 22.22% of C++ online submissions for Vertical Order Traversal of a Binary Tree.
class Solution {
public:

	void verticalTraversalImpl(TreeNode* root, map<int, map<int, set<int>>>& cache, int x, int y) {
		if (!root)
			return;
		cache[x][y].insert(root->val);
		verticalTraversalImpl(root->left, cache, x - 1, y + 1);
		verticalTraversalImpl(root->right, cache, x + 1, y + 1);
	}

	vector<vector<int>> verticalTraversal(TreeNode* root) {
		map<int, map<int, set<int>>> cache;
		verticalTraversalImpl(root, cache, 0, 0);

		vector<vector<int>> result;
		for (const auto& m : cache) {
			result.emplace_back();
			for (const auto& s : m.second) {
				for (const auto& v : s.second) {
					result.back().push_back(v);
				}
			}
		}

		return result;
	}
};

void printTraversal(const vector<vector<int>>& t) {
	for (const auto& p : t) {
		cout << "{ ";
		copy(begin(p), end(p), ostream_iterator<int>(cout, ","));
		cout << "} ";
	}
	cout << endl;
}

int main()
{
	{
		TreeNode* root = new TreeNode(3);
		root->left = new TreeNode(9);
		root->right = new TreeNode(20);
		root->right->left = new TreeNode(15);
		root->right->right = new TreeNode(7);
		auto r = Solution().verticalTraversal(root);
		printTraversal(r); // [[9],[3,15],[20],[7]]
	}
	{
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->left->left = new TreeNode(4);
		root->left->right = new TreeNode(5);
		root->right = new TreeNode(3);
		root->right->left = new TreeNode(6);
		root->right->right = new TreeNode(7);
		auto r = Solution().verticalTraversal(root);
		printTraversal(r); // [[4],[2],[1,5,6],[3],[7]]
	}

	{
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->right = new TreeNode(3);
		
		root->right->left = new TreeNode(4);
		root->left->right = new TreeNode(5);
		auto r = Solution().verticalTraversal(root);
		printTraversal(r); // [[2],[1,4,5],[3]]
	}

    return 0;
}

