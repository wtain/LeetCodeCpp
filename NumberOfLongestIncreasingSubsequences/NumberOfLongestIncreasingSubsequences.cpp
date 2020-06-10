
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*

https://leetcode.com/problems/number-of-longest-increasing-subsequence/

Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.

*/


// Simple DP
//class Solution {
//public:
//	int findNumberOfLIS(vector<int>& nums) 
//	{
//		if (nums.empty())
//			return 0;
//		vector<int> L(nums.size(), 1);
//		vector<int> LC(nums.size(), 1);
//
//		int result = 1;
//		int cnt = 1;
//		for (size_t i = 1; i < nums.size(); ++i)
//		{
//			int mx = 0;
//			int cnt1 = 1;
//			for (size_t j = 0; j < i; ++j)
//			{
//				if (nums[j] >= nums[i])
//					continue;
//				if (mx < L[j])
//				{
//					cnt1 = LC[j];
//					mx = L[j];
//				}
//				else if (mx == L[j])
//					cnt1 += LC[j];
//			}
//			L[i] = 1 + mx;
//			LC[i] = cnt1;
//			if (result < L[i])
//			{
//				cnt = cnt1;
//				result = L[i];
//			}
//			else if (result == L[i])
//				cnt += cnt1;
//		}
//		return cnt;
//	}
//};

// Segment Tree
class Solution {
public:

	struct Value
	{
		int Length;
		int Count;

		Value(int l, int c)
			: Length(l), Count(c) {}

		Value()
			: Length(0), Count(1) {}
	};

	struct Node
	{
		int rangeMin, rangeMax;
		Value value;
		Node *left, *right;

		Node(int vmin, int vmax)
			: rangeMin(vmin)
			, rangeMax(vmax)
			, left(nullptr)
			, right(nullptr) {}

		int getMid() const
		{
			return rangeMin + (rangeMax - rangeMin) / 2;
		}

		Node* getLeft()
		{
			if (!left)
				left = new Node(rangeMin, getMid());
			return left;
		}

		Node* getRight()
		{
			if (!right)
				right = new Node(getMid() + 1, rangeMax);
			return right;
		}
	};

	Value merge(Value v1, Value v2)
	{
		if (v1.Length == v2.Length)
		{
			if (!v1.Length)
				return Value();
			return Value(v1.Length, v1.Count + v2.Count);
		}
		return v1.Length > v2.Length ? v1 : v2;
	}

	Value query(Node* node, int num)
	{
		if (node->rangeMax <= num)
			return node->value;
		else if (node->rangeMin > num)
			return Value();
		else
			return merge(query(node->getLeft(), num), query(node->getRight(), num));
	}

	void insert(Node* node, int num, Value v)
	{
		if (node->rangeMax == node->rangeMin)
		{
			node->value = merge(v, node->value);
			return;
		}
		else if (num <= node->getMid())
			insert(node->getLeft(), num, v);
		else
			insert(node->getRight(), num, v);
		node->value = merge(node->getLeft()->value, node->getRight()->value);
	}

	int findNumberOfLIS(vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		auto p = minmax_element(begin(nums), end(nums));
		Node* root = new Node(*p.first, *p.second);
		for (auto num : nums)
		{
			auto v = query(root, num-1);
			insert(root, num, Value(v.Length+1, v.Count));
		}
		return root->value.Count;
	}
};

int main()
{
	vector<int> v1 = { 1,3,5,4,7 };
	vector<int> v2 = { 2,2,2,2,2 };
	vector<int> v3 = { 1, 2, 4, 3, 5, 4, 7, 2 };
	vector<int> v4;
	vector<int> v5 = { 2, 1 };
	
	cout << Solution().findNumberOfLIS(v1) << endl; // 2
	cout << Solution().findNumberOfLIS(v2) << endl; // 5
	cout << Solution().findNumberOfLIS(v3) << endl; // 3
	cout << Solution().findNumberOfLIS(v4) << endl; // 0
	cout << Solution().findNumberOfLIS(v5) << endl; // 2

    return 0;
}

