
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Intersection of Two Arrays II.
//Memory Usage : 10 MB, less than 8.93% of C++ online submissions for Intersection of Two Arrays II.
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(begin(nums1), end(nums1));
		sort(begin(nums2), end(nums2));

		auto it1 = begin(nums1), e1 = end(nums1);
		auto it2 = begin(nums2), e2 = end(nums2);

		vector<int> result;
		while (it1 != e1 && it2 != e2) {
			if (*it1 == *it2) {
				result.emplace_back(*it1);
				++it1; ++it2;
			}
			else if (*it1 < *it2) {
				++it1;
			}
			else {
				++it2;
			}
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
	print(Solution().intersect(vector<int>{1, 2, 2, 1}, vector<int>{2, 2})); // 2 2
	print(Solution().intersect(vector<int>{4,9,5}, vector<int>{9,4,9,8,4})); // 4, 9

    return 0;
}

