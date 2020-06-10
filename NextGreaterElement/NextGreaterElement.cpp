
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <stack>

using namespace std;

/*
https://leetcode.com/problems/next-greater-element-i/

You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
For number 1 in the first array, the next greater number for it in the second array is 3.
For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
For number 2 in the first array, the next greater number for it in the second array is 3.
For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.

*/

// NAIVE, 97.29% 
//class Solution {
//public:
//	vector<int> getNextGreaters(const vector<int>& nums2) {
//		vector<int> result;
//		const int n = nums2.size();
//		result.resize(n, -1);
//		for (int i = 0; i < n; ++i) {
//			for (int j = i + 1; j < n; ++j) {
//				if (nums2[j] > nums2[i]) {
//					result[i] = nums2[j];
//					break;
//				}
//			}
//		}
//		return result;
//	}
//
//	unordered_map<int, int> buildIndex(const vector<int>& nums2) {
//		unordered_map<int, int> index;
//		for (int i = 0; i < nums2.size(); ++i)
//			index.emplace(make_pair(nums2[i], i));
//		return index;
//	}
//
//	vector<int> mapElements(const vector<int>& nums1, const vector<int>& nums2, const vector<int>& nextGreaters) {
//		const auto index = buildIndex(nums2);
//		vector<int> result;
//		result.resize(nums1.size());
//		for (int i = 0; i < nums1.size(); ++i)
//			result[i] = nextGreaters[index.find(nums1[i])->second];
//		return result;
//	}
//
//	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//		//int n = nums2.size();
//		//vector<int> rightmaxes;
//		//rightmaxes.resize(n);
//		//rightmaxes[n - 1] = nums2[n - 1];
//		//unordered_map<int, int> index;
//		//for (int i = n - 2; i >= 0; --i) {
//		//	rightmaxes[i] = max(rightmaxes[i + 1], nums2[i]);
//		//	index.emplace(make_pair(nums2[i], i));
//		//}
//		//vector<int>
//
//		const auto nextGreaters = getNextGreaters(nums2);
//		return mapElements(nums1, nums2, nextGreaters);
//	}
//};

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> greaters;
		stack<int> st;
		const int n = nums2.size();
		int i = 0;
		while (i < n) {
			if (!st.empty()) {
				while (!st.empty() && st.top() < nums2[i]) {
					greaters.emplace(make_pair(st.top(), nums2[i]));
					st.pop();
				}
			}
			st.push(nums2[i++]);
		}

		const int m = nums1.size();
		vector<int> result;
		result.resize(m, -1);
		for (int i = 0; i < m; ++i) {
			auto it = greaters.find(nums1[i]);
			if (it != end(greaters))
				result[i] = it->second;
		}
		return result;
	}
};

int main()
{
	{
		auto r = Solution().nextGreaterElement(vector<int>({ 4,1,2 }), vector<int>({ 1,3,4,2 }));
		copy(begin(r), end(r), ostream_iterator<int>(cout, " ")); // -1,3,-1
		cout << endl;
	}

	{
		auto r = Solution().nextGreaterElement(vector<int>({ 2,4 }), vector<int>({ 1,2,3,4 }));
		copy(begin(r), end(r), ostream_iterator<int>(cout, " ")); // 3,-1
		cout << endl;
	}

    return 0;
}

