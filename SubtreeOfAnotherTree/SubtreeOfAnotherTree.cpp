
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

	bool match(TreeNode* s, TreeNode* t)
	{
		if (!s && !t)
			return true;
		if (!s || !t)
			return false;
		if (s->val != t->val)
			return false;
		return match(s->left, t->left) &&
			match(s->right, t->right);
	}

	bool isSubtree(TreeNode* s, TreeNode* t) 
	{
		if (!t)
			return true;
		if (!s)
			return false;
		if (s->val == t->val)
		{
			if (match(s->left, t->left) &&
				match(s->right, t->right))
				return true;
		}
		return isSubtree(s->left, t) || isSubtree(s->right, t);
	}
};

int main()
{
	TreeNode* s1 = new TreeNode(3);
	s1->right = new TreeNode(5);
	s1->left = new TreeNode(4);
	s1->left->left = new TreeNode(1);
	s1->left->right = new TreeNode(2);

	TreeNode* t1 = new TreeNode(4);
	t1->left = new TreeNode(1);
	t1->right = new TreeNode(2);



	TreeNode* s2 = new TreeNode(3);
	s2->right = new TreeNode(5);
	s2->left = new TreeNode(4);
	s2->left->left = new TreeNode(1);
	s2->left->right = new TreeNode(2);
	s2->left->right->left = new TreeNode(0);

	TreeNode* t2 = new TreeNode(4);
	t2->left = new TreeNode(1);
	t2->right = new TreeNode(2);

	cout << boolalpha << Solution().isSubtree(s1, t1) << endl; // true
	cout << boolalpha << Solution().isSubtree(s2, t2) << endl; // false

    return 0;
}

