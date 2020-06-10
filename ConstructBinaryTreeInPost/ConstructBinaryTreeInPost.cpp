
#include <iostream>
#include <vector>
#include <algorithm>

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

	typedef vector<int>::const_iterator It;

	TreeNode* buildTreeImpl(It in1, It in2, It post1, It post2)
	{
		if (in1 == in2 || post1 == post2)
			return nullptr;

		int v = *(post2 - 1);

		TreeNode* node = new TreeNode(v);

		auto inN = find(in1, in2, v);

		auto Ain1 = in1;
		auto Ain2 = inN;
		auto Bin1 = inN+1;
		auto Bin2 = in2;

		int nA = distance(Ain1, Ain2);
		//int nB = distance(Bin1, Bin2);

		auto Apost1 = post1;
		auto Apost2 = post1 + nA;
		auto Bpost1 = Apost2;
		auto Bpost2 = post2-1;

		/*auto Bpost2 = post2 - 1;
		auto Bpost1 = find(post1, post2, *Bin1);

		auto Apost1 = post1;
		auto Apost2 = Bpost1;*/

		node->left = buildTreeImpl(Ain1, Ain2, Apost1, Apost2);
		node->right = buildTreeImpl(Bin1, Bin2, Bpost1, Bpost2);

		return node;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
	{
		return buildTreeImpl(begin(inorder), end(inorder), begin(postorder), end(postorder));
	}
};

void printTreeImpl(const vector<TreeNode*>& level, vector<TreeNode*>& nextLevel)
{
	nextLevel.clear();
	for (auto& n : level)
	{
		if (n->left)
			nextLevel.push_back(n->left);
		if (n->right)
			nextLevel.push_back(n->right);
		cout << n->val << " ";
	}
	cout << endl;
}

void printTree(TreeNode* root)
{
	if (!root)
		return;
	vector<TreeNode*> level1 = { root }, level2;
	bool turn = true;
	while (!level1.empty() || !level2.empty())
	{
		vector<TreeNode*>& current = turn ? level1 : level2;
		vector<TreeNode*>& next = turn ? level2 : level1;
		printTreeImpl(current, next);
		turn = !turn;
	}
	cout << endl;
}

int main()
{
	//vector<int> inorder = { 9,3,15,20,7 }, postorder = { 9,15,7,20,3 };
	vector<int> inorder = { 1,2,3,4}, postorder = { 1,4,3,2 };
	auto t = Solution().buildTree(inorder, postorder);
	printTree(t);

    return 0;
}

