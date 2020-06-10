
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	int findFrequentTreeSumImpl(TreeNode* root, unordered_map<int, int>& counts, int& maxCnt)
	{
		if (!root)
			return 0;

		int sumL = findFrequentTreeSumImpl(root->left, counts, maxCnt);
		int sumR = findFrequentTreeSumImpl(root->right, counts, maxCnt);

		int sum = root->val + sumL + sumR;
		maxCnt = max(maxCnt, ++counts[sum]);
		return sum;
	}

	vector<int> findFrequentTreeSum(TreeNode* root) 
	{
		unordered_map<int, int> counts; 
		int maxCnt = 0;
		findFrequentTreeSumImpl(root, counts, maxCnt);
		vector<int> result;
		for (const auto& p : counts)
		{
			if (p.second == maxCnt)
				result.push_back(p.first);
		}
		return result;
	}
};

int main()
{
	TreeNode* tree1 = new TreeNode(5);
	tree1->left = new TreeNode(2);
	tree1->right = new TreeNode(-3);

	TreeNode* tree2 = new TreeNode(5);
	tree2->left = new TreeNode(2);
	tree2->right = new TreeNode(-5);

	auto v1 = Solution().findFrequentTreeSum(tree1);
	auto v2 = Solution().findFrequentTreeSum(tree2);

	copy(begin(v1), end(v1), ostream_iterator<int>(cout, " ")); // 2, -3, 4
	cout << endl;

	copy(begin(v2), end(v2), ostream_iterator<int>(cout, " ")); // 2
	cout << endl;

    return 0;
}

