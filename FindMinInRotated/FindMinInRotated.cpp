
#include <vector>
#include <iostream>

using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?

*/

/*
class Solution {
public:
int findMin(vector<int>& nums) {
auto b = begin(nums), e = end(nums);
while (distance(b, e) > 1)
{
size_t n = distance(b, e);
auto m = b + (n >> 1);
if (*b > *m)
e = m;
else
b = m;
}
++b;
if (b == end(nums))
b = begin(nums);
return *b;
}
};
*/

//class Solution {
//public:
//	int findMin(vector<int>& nums) {
//		if (nums.size() == 1)
//			return nums[0];
//		if (nums[0] < nums[nums.size() - 1])
//			return nums[0];
//		auto b = begin(nums), e = end(nums);
//		while (distance(b, e) > 2)
//		{
//			size_t n = distance(b, e);
//			auto m = b + (n >> 1);
//			if (*b > *m)
//				e = m + 1;
//			else //if (*b < *m)
//				b = m;
//			//else
//
//		}
//		int v = *b;
//		int i = 0;
//		do
//		{
//			++b; ++i;
//			if (b == end(nums))
//				b = begin(nums);
//		} while (*b == v && i < nums.size());
//
//		if (v < *b)
//			return v;
//		
//		return *b;
//	}
//};

class Solution {
public:
	int findMin(vector<int>& nums) {
		auto b = begin(nums), e = end(nums)-1;
		while (distance(b, e) > 0)
		{
			size_t n = distance(b, e);
			auto m = b + (n >> 1);
			if (*e > *m)
				e = m;
			else if (*e < *m)
				b = m + 1;
			else
				--e;
		}
		return *b;
	}
};

int main()
{
	//vector<int> v = { 4, 5, 6, 7, 0, 1, 2 };
	//vector<int> v = { 1 };
	//vector<int> v = { 1, 2 };
	//vector<int> v = { 1, 1, 1 };
	//vector<int> v = { 4, 5, 6, 7, 7, 0, 1, 2 };
	//vector<int> v = { 4, 5, 6, 7, 7, 0, 1, 1, 2 };
	//vector<int> v = { 3, 3, 1, 3 };
	//vector<int> v = { 3, 1, 3, 3 };
	//vector<int> v = { 1, 1, 3, 1 };	
	//vector<int> v = { 1, 3, 1, 1 };
	//vector<int> v = { 1, 1, 1, 1 };
	//vector<int> v = { 1, 2, 0, 1, 1, 1 };
	//vector<int> v = { 1,1,2,0,0,1 };
	
	
	
	cout << Solution().findMin(vector<int>({ 1, 1, 2, 0, 0, 1 })) << endl; // 0
	cout << Solution().findMin(vector<int>({ 1, 2, 0, 1, 1, 1 })) << endl; // 0
	cout << Solution().findMin(vector<int>({ 1, 1, 1, 1 })) << endl; // 1
	cout << Solution().findMin(vector<int>({ 1, 3, 1, 1 })) << endl; // 1
	cout << Solution().findMin(vector<int>({ 1, 1, 3, 1 })) << endl; // 1
	cout << Solution().findMin(vector<int>({ 3, 1, 3, 3 })) << endl; // 1
	cout << Solution().findMin(vector<int>({ 3, 3, 1, 3 })) << endl; // 1
	cout << Solution().findMin(vector<int>({ 4, 5, 6, 7, 7, 0, 1, 1, 2 })) << endl; // 0
	cout << Solution().findMin(vector<int>({ 4, 5, 6, 7, 7, 0, 1, 2 })) << endl; // 0
	cout << Solution().findMin(vector<int>({ 1, 1, 1 })) << endl; // 1
	cout << Solution().findMin(vector<int>({ 1, 2 })) << endl; // 1
	cout << Solution().findMin(vector<int>({ 1 })) << endl; // 1
	cout << Solution().findMin(vector<int>({ 4, 5, 6, 7, 0, 1, 2 })) << endl; // 0
	cout << Solution().findMin(vector<int>({ 1, 3, 5 })) << endl; // 1
	cout << Solution().findMin(vector<int>({ 3, 1, 3 })) << endl; // 1
	cout << Solution().findMin(vector<int>({ 2, 2, 2, 3, 1 })) << endl; // 1
	

	//cout << Solution().findMin(vector<int>({ 1, 2, 0, 1, 1, 1 })) << endl; // 0

    return 0;
}

