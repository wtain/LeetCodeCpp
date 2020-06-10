
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int findSecondMinimumValue(TreeNode* root) 
	{
		if (!root)
			return -1;
		/*if (!root->left)
			return -1;
		if (root->left->val == root->val &&
			root->right->val != root->val)
			return root->right->val;
		if (root->left->val != root->val &&
			root->right->val == root->val)
			return root->left->val;*/

		int m1 = -1, m2 = -1;
		findSecondMinimumValueImpl(root, m1, m2);
		return m2;
	}

	void findSecondMinimumValueImpl(TreeNode* root, int& m1, int& m2)
	{
		if (m1 == -1)
			m1 = root->val;
		else if (root->val < m1)
		{
			m2 = m1;
			m1 = root->val;
		}
		else if (root->val == m1)
		{

		}
		else if (root->val < m2 || m2 == -1)
		{
			m2 = root->val;
		}
		if (root->left)
			findSecondMinimumValueImpl(root->left, m1, m2);
		if (root->right)
			findSecondMinimumValueImpl(root->right, m1, m2);
	}
};

int main()
{
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(7);
	cout << Solution().findSecondMinimumValue(root) << endl;
    return 0;
}

