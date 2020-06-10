
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stack>
#include <queue>

using namespace std;

/*
https://leetcode.com/problems/find-k-closest-elements/

Given a sorted array arr, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]


Constraints:

1 <= k <= arr.length
1 <= arr.length <= 10^4
Absolute value of elements in the array and x will not exceed 104

*/

//Runtime: 84 ms, faster than 94.41% of C++ online submissions for Find K Closest Elements.
//Memory Usage : 31.6 MB, less than 16.67% of C++ online submissions for Find K Closest Elements.
//class Solution {
//public:
//	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//		auto it = lower_bound(begin(arr), end(arr), x);
//		deque<int> res;
//		vector<int>::const_iterator f = it;
//		vector<int>::const_reverse_iterator b = vector<int>::const_reverse_iterator(it);
//		for (int i = 0; i < k; ++i) {
//			int d1 = b != rend(arr) ? (x - *b) : numeric_limits<int>::max();
//			int d2 = f != end(arr) ? (*f - x) : numeric_limits<int>::max();
//			if (d1 <= d2)
//				res.push_front(*b++);
//			else
//				res.push_back(*f++);
//		}
//
//		vector<int> result;
//		result.reserve(res.size());
//		copy(begin(res), end(res), back_inserter(result));
//		return result;
//	}
//};

//Runtime: 80 ms, faster than 97.19% of C++ online submissions for Find K Closest Elements.
//Memory Usage : 31.1 MB, less than 16.67% of C++ online submissions for Find K Closest Elements.
class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		auto f = lower_bound(begin(arr), end(arr), x);
		
		int i1 = distance(begin(arr), f) - 1;
		int i2 = i1 + 1;
		
		for (int i = 0; i < k; ++i) {
			int d1 = i1 >= 0 ? (x - arr[i1]) : numeric_limits<int>::max();
			int d2 = i2 < arr.size() ? (arr[i2] - x) : numeric_limits<int>::max();
			if (d1 <= d2)
				i1--;
			else
				i2++;
		}

		vector<int> result;
		result.reserve(k);
		copy(begin(arr) + (i1 + 1), begin(arr) + i2, back_inserter(result));
		return result;
	}
};

void print(const vector<int>& v) {
	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	print(Solution().findClosestElements(vector<int>{1, 2, 3, 4, 5}, 4, 3)); // 1 2 3 4
	print(Solution().findClosestElements(vector<int>{1, 2, 3, 4, 5}, 4, -1)); // 1 2 3 4
	print(Solution().findClosestElements(vector<int>{0, 0, 1, 2, 3, 3, 4, 7, 7, 8}, 3, 5)); // 3, 3, 4

    return 0;
}

