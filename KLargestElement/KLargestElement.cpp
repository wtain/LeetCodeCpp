
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <ctime>

using namespace std;

// https://leetcode.com/problems/kth-largest-element-in-an-array/

/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ? k ? array's length.
*/

// Heap approach, N*log(k) time, K space, suboptimal
//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) 
//	{
//		if (k == 1)
//			return *max_element(begin(nums), end(nums));
//		vector<int> h;
//		const int n = nums.size();
//		for (int i = 0; i < k; ++i)
//		{
//			h.push_back(nums[i]);
//			push_heap(begin(h), end(h), greater<int>());
//		}
//		for (int i = k; i < n; ++i)
//		{
//			if (h[0] > nums[i])
//				continue;
//			pop_heap(begin(h), end(h), greater<int>());
//			h[k - 1] = nums[i];
//			push_heap(begin(h), end(h), greater<int>());
//		}
//		return h[0];
//	}
//};

class Solution {
public:

	Solution()
	{
		srand(static_cast<unsigned>(time(nullptr)));
	}

	int findKthLargest(vector<int>& nums, int k)
	{
		const int n = nums.size();

		return getKthSmallestElement(nums, n - k+1);
	}

	int getKthSmallestElement(vector<int>& nums, int k)
	{
		const int n = nums.size();

		for (int i = n-1; i >= 0; --i)
		{
			int j = rand() % (i + 1);
			swap(nums[i], nums[j]);
		}

		int l = 0, r = n - 1;
		--k;
		while (l < r)
		{
			int m = getMiddle(nums, l, r);

			if (k == m)
				break;
			else if (k < m)
				r = m - 1;
			else
				l = m + 1;
		}
		return nums[k];
	}

	int getMiddle(vector<int>& nums, int l, int r)
	{
		int i = l;

		for (int j = l + 1; j <= r; ++j)
		{
			if (nums[j] < nums[l])
				swap(nums[j], nums[++i]);
		}
		swap(nums[i], nums[l]);
		return i;
	}
};

int main()
{
	vector<int> v1 = { 3,2,1,5,6,4 };
	vector<int> v2 = { 3,2,3,1,2,4,5,5,6 };
	vector<int> v3 = { 1 };
	cout << Solution().findKthLargest(v1, 2) << endl; // 5
	cout << Solution().findKthLargest(v2, 4) << endl; // 4
	cout << Solution().findKthLargest(v3, 1) << endl; // 1
    return 0;
}

