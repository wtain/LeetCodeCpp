
#include <iostream>
#include <vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution 
{
public:
	
	void pathSumImpl(TreeNode* root, int sum, vector<int>& path, int& result)
	{
		if (!root)
			return;
		int partSum = path.empty() ? 0 : path.back();
		partSum += root->val;
		for (const auto ps : path)
		{
			int pps = partSum - ps;
			if (pps == sum)
				++result;
		}
		path.push_back(partSum);
		if (partSum == sum)
			++result;
		if (root->left)
			pathSumImpl(root->left, sum, path, result);
		if (root->right)
			pathSumImpl(root->right, sum, path, result);
		path.pop_back();
	}

	int pathSum(TreeNode* root, int sum) 
	{
		int result = 0;
		vector<int> path;
		pathSumImpl(root, sum, path, result);
		return result;
	}
};

int main()
{
	TreeNode* n10 = new TreeNode(10);
	n10->right = new TreeNode(-3);
	n10->right->right = new TreeNode(11);
	n10->left = new TreeNode(5);
	n10->left->right = new TreeNode(2);
	n10->left->right->right = new TreeNode(1);
	n10->left->left = new TreeNode(3);
	n10->left->left->left = new TreeNode(3);
	n10->left->left->right = new TreeNode(-2);

	cout << Solution().pathSum(n10, 8) << endl;

    return 0;
}

