
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/largest-divisible-subset/
https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3359/

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/

/*
int gcd(int a, int b) {
if (b > a)
swap(a, b);
while (b) {
int anew = b;
b = a % b;
a = anew;
}
return a;
}

int lcm(int a, int b) {
return a * b / gcd(a, b);
}
*/

//Runtime: 44 ms, faster than 53.88% of C++ online submissions for Largest Divisible Subset.
//Memory Usage : 10.6 MB, less than 18.32% of C++ online submissions for Largest Divisible Subset.
//class Solution {
//public:
//
//	vector<int> largestDivisibleSubset(vector<int>& nums) {
//		vector<int> result;
//		if (nums.empty())
//			return result;
//		sort(begin(nums), end(nums));
//		const size_t N = nums.size();
//		vector<int> counts(N);
//		vector<vector<int>> sets(N);
//		for (int i = 0; i < N; ++i) {
//			int maxCnt = 1;
//			for (int j = i-1; j >= 0; --j) {
//				if (nums[i] % nums[j])
//					continue;
//				int newCnt = counts[j] + 1;
//				if (newCnt > maxCnt) {
//					maxCnt = newCnt;
//					sets[i] = sets[j];
//				}
//			}
//			sets[i].push_back(nums[i]);
//			counts[i] = maxCnt;
//			if (sets[i].size() > result.size())
//				result = sets[i];
//		}
//		return result;
//	}
//};

//Runtime: 40 ms, faster than 76.59% of C++ online submissions for Largest Divisible Subset.
//Memory Usage : 8.7 MB, less than 44.08% of C++ online submissions for Largest Divisible Subset.
class Solution {
public:

	vector<int> largestDivisibleSubset(vector<int>& nums) {
		if (nums.empty())
			return{};
		sort(begin(nums), end(nums));
		const size_t N = nums.size();
		
		vector<int> counts(N, 1);
		vector<int> indexes(N, -1);

		size_t maxIndex = 0;
		for (int i = 0; i < N; ++i) {
			int maxCnt = 1;
			for (int j = i - 1; j >= 0; --j) {
				if (nums[i] % nums[j])
					continue;
				int newCnt = counts[j] + 1;
				if (newCnt > maxCnt) {
					maxCnt = newCnt;
					indexes[i] = j;
				}
			}
			counts[i] = maxCnt;
			if (counts[i] > counts[maxIndex])
				maxIndex = i;
		}

		vector<int> result;
		result.reserve(counts[maxIndex]);
		int t = maxIndex;
		while (t >= 0) {
			result.push_back(nums[t]);
			t = indexes[t];
		}
		return result;
	}
};

void print(const vector<int>& v) {
	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	print(Solution().largestDivisibleSubset(vector<int>{4, 8, 10, 240})); // [4,8,240]

	print(Solution().largestDivisibleSubset(vector<int>{1, 2, 3})); // 1 2 (1 3)
	print(Solution().largestDivisibleSubset(vector<int>{1, 2, 4, 8})); // 1 2 4 8
	print(Solution().largestDivisibleSubset(vector<int>{})); // []
	print(Solution().largestDivisibleSubset(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10})); // 1 2 4 8

    return 0;
}

