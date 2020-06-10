
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_set>

using namespace std;

/*
https://leetcode.com/problems/increasing-subsequences/

Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2.



Example:

Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]


Note:

The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
*/

//Runtime: 132 ms, faster than 85.33% of C++ online submissions for Increasing Subsequences.
//Memory Usage : 19.5 MB, less than 60.00% of C++ online submissions for Increasing Subsequences.
//class Solution {
//public:
//
//	unsigned long long perfectHash(const vector<int>& solution) {
//		unsigned long long result = 0;
//		for (const int i : solution) {
//			result *= 201;
//			result += 101 + i;
//		}
//		return result;
//	}
//
//	void findSubsequencesImpl(const vector<int>& nums, vector<vector<int>>& results, vector<int>& solution, int startIndex, unordered_set<unsigned long long>& hashes) {
//		if (solution.size() >= 2) {
//			const auto hash = perfectHash(solution);
//			auto it = hashes.find(hash);
//			if (it == end(hashes)) {
//				hashes.emplace_hint(it, hash);
//				results.push_back(solution);
//			}
//		}
//
//		for (int i = startIndex; i < nums.size(); ++i) {
//			if (!solution.empty() && solution.back() > nums[i])
//				continue;
//			solution.push_back(nums[i]);
//			findSubsequencesImpl(nums, results, solution, i + 1, hashes);
//			solution.pop_back();
//		}
//	}
//
//	vector<vector<int>> findSubsequences(vector<int>& nums) {
//		vector<vector<int>> results;
//		vector<int> solution;
//		unordered_set<unsigned long long> hashes;
//		findSubsequencesImpl(nums, results, solution, 0, hashes);
//		return results;
//	}
//};

//Runtime: 152 ms, faster than 84.57% of C++ online submissions for Increasing Subsequences.
//Memory Usage : 19.4 MB, less than 60.00% of C++ online submissions for Increasing Subsequences.
//class Solution {
//public:
//
//	void findSubsequencesImpl(const vector<int>& nums, vector<vector<int>>& results, vector<int>& solution, int startIndex, unordered_set<unsigned long long>& hashes, unsigned long long hash) {
//		if (solution.size() >= 2) {
//			auto it = hashes.find(hash);
//			if (it == end(hashes)) {
//				hashes.emplace_hint(it, hash);
//				results.push_back(solution);
//			}
//		}
//
//		for (int i = startIndex; i < nums.size(); ++i) {
//			if (!solution.empty() && solution.back() > nums[i])
//				continue;
//			solution.push_back(nums[i]);
//			findSubsequencesImpl(nums, results, solution, i + 1, hashes, 201 * hash + (101 + nums[i]));
//			solution.pop_back();
//		}
//	}
//
//	vector<vector<int>> findSubsequences(vector<int>& nums) {
//		vector<vector<int>> results;
//		vector<int> solution;
//		unordered_set<unsigned long long> hashes;
//		findSubsequencesImpl(nums, results, solution, 0, hashes, 0);
//		return results;
//	}
//};

//Runtime: 56 ms, faster than 98.21% of C++ online submissions for Increasing Subsequences.
//Memory Usage : 19.5 MB, less than 60.00% of C++ online submissions for Increasing Subsequences.
class Solution {
	vector<int> solution;
	unordered_set<unsigned long long> hashes;
public:

	void findSubsequencesImpl(const vector<int>& nums, vector<vector<int>>& results, int startIndex, unsigned long long hash) {
		if (solution.size() >= 2) {
			auto it = hashes.find(hash);
			if (it == end(hashes)) {
				hashes.emplace_hint(it, hash);
				results.push_back(solution);
			}
		}

		for (int i = startIndex; i < nums.size(); ++i) {
			if (!solution.empty() && solution.back() > nums[i])
				continue;
			solution.push_back(nums[i]);
			findSubsequencesImpl(nums, results, i + 1, 201 * hash + (101 + nums[i]));
			solution.pop_back();
		}
	}

	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<vector<int>> results;
		
		findSubsequencesImpl(nums, results, 0, 0);
		return results;
	}
};

void printResult(const vector<vector<int>>& results) {
	for (const auto r : results) {
		cout << "[";
		copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
		cout << "] ";
	}
	cout << endl << endl;
}

int main()
{
	{
		printResult(Solution().findSubsequences(vector<int>{4, 6, 7, 7}));
		// [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
	}
	{
		printResult(Solution().findSubsequences(vector<int>{4, 3, 2, 1}));
		// []
	}
	{
		printResult(Solution().findSubsequences(vector<int>{-100, -99, -98, -97, -96, -96}));
		// [[-99,-96,-96],[-100,-99],[-98,-97,-96,-96],[-100,-98],[-100,-97],[-99,-98,-96,-96],[-100,-96],[-100,-97,-96],[-98,-96,-96],[-98,-96],[-98,-97],[-100,-99,-98,-97,-96,-96],[-99,-97,-96,-96],[-99,-98,-97,-96],[-100,-98,-96,-96],[-100,-98,-96],[-100,-98,-97],[-98,-97,-96],[-99,-97],[-99,-98],[-100,-99,-96,-96],[-99,-97,-96],[-100,-99,-97,-96,-96],[-99,-96],[-100,-99,-98,-96,-96],[-100,-99,-96],[-96,-96],[-100,-98,-97,-96,-96],[-100,-98,-97,-96],[-100,-99,-97],[-100,-99,-98],[-99,-98,-97],[-100,-99,-97,-96],[-100,-99,-98,-97,-96],[-100,-97,-96,-96],[-99,-98,-96],[-97,-96],[-100,-99,-98,-97],[-100,-99,-98,-96],[-97,-96,-96],[-100,-96,-96],[-99,-98,-97,-96,-96]]
		// [[-100,-99],[-100,-99,-98],[-100,-99,-98,-97],[-100,-99,-98,-97,-96],[-100,-99,-98,-97,-96,-96],[-100,-99,-98,-96],[-100,-99,-98,-96,-96],[-100,-99,-97],[-100,-99,-97,-96],[-100,-99,-97,-96,-96],[-100,-99,-96],[-100,-99,-96,-96],[-100,-98],[-100,-98,-97],[-100,-98,-97,-96],[-100,-98,-97,-96,-96],[-100,-98,-96],[-100,-98,-96,-96],[-100,-97],[-100,-97,-96],[-100,-97,-96,-96],[-100,-96],[-100,-96,-96]]
	}
	
	//cout << Solution().perfectHash(vector<int>{-99, -98}) << endl;
	//cout << Solution().perfectHash(vector<int>{-100, -99, -98}) << endl;


    return 0;
}

