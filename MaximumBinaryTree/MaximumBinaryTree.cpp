#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

/*
https://leetcode.com/problems/maximum-binary-tree/

Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

   6
 /   \
3     5
 \    /
  2  0
   \
    1
Note:
The size of the given array will be in the range [1,1000].
*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:

	typedef vector<int>::const_iterator Iterator;

	TreeNode* constructImpl(Iterator i1, Iterator i2)
	{
		if (i1 >= i2)
			return NULL;
		auto itmax = max_element(i1, i2);
		TreeNode* root = new TreeNode(*itmax);
		root->left = constructImpl(i1, itmax);
		root->right = constructImpl(itmax+1, i2);
		return root;
	}

	TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
	{
		// naive
		return constructImpl(begin(nums), end(nums));
	}
};

class Helper
{
	int parseInt(const std::string& s, int& i, int ie)
	{
		int v = 0;
		while (i <= ie && isdigit(s[i]))
		{
			v *= 10;
			v += s[i] - '0';
			++i;
		}
		return v;
	}

	/*
	INT = D+
	TREE = INT|INT(TREE,TREE)|e
	*/
	TreeNode* constructTreeImpl(const std::string& s, int& i, int ie)
	{
		if (i > ie || !isdigit(s[i]))
			return NULL;
		int v = parseInt(s, i, ie);

		TreeNode* node = new TreeNode(v);

		if (i <= ie)
		{
			if (s[i] == '(')
			{
				++i;
				node->left = constructTreeImpl(s, i, ie);
				if (s[i] != ',')
					throw 1;
				++i;
				node->right = constructTreeImpl(s, i, ie);
				if (s[i] != ')')
					throw 1;
				++i;
			}
		}

		return node;
	}

public:

	TreeNode* constructTree(const std::string& s)
	{
		int i = 0;
		return constructTreeImpl(s, i, s.length() - 1);
	}

	void printInOrder(TreeNode* root)
	{
		if (!root)
			return;
		cout << root->val << ", ";
		printInOrder(root->left);
		printInOrder(root->right);
	}

	void printPostOrder(TreeNode* root)
	{
		if (!root)
			return;
		printPostOrder(root->left);
		printPostOrder(root->right);
		cout << root->val << ", ";
	}
};

int main()
{
	vector<int> arr = { 3,2,1,6,0,5 };
	auto root = Solution().constructMaximumBinaryTree(arr);
    return 0;
}

