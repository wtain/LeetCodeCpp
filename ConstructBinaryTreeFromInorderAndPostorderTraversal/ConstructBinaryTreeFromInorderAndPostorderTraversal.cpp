
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}	
};

//Runtime: 56 ms, faster than 23.77% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
//Memory Usage : 24.5 MB, less than 20.62% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
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
		auto Bin1 = inN + 1;
		auto Bin2 = in2;

		int nA = distance(Ain1, Ain2);
		//int nB = distance(Bin1, Bin2);

		auto Apost1 = post1;
		auto Apost2 = post1 + nA;
		auto Bpost1 = Apost2;
		auto Bpost2 = post2 - 1;

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

void printTree(TreeNode* root)
{
	if (!root)
		return;
	cout << "( ";
	printTree(root->left);
	cout << root->val << " ";
	printTree(root->right);
	cout << " )";
}

int main()
{
	auto root = Solution().buildTree(vector<int>{9, 3, 15, 20, 7}, vector<int>{ 9, 15, 7, 20, 3});
	printTree(root);

    return 0;
}

