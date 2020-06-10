
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:

	TreeNode* first(TreeNode* root, stack<TreeNode*>& parents)
	{
		while (root->left)
		{
			parents.push(root);
			root = root->left;
		}
		return root;
	}

	TreeNode* rightParent(TreeNode* root, stack<TreeNode*>& parents)
	{
		TreeNode* current = root;
		while (!parents.empty())
		{
			TreeNode* parent = parents.top(); parents.pop();
			if (parent->left = current)
				return parent;
			current = parent;
		}
		return nullptr;
	}

	vector<int> inorderTraversal(TreeNode* root) 
	{
		if (!root)
			return{};
		vector<int> result;
		stack<TreeNode*> parents;
		TreeNode* current = first(root, parents);
		while (current)
		{
			result.push_back(current->val);
			if (current->right)
			{
				current = first(current->right, parents);
			}
			else
			{
				if (!parents.empty())
				{
					current = rightParent(current, parents);
				}
				else
					current = nullptr;
			}
		}

		return result;
	}
};

void AddNode(TreeNode* root, int v)
{
	if (root->val > v)
	{
		if (root->left)
			AddNode(root->left, v);
		else
			root->left = new TreeNode(v);
	}
	else
	{
		if (root->right)
			AddNode(root->right, v);
		else
			root->right = new TreeNode(v);
	}
}

int main()
{
	TreeNode* root = new TreeNode(8);
	AddNode(root, 4);
	AddNode(root, 12);

	AddNode(root, 2);
	AddNode(root, 6);
	AddNode(root, 10);
	AddNode(root, 14);

	AddNode(root, 1);
	AddNode(root, 3);
	AddNode(root, 5);
	AddNode(root, 7);
	AddNode(root, 9);
	AddNode(root, 11);
	AddNode(root, 13);
	AddNode(root, 15);

	const auto result = Solution().inorderTraversal(root);
	copy(begin(result), end(result), ostream_iterator<int>(cout, " "));
	cout << endl;

    return 0;
}

