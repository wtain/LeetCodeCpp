
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
https://leetcode.com/problems/wiggle-sort-ii/

Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:

Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].
Example 2:

Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].
Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

//class Solution {
//public:
//	void wiggleSort(vector<int>& nums) 
//	{
//		const int n = nums.size();
//		if (n == 2)
//		{
//			int a1 = nums[0];
//			int a2 = nums[1];
//			nums[0] = min(a1, a2);
//			nums[1] = max(a1, a2);
//			return;
//		}
//		for (int i = 1; i < n-1; ++i)
//		{
//			int a1 = nums[i - 1];
//			int a2 = nums[i];
//			int a3 = nums[i + 1];
//			if (i % 2)
//			{
//				if (a1 > a2)
//					swap(a1, a2);
//				if (a2 > a3)
//					swap(a2, a3);
//				if (a1 > a2)
//					swap(a1, a2);
//			}
//			else
//			{
//				if (a1 < a2)
//					swap(a1, a2);
//				if (a2 < a3)
//					swap(a2, a3);
//				if (a1 < a2)
//					swap(a1, a2);
//			}
//			nums[i - 1] = a1;
//			nums[i] = a3;
//			nums[i + 1] = a2;
//		}
//		/*for (int i = 1; i < n; ++i)
//		{
//			int a1 = nums[i - 1];
//			int a2 = nums[i];
//			if (i % 2)
//			{
//				if (a1 > a2)
//					swap(a1, a2);
//			}
//			else
//			{
//				if (a1 < a2)
//					swap(a1, a2);
//			}
//			nums[i - 1] = a1;
//			nums[i] = a2;
//		}*/
//	}
//};

//class Solution {
//public:
//	void wiggleSort(vector<int>& nums)
//	{
//		const int n = nums.size();
//		if (!n)
//			return;
//		int pre = nums[0];
//		bool inc = true;
//		for (int i = 1; i < n; ++i)
//		{
//			if (inc && pre <= nums[i] ||
//				!inc && pre >= nums[i])
//			{
//				nums[i - 1] = pre;
//				pre = nums[i];
//			}
//			else
//				nums[i - 1] = nums[i];
//			inc = !inc;
//		}
//		nums[n - 1] = pre;
//	}
//};

class Solution {
public:

	Solution()
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	void wiggleSort(vector<int>& nums)
	{
		const int n = nums.size();
		if (!n)
			return;
		int m = (n + 1) >> 1;
		int median = getKthSmallest(nums, m);

		for (int i = 0, j = 0, k = n - 1; j <= k;)
		{
			if (nums[A(j, n)] > median)
				swap(nums[A(i++, n)], nums[A(j++, n)]);
			else if (nums[A(j, n)] < median)
				swap(nums[A(k--, n)], nums[A(j, n)]);
			else
				++j;
		}
	}

	int A(int i, int n)
	{
		return (2 * i + 1) % (n | 1);
	}

	int getKthSmallest(vector<int>& nums, int k)
	{
		const int n = nums.size();
		for (int i = n - 1; i >= 0; --i)
		{
			int j = std::rand() % (i + 1);
			swap(nums[i], nums[j]);
		}
		int l = 0, r = n - 1;
		--k;
		while (l < r)
		{
			int m = getMiddle(nums, l, r);
			if (m < k)
				l = m + 1;
			else if (m > k)
				r = m - 1;
			else
				break;
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
	vector<int> v1 = { 1, 5, 1, 1, 6, 4 };
	vector<int> v2 = { 1, 3, 2, 2, 3, 1 };
	vector<int> v3 = { 2, 1 };
	vector<int> v4 = { 1, 2, 2, 1, 2, 1, 1, 1, 1, 2, 2, 2 };
	vector<int> v5 = { 4,5,5,6 };

	Solution().wiggleSort(v1);
	copy(begin(v1), end(v1), ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	Solution().wiggleSort(v2);
	copy(begin(v2), end(v2), ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	Solution().wiggleSort(v3);
	copy(begin(v3), end(v3), ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	Solution().wiggleSort(v4);
	copy(begin(v4), end(v4), ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	Solution().wiggleSort(v5);
	copy(begin(v5), end(v5), ostream_iterator<int>(cout, " "));
	cout << endl << endl;

    return 0;
}

