// BSTIterator.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class BSTIterator {
	stack<TreeNode*> parents;
	TreeNode *current;
	bool hasValue;

	TreeNode * moveFirst(TreeNode * node)
	{
		if (!node)
		{
			hasValue = false;
			return nullptr;
		}
		while (node->left)
		{
			parents.push(node);
			node = node->left;
		}
		hasValue = !!node;
		return node;
	}

	TreeNode * rightParent(TreeNode * node)
	{
		while (!parents.empty())
		{
			TreeNode* parent = parents.top(); parents.pop();
			if (node == parent->left)
				return parent;
			node = parent;
		}
		hasValue = false;
		return nullptr;
	}

	void moveNext()
	{
		if (current->right)
		{
			parents.push(current);
			current = moveFirst(current->right);
		}
		else
			current = rightParent(current);
	}

public:
	BSTIterator(TreeNode *root) : current(root)
	{
		current = moveFirst(current);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() 
	{
		return hasValue;
	}

	/** @return the next smallest number */
	int next() 
	{
		int v = current->val;
		moveNext();
		return v;
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

	//BSTIterator i = BSTIterator(root);
	//BSTIterator i = BSTIterator(nullptr);
	BSTIterator i = BSTIterator(new TreeNode(1));
	while (i.hasNext()) cout << i.next() << " ";
	cout << endl;

    return 0;
}

