
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/intersection-of-two-arrays/

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.

*/

//class Solution {
//public:
//
//	set<int> getUnique(const vector<int>& nums) {
//		set<int> rv;
//		copy(begin(nums), end(nums), inserter(rv, end(rv)));
//		return rv;
//	}
//
//	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//		auto d1 = getUnique(nums1);
//		auto d2 = getUnique(nums2);
//		vector<int> rv;
//		set_intersection(begin(d1), end(d1), begin(d2), end(d2), back_inserter(rv));
//		return rv;
//	}
//};

class Solution {
public:

	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		
		unordered_set<int> unique;
		for (auto n1 : nums1)
			unique.insert(n1);

		vector<int> rv;
		rv.reserve(unique.size());
		for (auto n2 : nums2) {
			auto it = unique.find(n2);
			if (it != end(unique)) {
				rv.push_back(n2);
				unique.erase(it);
			}
		}

		return rv;
	}
};

int main()
{
	{
		auto r = Solution().intersection(vector<int>({ 1,2,2,1 }), vector<int>({ 2,2 }));
		copy(begin(r), end(r), ostream_iterator<int>(cout, " ")); // 2
		cout << endl;
	}

	{
		auto r = Solution().intersection(vector<int>({ 4,9,5 }), vector<int>({ 9,4,9,8,4 }));
		copy(begin(r), end(r), ostream_iterator<int>(cout, " ")); // 9 4
		cout << endl;
	}

    return 0;
}

