
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [1,1],[1,1]
Explanation: The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [1,3],[2,3]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]

*/

//auto i1 = begin(nums1), i2 = begin(nums2), e1 = end(nums1), e2 = end(nums2);
//
//while (i1 != e1 && i2 != e2 && result.size() < k) {
//	/*auto& less = *i1 <= *i2 ? i1 : i2;
//	auto& less_e = *i1 <= *i2 ? e1 : e2;
//	auto& greater = *i1 <= *i2 ? i2 : i1;
//	auto& greater_e = *i1 <= *i2 ? e2 : e1;*/
//}

//Runtime: 16 ms, faster than 88.74% of C++ online submissions for Find K Pairs with Smallest Sums.
//Memory Usage : 9.1 MB, less than 100.00% of C++ online submissions for Find K Pairs with Smallest Sums.
class Solution {
public:

	typedef vector<int>::const_iterator Iterator;
	typedef pair<Iterator, Iterator> Pair;

	struct Compare {

		bool operator() (Pair i1, Pair i2) const {
			return *i1.first + *i1.second > *i2.first + *i2.second;
		}
	};

	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<vector<int>> result;

		if (nums1.empty())
			return{};

		result.reserve(k);

		priority_queue<Pair, vector<Pair>, Compare> iterators;
		Iterator i1 = begin(nums1);

		for (Iterator i2 = begin(nums2); i2 != end(nums2); ++i2)
			iterators.push(Pair(i1, i2));

		while (result.size() < k && !iterators.empty()) {
			auto p = iterators.top(); iterators.pop();
			result.push_back(vector<int>{*p.first, *p.second});
			if (++p.first != end(nums1))
				iterators.push(p);
		}

		return result;
	}
};

void printSolution(const vector<vector<int>>& pairs) {
	for (const auto& p : pairs)
		cout << "[" << p[0] << "," << p[1] << "] ";
	cout << endl;
}

int main()
{
	printSolution(Solution().kSmallestPairs(vector<int>{1, 7, 11}, vector<int>{2, 4, 6}, 3)); // [[1,2],[1,4],[1,6]] 
	printSolution(Solution().kSmallestPairs(vector<int>{1, 1, 2}, vector<int>{1, 2, 3}, 2)); // [1,1],[1,1]
	printSolution(Solution().kSmallestPairs(vector<int>{1, 2}, vector<int>{3}, 3)); // [1,3],[2,3]

	printSolution(Solution().kSmallestPairs(vector<int>{}, vector<int>{3, 5, 7, 9}, 1)); // []

    return 0;
}

