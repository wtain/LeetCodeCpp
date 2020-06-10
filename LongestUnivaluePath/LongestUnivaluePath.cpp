
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

//#define null -10005000
//
//class Helper
//{
//public:
//	static TreeNode* constructTree(const vector<int>& nodes)
//	{
//		TreeNode* root = new TreeNode(nodes[0]);
//		vector<TreeNode*> level1;
//		vector<TreeNode*> level2;
//		level1.push_back(root);
//		int j = 0;
//		for (int i = 1; i < nodes.size(); ++i, ++j)
//		{
//			int n = j / 2;
//			if (!level1[n])
//				continue;
//			if (n == level1.size())
//			{
//
//			}
//			TreeNode* newNode = (nodes[i] != null) ? (new TreeNode(nodes[i])) : nullptr;
//			if (!(j % 2))
//				level1[n]->left = newNode;
//			else
//				level1[n]->right = newNode;
//		}
//		return root;
//	}
//};

class Solution {
public:

	void longestUnivaluePathImpl(TreeNode* root, int& maxPath1, int& maxPath)
	{
		if (!root)
			return;
		int maxPath2 = 0;
		int maxL1 = 0, maxR1 = 0;
		longestUnivaluePathImpl(root->left, maxL1, maxPath);
		longestUnivaluePathImpl(root->right, maxR1, maxPath);
		if (root->left && root->right && root->left->val == root->val && root->right->val == root->val)
		{
			maxPath1 = max(maxL1, maxR1) + 1;
			maxPath2 = maxL1 + maxR1 + 2;
		}
		else if (root->left && root->left->val == root->val)
		{
			maxPath1 = maxL1 + 1;
		}
		else if (root->right && root->right->val == root->val)
			maxPath1 = maxR1 + 1;
		
		maxPath = max(maxPath, maxPath1);
		maxPath = max(maxPath, maxPath2);
	}

	int longestUnivaluePath(TreeNode* root) 
	{
		int maxPath = 0, max1 = 0;
		longestUnivaluePathImpl(root, max1, maxPath);
		return maxPath;
	}
};


int main()
{
	TreeNode* tree1 = new TreeNode(5);
	tree1->right = new TreeNode(5);
	tree1->right->right = new TreeNode(5);
	tree1->left = new TreeNode(4);
	tree1->left->left = new TreeNode(1);
	tree1->left->right = new TreeNode(1);

	TreeNode* tree2 = new TreeNode(1);
	tree2->right = new TreeNode(5);
	tree2->right->right = new TreeNode(5);
	tree2->left = new TreeNode(4);
	tree2->left->left = new TreeNode(4);
	tree2->left->right = new TreeNode(4);

	cout << Solution().longestUnivaluePath(tree1) << endl; // 2
	cout << Solution().longestUnivaluePath(tree2) << endl; // 2

	// [-6,8,-4,8,-5,-1,null,-9,9,8,8,null,null,-5,6,null,null,null,-4,null,4,null,null,8,8,null,null,null,5,null,null,null,null,null,-9]

    return 0;
}

