
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <iomanip>

using namespace std;

/*

https://leetcode.com/problems/continuous-subarray-sum/

Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.

Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
Note:
The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.

*/

//class Solution {
//public:
//
//	void inc(map<int, int>& rems, int r)
//	{
//		auto it = rems.find(r);
//		if (it == end(rems))
//			rems.insert(it, make_pair(r, 1));
//		else
//			++it->second;
//	}
//
//	void dec(map<int, int>& rems, int r)
//	{
//		auto it = rems.find(r);
//		if (!--it->second)
//			rems.erase(it);
//	}
//
//	bool checkSubarraySum(vector<int>& nums, int k) 
//	{
//		const size_t n = nums.size();
//		if (n < 2)
//			return false;
//		if (!k)
//		{
//			auto it = begin(nums);
//			while (it != end(nums))
//			{
//				it = find(it, end(nums), 0);
//				if (it == end(nums))
//					return false;
//				++it;
//				if (it == end(nums))
//					return false;
//				if (!*it)
//					return true;
//				++it;
//			}
//			return !*it;
//		}
//		if (k < 0)
//			k = -k;
//		vector<int> ps(n);
//		map<int, int> rems;
//		ps[0] = nums[0] % k;
//		//inc(rems, ps[0]);
//		for (int i = 1; i < n; ++i)
//		{
//			ps[i] = (ps[i - 1] + nums[i]) % k;
//			inc(rems, ps[i]);
//		}
//		for (int i = 0; i < n; ++i)
//		{
//			if (i < n-1)
//				dec(rems, ps[i+1]);
//			if (!ps[i] && i > 0)
//				return true;
//			auto it = rems.find(ps[i]);
//			if (it != rems.end())
//				return true;
//		}
//		return false;
//	}
//};

class Solution {
public:

	void inc(unordered_map<int, int>& m, int s)
	{
		auto it = m.find(s);
		if (end(m) == it)
			m.emplace_hint(it, make_pair(s, 1));
		else
			++it->second;
	}

	void dec(unordered_map<int, int>& m, int s)
	{
		auto it = m.find(s);
		if (!--it->second)
			m.erase(it);
	}

	bool checkSubarraySumZero(const vector<int>& nums)
	{
		auto it = begin(nums);
		while (it != end(nums))
		{
			it = find(it, end(nums), 0);
			if (it == end(nums))
				return false;
			++it;
			if (it == end(nums))
				return false;
			if (!*it)
				return true;
			++it;
		}
		return false;
	}

	bool checkSubarraySumImpl(vector<int>& nums, int k)
	{
		const int n = nums.size();
		vector<int> ps(n);
		unordered_map<int, int> rems;
		ps[0] = nums[0] % k;
		for (int i = 1; i < n; ++i)
		{
			ps[i] = (ps[i - 1] + nums[i]) % k;
			inc(rems, ps[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			if (i < n - 1)
				dec(rems, ps[i + 1]);
			if (i > 0 && !ps[i])
				return true;
			auto it = rems.find(ps[i]);
			if (it != end(rems))
				return true;
		}
		return false;
	}

	bool checkSubarraySum(vector<int>& nums, int k)
	{
		if (nums.size() < 2)
			return false;
		if (!k)
			return checkSubarraySumZero(nums);
		if (k < 0)
			k = -k;
		return checkSubarraySumImpl(nums, k);
	}
};

int main()
{
	vector<int> test1 = { 23, 2, 4, 6, 7 };
	vector<int> test2 = { 23, 2, 6, 4, 7 };
	vector<int> test3 = { 0, 0 };
	vector<int> test4 = { 0, 1, 0 };
	vector<int> test5 = { 0, 1, 0, 0 };
	vector<int> test6 = { 0 };
	vector<int> test7 = { 1, 1 };
	vector<int> test8 = { 1, 2, 3 };
	vector<int> test9 = { 5, 2, 4 };
	
	/*
	cout << boolalpha << Solution().checkSubarraySum(test1, 6) << endl; // true
	cout << boolalpha << Solution().checkSubarraySum(test2, 6) << endl; // true
	cout << boolalpha << Solution().checkSubarraySum(test2, 0) << endl; // false
	cout << boolalpha << Solution().checkSubarraySum(test2, -6) << endl; // true
	cout << boolalpha << Solution().checkSubarraySum(test3, 0) << endl; // true
	cout << boolalpha << Solution().checkSubarraySum(test4, 0) << endl; // false
	cout << boolalpha << Solution().checkSubarraySum(test5, 0) << endl; // true
	cout << boolalpha << Solution().checkSubarraySum(test3, -1) << endl; // true
	cout << boolalpha << Solution().checkSubarraySum(test6, -1) << endl; // false
	cout << boolalpha << Solution().checkSubarraySum(test7, 2) << endl; // true
	cout << boolalpha << Solution().checkSubarraySum(test8, 5) << endl; // true
	cout << boolalpha << Solution().checkSubarraySum(test8, 4) << endl; // false
	cout << boolalpha << Solution().checkSubarraySum(test9, 4) << endl; // false
	cout << boolalpha << Solution().checkSubarraySum(test9, 5) << endl; // false
	cout << boolalpha << Solution().checkSubarraySum(test4, -1) << endl; // true
	*/
	cout << boolalpha << Solution().checkSubarraySum(test8, 4) << endl; // false

    return 0;
}

