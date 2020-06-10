
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/circular-array-loop/

You are given a circular array nums of positive and negative integers. If a number k at an index is positive, then move forward k steps. Conversely, if it's negative (-k), move backward k steps. Since the array is circular, you may assume that the last element's next element is the first element, and the first element's previous element is the last element.

Determine if there is a loop (or a cycle) in nums. A cycle must start and end at the same index and the cycle's length > 1. Furthermore, movements in a cycle must all follow a single direction. In other words, a cycle must not consist of both forward and backward movements.



Example 1:

Input: [2,-1,1,2,2]
Output: true
Explanation: There is a cycle, from index 0 -> 2 -> 3 -> 0. The cycle's length is 3.
Example 2:

Input: [-1,2]
Output: false
Explanation: The movement from index 1 -> 1 -> 1 ... is not a cycle, because the cycle's length is 1. By definition the cycle's length must be greater than 1.
Example 3:

Input: [-2,1,-1,-2,-2]
Output: false
Explanation: The movement from index 1 -> 2 -> 1 -> ... is not a cycle, because movement from index 1 -> 2 is a forward movement, but movement from index 2 -> 1 is a backward movement. All movements in a cycle must follow a single direction.


Note:

-1000 ? nums[i] ? 1000
nums[i] ? 0
1 ? nums.length ? 5000


Follow up:

Could you solve it in O(n) time complexity and O(1) extra space complexity?

*/

//class Solution {
//public:
//
//	int advance(const vector<int>& nums, int index) {
//		return (index + nums.size() + nums[index]) % nums.size();
//	}
//
//	int advance(const vector<int>& nums, int index, int steps) {
//		for (int i = 0; i < steps; ++i)
//			index = advance(nums, index);
//		return index;
//	}
//
//	int findLoop(const vector<int>& nums, int index) {
//		int j1 = index, j2 = index;
//		do {
//			j1 = advance(nums, j1);
//			j2 = advance(nums, j2, 2);
//		} while (j1 != j2);
//		j1 = 0;
//
//		while (j1 != j2) {
//			j1 = advance(nums, j1);
//			j2 = advance(nums, j2);
//		}
//
//		return j1;
//	}
//
//	//bool circularArrayLoopAtIndex(const vector<int>& nums, int index) {
//	//	int j = findLoop(nums, index);
//
//	//	int j0 = j, cnt = 1;
//	//	j = advance(nums, j);
//	//	while (j != j0) {
//	//		if (nums[j] * nums[j0] < 0)
//	//			return false;
//	//		j = advance(nums, j);
//	//		++cnt;
//	//	}
//
//	//	return cnt > 1;
//	//}
//
//	//bool circularArrayLoop(vector<int>& nums) {
//	//	const size_t n = nums.size();
//	//	for (int i = 0; i < n; ++i)
//	//		if (circularArrayLoopAtIndex(nums, i))
//	//			return true;
//	//	return false;
//	//}
//
//	bool circularArrayLoop(vector<int>& nums) {
//		int j = findLoop(nums, 0);
//
//		int j0 = j, cnt = 1;
//		j = advance(nums, j);
//		while (j != j0) {
//			if (nums[j] * nums[j0] < 0)
//				return false;
//			j = advance(nums, j);
//			++cnt;
//		}
//
//		return cnt > 1;
//	}
//};

//Runtime: 128 ms, faster than 9.87% of C++ online submissions for Circular Array Loop.
//Memory Usage : 7.7 MB, less than 100.00% of C++ online submissions for Circular Array Loop.
class Solution {
public:

	int advance(const vector<int>& nums, int index) {
		return (index + nums.size() + nums[index]) % nums.size();
	}

	int advance(const vector<int>& nums, int index, int steps) {
		for (int i = 0; i < steps; ++i)
			index = advance(nums, index);
		return index;
	}

	bool isLoop(const vector<int>& nums, int index) {
		int j1 = index, j2 = index;
		const size_t n = nums.size();
		size_t steps = 0;
		do {
			j1 = advance(nums, j1); ++steps;
			j2 = advance(nums, j2, 2);
			if (steps > n)
				return false;
		} while (j1 != j2);
		
		return true;
	}

	bool circularArrayLoopAtIndex(vector<int>& nums, int j) {
		if (!isLoop(nums, j))
			return false;

		int j0 = j, cnt = 1;
		j = advance(nums, j);
		const size_t n = nums.size();
		while (j != j0) {
			if (nums[j] * nums[j0] < 0)
				return false;
			j = advance(nums, j);
			++cnt;
			if (cnt > n)
				return false;
		}

		return cnt > 1;
	}

	bool circularArrayLoop(vector<int>& nums) {
		const size_t n = nums.size();
		for (int i = 0; i < n; ++i)
			if (circularArrayLoopAtIndex(nums, i))
				return true;
		return false;
	}
};

int main()
{
	cout << boolalpha << Solution().circularArrayLoop(vector<int>{2, -1, 1, 2, 2}) << endl; // true
	cout << boolalpha << Solution().circularArrayLoop(vector<int>{-1, 2}) << endl; // false
	cout << boolalpha << Solution().circularArrayLoop(vector<int>{-2, 1, -1, -2, -2}) << endl; // false
	cout << boolalpha << Solution().circularArrayLoop(vector<int>{ 1, -1, 1, -1, 5}) << endl; // false
	cout << boolalpha << Solution().circularArrayLoop(vector<int>{ 1, -1, 1, -1, 1, 5}) << endl; // true
	cout << boolalpha << Solution().circularArrayLoop(vector<int>{ -1, -2, -3, -4, -5}) << endl; // false

    return 0;
}

