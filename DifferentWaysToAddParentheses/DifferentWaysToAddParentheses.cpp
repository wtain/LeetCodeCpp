
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/different-ways-to-add-parentheses/

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1:

Input: "2-1-1"
Output: [0, 2]
Explanation:
((2-1)-1) = 0
(2-(1-1)) = 2
Example 2:

Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation:
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

*/

//Runtime: 28 ms, faster than 5.57% of C++ online submissions for Different Ways to Add Parentheses.
//Memory Usage : 11 MB, less than 49.53% of C++ online submissions for Different Ways to Add Parentheses.
//class Solution {
//public:
//
//	vector<int> diffWaysToComputeImpl(const string& input, const size_t l, const size_t r) {
//		if (r == l)
//			return{};
//
//		vector<int> result;
//
//		size_t start = l;
//
//		while (start < r) {
//
//			auto p = input.find_first_of("+-*", start); // r - l
//			if (p == string::npos)
//				p = r;
//			if (p == r)
//				break;
//
//			const auto left = diffWaysToComputeImpl(input, l, p);
//			const auto right = diffWaysToComputeImpl(input, p + 1, r);
//
//			result.reserve(result.size() + left.size() * right.size());
//			for (auto li : left) {
//				for (auto ri : right) {
//					if (input[p] == '+')
//						result.push_back(li + ri);
//					else if (input[p] == '-')
//						result.push_back(li - ri);
//					else if (input[p] == '*')
//						result.push_back(li * ri);
//				}
//			}
//
//			start = p + 1;
//		}
//
//		if (result.empty())
//			result.emplace_back(stoi(input.substr(l, r - l)));
//
//		return result;
//	}
//
//	vector<int> diffWaysToCompute(string input) {
//		return diffWaysToComputeImpl(input, 0, input.length());
//	}
//};

//Runtime: 12 ms, faster than 22.74% of C++ online submissions for Different Ways to Add Parentheses.
//Memory Usage : 7.2 MB, less than 94.19% of C++ online submissions for Different Ways to Add Parentheses.
class Solution {

	vector<vector<vector<int>>> cache;

public:

	vector<int> diffWaysToComputeImpl(const string& input, const size_t l, const size_t r) {
		if (r == l)
			return{};

		if (!cache[l][r - 1].empty())
			return cache[l][r - 1];

		vector<int>& result = cache[l][r - 1];

		size_t start = l;

		while (start < r) {

			auto p = input.find_first_of("+-*", start); // r - l
			if (p == string::npos)
				p = r;
			if (p == r)
				break;

			const auto left = diffWaysToComputeImpl(input, l, p);
			const auto right = diffWaysToComputeImpl(input, p + 1, r);

			result.reserve(result.size() + left.size() * right.size());
			for (auto li : left) {
				for (auto ri : right) {
					if (input[p] == '+')
						result.push_back(li + ri);
					else if (input[p] == '-')
						result.push_back(li - ri);
					else if (input[p] == '*')
						result.push_back(li * ri);
				}
			}

			start = p + 1;
		}

		if (result.empty())
			result.emplace_back(stoi(input.substr(l, r - l)));

		return result;
	}

	vector<int> diffWaysToCompute(string input) {
		const auto n = input.length();
		cache.resize(n, vector<vector<int>>(n));
		return diffWaysToComputeImpl(input, 0, n);
	}
};

void print(const vector<int>& r) {
	copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	print(Solution().diffWaysToCompute("2-1-1")); // [0, 2]
	print(Solution().diffWaysToCompute("2*3-4*5")); // [-34, -14, -10, -10, 10]

    return 0;
}

