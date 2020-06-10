
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
https://leetcode.com/problems/construct-string-from-binary-tree/

You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:
Input: Binary tree: [1,2,3,4]
1
/   \
2     3
/
4

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())",
but you need to omit all the unnecessary empty parenthesis pairs.
And it will be "1(2(4))(3)".
Example 2:
Input: Binary tree: [1,2,3,null,4]
1
/   \
2     3
\
4

Output: "1(2()(4))(3)"

Explanation: Almost the same as the first example,
except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.

*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//class Solution {
//public:
//	string tree2str(TreeNode* t) {
//		if (!t)
//			return "";
//
//		string result;
//
//		string s1 = tree2str(t->left);
//		string s2 = tree2str(t->right);
//
//		result += to_string(t->val);
//
//		/*
//		if (s1.empty() && !s2.empty())
//			result += "()" + s2;
//		else if (!s1.empty() && s2.empty())
//			result += s1;
//		else if (!s1.empty() && !s2.empty())
//			result += "(" + s1 + ")" + s2;
//		*/
//
//		if (!s1.empty() && !s2.empty())
//			result += "(" + s1 + ")(" + s2 + ")";
//		else if (!s1.empty())
//			result += "(" + s1 + ")";
//		else if (!s2.empty())
//			result += "()(" + s2 + ")";
//
//		return result;
//	}
//};

//class Solution {
//public:
//	string tree2str(TreeNode* t) {
//		if (!t)
//			return "";
//
//		string result;
//
//		string s1 = tree2str(t->left);
//		string s2 = tree2str(t->right);
//
//		result += to_string(t->val);
//
//		if (!s1.empty() || !s2.empty())
//			result += "(" + s1 + ")";
//
//		if (!s2.empty())
//			result += "(" + s2 + ")";
//
//		return result;
//	}
//};

class Solution {
public:

	void tree2strImpl(TreeNode* t, ostream& stream)
	{
		if (!t)
			return;

		bool s1ne = !!t->left;
		bool s2ne = !!t->right;

		stream << t->val;

		if (s1ne || s2ne) {
			stream << "(";
			tree2strImpl(t->left, stream);
			stream << ")";
		}

		if (s2ne) {
			stream << "(";
			tree2strImpl(t->right, stream);
			stream << ")";
		}
	}

	string tree2str(TreeNode* t) {
		ostringstream stream;

		tree2strImpl(t, stream);

		return stream.str();
	}
};


int main()
{
	{
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->right = new TreeNode(3);
		root->left->left = new TreeNode(4);
		cout << Solution().tree2str(root) << endl; // "1(2(4))(3)"
	}

	{
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->right = new TreeNode(3);
		root->left->right = new TreeNode(4);
		cout << Solution().tree2str(root) << endl; // "1(2()(4))(3)"
	}
    return 0;
}

