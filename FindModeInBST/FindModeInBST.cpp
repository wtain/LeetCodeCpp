
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

/*

https://leetcode.com/problems/find-mode-in-binary-search-tree/

Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.


For example:
Given BST [1,null,2,2],

1
 \
  2
 /
2


return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

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

	// trivial
	/*void findModeImpl(TreeNode* root, unordered_map<int, int>& freqs)
	{
		if (!root)
			return;
		freqs[root->val] = freqs[root->val] + 1;
		findModeImpl(root->left, freqs);
		findModeImpl(root->right, freqs);
	}

	vector<int> findMode(TreeNode* root) {
		vector<int> result;
		unordered_map<int, int> freqs;
		findModeImpl(root, freqs);
		int mx = 0;
		for (const auto& f : freqs)
		{
			if (f.second > mx)
				mx = f.second;
		}
		for (const auto& f : freqs)
		{
			if (f.second == mx)
				result.push_back(f.first);
		}
		return result;
	}*/

	// WRONG! doesn't check values in internal nodes
	// Not used information about BST properties
	// Traverse?
	/*void findModeImpl(TreeNode* root, vector<int>& result, int& mx)
	{
		if (!root)
			return;
		if (!root->left && !root->right)
		{
			result.push_back(root->val);
			mx = 1;
			return;
		}
		vector<int> r1, r2; 
		int mx1 = 0, mx2 = 0;
		findModeImpl(root->left, r1, mx1);
		findModeImpl(root->right, r2, mx2);
		if (mx1 > mx2)
		{
			result = r1;
			mx = mx1;
		}
		else if (mx1 < mx2)
		{
			result = r2;
			mx = mx2;
		}
		else
		{
			copy(begin(r1), end(r1), back_inserter(result));
			copy(begin(r2), end(r2), back_inserter(result));
			mx = mx1;
		}
	}

	vector<int> findMode(TreeNode* root) {
		vector<int> result;
		int mx = 0;
		findModeImpl(root, result, mx);
		return result;
	}*/

	void findModeImpl(TreeNode* root, vector<int>& result, int& current, int& currLen, int& maxLen)
	{
		if (!root)
			return;
		findModeImpl(root->left, result, current, currLen, maxLen);
		if (!currLen)
		{
			maxLen = currLen = 1;
			current = root->val;
			result.push_back(current);
		}
		else if(root->val == current)
		{
			++currLen;
			if (currLen == maxLen)
				result.push_back(current);
			else if (currLen > maxLen)
			{
				maxLen = currLen;
				result.clear();
				result.push_back(current);
			}
		}
		else
		{
			currLen = 1;
			current = root->val;
			if (currLen == maxLen)
				result.push_back(current);
		}
		findModeImpl(root->right, result, current, currLen, maxLen);
	}

	// Traverse with iterator
	// count current group length
	// once same as longest - add to results
	// once became longer than max - clear results, re-add current value to modes
	vector<int> findMode(TreeNode* root) {
		vector<int> result;
		int current = 0, currLen = 0, maxLen = 0;
		findModeImpl(root, result, current, currLen, maxLen);
		return result;
	}
};

int main()
{
	TreeNode* n1 = new TreeNode(1);
	n1->right = new TreeNode(2);
	n1->right->left = new TreeNode(2);

	auto v = Solution().findMode(n1);

	copy(begin(v), end(v), ostream_iterator<int>(cout, " ")); // 2
	cout << endl;

    return 0;
}

