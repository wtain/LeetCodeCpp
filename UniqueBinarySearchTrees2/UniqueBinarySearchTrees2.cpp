
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/unique-binary-search-trees-ii/

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
[1,null,3,2],
[3,2,null,1],
[3,1,null,null,2],
[2,1,3],
[1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3


Constraints:

0 <= n <= 8

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// WRONG!
//class Solution {
//public:
//
//	TreeNode* cloneTree(TreeNode* root) {
//		if (!root)
//			return nullptr;
//		TreeNode* n = new TreeNode(root->val);
//		n->left = cloneTree(root->left);
//		n->right = cloneTree(root->right);
//		return n;
//	}
//
//	void generateTreesImpl(vector<TreeNode*>& result, vector<bool>& used, TreeNode* root, TreeNode* parent, int n, int vmin, int vmax) {
//		if (!n) {
//			result.push_back(cloneTree(root));
//			return;
//		}
//		for (int i = 0; i < used.size(); ++i) {
//			const int v = i + 1;
//			if (used[i])
//				continue;
//			if (v < vmin || v > vmax)
//				continue;
//
//			used[i] = true;
//			TreeNode* node = new TreeNode(v);
//			if (parent) {
//				if (parent->val > v)
//					parent->left = node;
//				else
//					parent->right = node;
//			}
//			generateTreesImpl(result, used, root ? root : node, node, n - 1, vmin, v-1);
//			generateTreesImpl(result, used, root ? root : node, node, n - 1, v+1, vmax);
//			used[i] = false;
//		}
//		if (parent) {
//			/*parent->left = nullptr;
//			parent->right = nullptr;*/
//		}
//	}
//
//	vector<TreeNode*> generateTrees(int n) {
//
//		vector<bool> used(n);
//
//		vector<TreeNode*> result;
//
//		generateTreesImpl(result, used, nullptr, nullptr, n, 0, n+1);
//
//		return result;
//	}
//};

//Runtime: 44 ms, faster than 6.53% of C++ online submissions for Unique Binary Search Trees II.
//Memory Usage : 18.9 MB, less than 5.05% of C++ online submissions for Unique Binary Search Trees II.
//class Solution {
//public:
//
//	TreeNode* cloneTree(TreeNode* root) {
//		if (!root)
//			return nullptr;
//		TreeNode* n = new TreeNode(root->val);
//		n->left = cloneTree(root->left);
//		n->right = cloneTree(root->right);
//		return n;
//	}
//
//	vector<TreeNode*> generateTreesImpl(vector<bool>& used, int n, int vmin, int vmax) {
//		if (!n)
//			return{nullptr};
//		vector<TreeNode*> result;
//		for (int i = 0; i < used.size(); ++i) {
//			const int v = i + 1;
//			if (used[i])
//				continue;
//			if (v < vmin || v > vmax)
//				continue;
//
//			used[i] = true;
//			TreeNode* node = new TreeNode(v);
//
//			const auto rl = generateTreesImpl(used, n - 1, vmin, v - 1);
//			const auto rr = generateTreesImpl(used, n - 1, v + 1, vmax);
//			for (auto rli : rl) {
//				node->left = rli;
//				for (auto rri : rr) {
//					node->right = rri;
//					result.push_back(cloneTree(node));
//				}
//			}
//
//			used[i] = false;
//		}
//		if (result.empty())
//			return{ nullptr };
//		return result;
//	}
//
//	vector<TreeNode*> generateTrees(int n) {
//
//		if (!n)
//			return{};
//
//		vector<bool> used(n);
//
//		return generateTreesImpl(used, n, 0, n + 1);
//	}
//};

//Runtime: 44 ms, faster than 6.53% of C++ online submissions for Unique Binary Search Trees II.
//Memory Usage : 19 MB, less than 5.05% of C++ online submissions for Unique Binary Search Trees II.
//class Solution {
//
//	//vector<vector<vector<TreeNode*>>> memo;
//	vector<bool> used;
//public:
//
//	TreeNode* cloneTree(TreeNode* root) {
//		if (!root)
//			return nullptr;
//		TreeNode* n = new TreeNode(root->val);
//		n->left = cloneTree(root->left);
//		n->right = cloneTree(root->right);
//		return n;
//	}
//
//	vector<TreeNode*> generateTreesImpl(int n, int vmin, int vmax) {
//		if (!n)
//			return{ nullptr };
//		vector<TreeNode*> result;
//		for (int i = 0; i < used.size(); ++i) {
//			const int v = i + 1;
//			if (used[i])
//				continue;
//			if (v < vmin || v > vmax)
//				continue;
//
//			used[i] = true;
//			TreeNode* node = new TreeNode(v);
//
//			const auto rl = generateTreesImpl(n - 1, vmin, v - 1);
//			const auto rr = generateTreesImpl(n - 1, v + 1, vmax);
//			for (auto rli : rl) {
//				node->left = rli;
//				for (auto rri : rr) {
//					node->right = rri;
//					result.push_back(cloneTree(node));
//				}
//			}
//
//			used[i] = false;
//		}
//		if (result.empty())
//			return{ nullptr };
//		return result;
//	}
//
//	vector<TreeNode*> generateTrees(int n) {
//
//		if (!n)
//			return{};
//
//		used.resize(n);
//		
//		//memo.resize(n, vector<vector<TreeNode*>>(n));
//
//		return generateTreesImpl(n, 0, n + 1);
//	}
//};

//Runtime: 12 ms, faster than 90.72% of C++ online submissions for Unique Binary Search Trees II.
//Memory Usage : 13.3 MB, less than 82.05% of C++ online submissions for Unique Binary Search Trees II.
class Solution {

	vector<vector<vector<TreeNode*>>> memo;
	vector<bool> used;
public:

	TreeNode* cloneTree(TreeNode* root) {
		if (!root)
			return nullptr;
		TreeNode* n = new TreeNode(root->val);
		n->left = cloneTree(root->left);
		n->right = cloneTree(root->right);
		return n;
	}

	vector<TreeNode*> generateTreesImpl(int vmin, int vmax) {
		if (vmin > vmax)
			return{ nullptr };
		if (memo[vmin - 1][vmax - 1].empty()) {
			vector<TreeNode*> result;
			for (int i = 0; i < used.size(); ++i) {
				const int v = i + 1;
				if (used[i])
					continue;
				if (v < vmin || v > vmax)
					continue;

				used[i] = true;
				TreeNode* node = new TreeNode(v);

				const auto rl = generateTreesImpl(vmin, v - 1);
				const auto rr = generateTreesImpl(v + 1, vmax);
				for (auto rli : rl) {
					node->left = rli;
					for (auto rri : rr) {
						node->right = rri;
						result.push_back(cloneTree(node));
					}
				}

				used[i] = false;
			}
			if (result.empty())
				return{ nullptr };
			memo[vmin - 1][vmax - 1].swap(result);
		}
		
		return memo[vmin - 1][vmax - 1];
	}

	vector<TreeNode*> generateTrees(int n) {

		if (!n)
			return{};

		used.resize(n);

		memo.resize(n, vector<vector<TreeNode*>>(n));

		return generateTreesImpl(1, n);
	}
};

void printTree(TreeNode* t) {
	if (!t) {
		cout << "(null)" << endl;
		return;
	}

	vector<pair<TreeNode*, int>> nodes1;
	vector<pair<TreeNode*, int>> nodes2;
	nodes1.emplace_back(t, 0);
	while (!nodes1.empty()) {
		nodes2.clear();

		for (auto np : nodes1) {
			if (np.second == 1)
				cout << "/ ";
			else if (np.second == 2)
				cout << "\\ ";
			else
				cout << "*";
		}
		cout << endl;

		for (auto np : nodes1) {
			auto n = np.first;
			cout << n->val << " ";
			if (n->left)
				nodes2.emplace_back(n->left, 1);
			if (n->right)
				nodes2.emplace_back(n->right, 2);
		}
		cout << endl;
		nodes1.swap(nodes2);
	}
}

void printSolution(const vector<TreeNode*>& s) {
	for (auto pr : s) {
		printTree(pr);
		cout << endl;
	}
}

int main()
{
	{
		/*auto r = Solution().generateTrees(8);
		cout << r.size() << endl;
		printSolution(r);*/
	}

	auto r = Solution().generateTrees(0);
	cout << r.size() << endl;
	printSolution(r);

	{
		auto r = Solution().generateTrees(3);
		cout << r.size() << endl; // 5
		printSolution(r);
	}

    return 0;
}

