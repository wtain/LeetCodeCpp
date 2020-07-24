
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <sstream>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/largest-number/
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/

/// WRONG
//class Solution {
//public:
//	string largestNumber(vector<int>& nums) {
//		vector<string> strs;
//		strs.reserve(nums.size());
//		for (const auto n : nums) {
//			auto si = to_string(n);
//			reverse(begin(si), end(si));
//			strs.push_back(si);
//		}
//		sort(begin(strs), end(strs), greater<string>());
//		if (strs[0] == "0")
//			return "0";
//		ostringstream ss;
//		for (auto& si : strs) {
//			reverse(begin(si), end(si));
//			ss << si;
//		}
//		return ss.str();
//	}
//};

//Runtime: 16 ms, faster than 78.35% of C++ online submissions for Largest Number.
//Memory Usage : 11.5 MB, less than 50.93% of C++ online submissions for Largest Number.
//class Solution {
//public:
//
//	struct compare {
//
//		bool operator() (const string& s1, const string& s2) const {
//			return s1 + s2 > s2 + s1;
//		}
//
//	};
//
//	string largestNumber(vector<int>& nums) {
//		vector<string> strs;
//		strs.reserve(nums.size());
//		for (const auto n : nums)
//			strs.push_back(to_string(n));
//		sort(begin(strs), end(strs), compare());
//		if (strs[0] == "0")
//			return "0";
//		ostringstream ss;
//		for (auto& si : strs)
//			ss << si;
//		return ss.str();
//	}
//};

//class Solution {
//public:
//
//	struct compare {
//
//		bool operator() (const string& s1, const string& s2) const {
//			return s1 + s2 > s2 + s1;
//		}
//
//	};
//
//	string largestNumber(vector<int>& nums) {
//		vector<string> strs;
//		strs.reserve(nums.size());
//		for (const auto n : nums)
//			strs.push_back(to_string(n));
//		sort(begin(strs), end(strs), compare());
//		if (strs[0] == "0")
//			return "0";
//		ostringstream ss;
//		return accumulate(begin(strs), end(strs), ref(ss), [&](auto& ss, const auto& si) { ss.get() << si; }).get().str();
//	}
//};

//Runtime: 16 ms, faster than 78.35% of C++ online submissions for Largest Number.
//Memory Usage : 12.8 MB, less than 9.73% of C++ online submissions for Largest Number.
class Solution {
public:

	struct compare {

		bool operator() (const string& s1, const string& s2) const {
			return s1 + s2 > s2 + s1;
		}

	};

	string largestNumber(vector<int>& nums) {
		vector<string> strs;
		strs.reserve(nums.size());
		transform(begin(nums), end(nums), back_inserter(strs), [](auto n) { return to_string(n); });
		sort(begin(strs), end(strs), compare());
		if (strs[0] == "0")
			return "0";
		return accumulate(begin(strs), end(strs), string(), [](auto& ss, const auto& si) { return ss + si; });
	}
};

int main()
{
	cout << Solution().largestNumber(vector<int>{10, 2}) << endl; // 210
	cout << Solution().largestNumber(vector<int>{3, 30, 34, 5, 9}) << endl; // 9534330
	cout << Solution().largestNumber(vector<int>{0, 0, 0}) << endl; // 0
	cout << Solution().largestNumber(vector<int>{1, 12, 21}) << endl; // 21121

    return 0;
}

