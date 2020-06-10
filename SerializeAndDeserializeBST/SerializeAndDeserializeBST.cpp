
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

/*
https://leetcode.com/problems/serialize-and-deserialize-bst/

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {

public:

	void serializeImpl(ostringstream& stream, TreeNode* root) {
		if (root) {
			stream << root->val;
			if (root->left || root->right) {
				stream << "(";
				serializeImpl(stream, root->left);
				stream << ",";
				serializeImpl(stream, root->right);
				stream << ")";
			}
		}
	}

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		ostringstream stream;
		serializeImpl(stream, root);
		return stream.str();
	}

	int deserializeImpl(const string& data, int index, TreeNode*& root) {
		if (index >= data.length() || !isdigit(data[index]))
			return index;
		auto i = data.find_first_of("(,)", index);
		if (i == index)
			return index;
		int val = stoi(data.substr(index, i - index));
		root = new TreeNode(val);
		if (i == string::npos || data[i] == ',' || data[i] == ')')
			return i;
			//return i == string::npos ? string::npos : i + 1;
		int i2 = deserializeImpl(data, i+1, root->left);
		return deserializeImpl(data, i2+1, root->right) + 1;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		TreeNode* root = nullptr;
		deserializeImpl(data, 0, root);
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

bool matchTrees(TreeNode* t1, TreeNode* t2) {
	if (!t1 && !t2)
		return true;
	if (!t1 || !t2)
		return false;
	if (t1->val != t2->val)
		return false;
	return matchTrees(t1->left, t2->left) &&
		matchTrees(t1->right, t2->right);
}

void runTest(const string& name, TreeNode* root) {
	const auto s = Codec().serialize(root);
	cout << s << endl;
	auto root2 = Codec().deserialize(s);
	const auto s2 = Codec().serialize(root2);
	cout << s2 << endl;
	cout << "Test \"" << name << "\": " << boolalpha << matchTrees(root, root2) << endl;
}

int main()
{
	{
		TreeNode* root = new TreeNode(2);
		root->left = new TreeNode(1);
		root->right = new TreeNode(3);

		runTest("small", root);
	}

	{
		TreeNode* root = new TreeNode(6);
		root->left = new TreeNode(4);
		root->right = new TreeNode(8);

		root->left->left = new TreeNode(2);
		root->left->right = new TreeNode(5);

		root->left->left->left = new TreeNode(1);

		root->right->left = new TreeNode(7);

		runTest("big", root);
	}
	{
		runTest("empty", nullptr);
	}
	{
		runTest("single node", new TreeNode(1));
	}
    return 0;
}

