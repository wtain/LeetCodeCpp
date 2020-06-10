
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/average-of-levels-in-binary-tree/

Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
3
/ \
9  20
/  \
15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

	void averageOfLevelsImpl(TreeNode* root, vector<double>& result, vector<int>& counts, int level) {
		if (!root)
			return;
		if (result.size() == level) {
			result.emplace_back(root->val);
			counts.emplace_back(1);
		}
		else {
			result[level] += root->val;
			++counts[level];
		}
		averageOfLevelsImpl(root->left, result, counts, level + 1);
		averageOfLevelsImpl(root->right, result, counts, level + 1);
	}

	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> result;
		vector<int> counts;

		averageOfLevelsImpl(root, result, counts, 0);

		for (int i = 0; i < result.size(); ++i)
			result[i] /= counts[i];

		return result;
	}
};

int main()
{
	{
		TreeNode* root = new TreeNode(3);
		root->left = new TreeNode(9);
		root->right = new TreeNode(20);
		root->right->left = new TreeNode(15);
		root->right->right = new TreeNode(7);

		auto r = Solution().averageOfLevels(root);
		cout << setprecision(8);
		copy(begin(r), end(r), ostream_iterator<double>(cout, " "));

		cout << endl; // 3, 14.5, 11
	}

    return 0;
}

