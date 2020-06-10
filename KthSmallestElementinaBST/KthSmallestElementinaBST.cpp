
#include <iostream>
#include <stack>

using namespace std;

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
	int kthSmallest(TreeNode* root, int k) 
	{
		stack<TreeNode*> parents;
		auto pNode = minNode(root, parents);
		for (int i = 1; i < k; ++i)
		{
			pNode = nextNode(pNode, parents);
		}

		return pNode->val;
	}

	TreeNode* nextNode(TreeNode* pNode, stack<TreeNode*>& parents)
	{
		if (pNode->right)
		{
			parents.push(pNode);
			return minNode(pNode->right, parents);
		}
		
		while (!parents.empty())
		{
			auto pParent = parents.top();
			parents.pop();
			if (pParent->left == pNode)
				return pParent;
			pNode = pParent;
		}

		return NULL;
	}

	TreeNode* minNode(TreeNode* pNode, stack<TreeNode*>& parents)
	{
		while (pNode)
		{
			parents.push(pNode);
			pNode = pNode->left;
		}
		return parents.top();
	}
};

int main()
{
	/*
	TreeNode* n5 = new TreeNode(5);
	n5->right = new TreeNode(6);
	n5->left = new TreeNode(3);
	n5->left->right = new TreeNode(4);
	n5->left->left = new TreeNode(2);
	n5->left->left->left = new TreeNode(1);

	cout << Solution().kthSmallest(n5, 3) << endl;
	*/

	TreeNode* n4 = new TreeNode(4);
	n4->right = new TreeNode(5);
	n4->left = new TreeNode(2);
	n4->left->right = new TreeNode(3);
	n4->left->left = new TreeNode(1);

	cout << Solution().kthSmallest(n4, 4) << endl;

    return 0;
}

