
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/next-permutation/

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 ? 1,3,2
3,2,1 ? 1,2,3
1,1,5 ? 1,5,1

*/

//#pragma message("!!!!!!!!!!!!!!!!!!!!!!!! Not solved problem, MEDIUM")

//Runtime: 16 ms, faster than 11.04% of C++ online submissions for Next Permutation.
//Memory Usage : 12.1 MB, less than 61.98% of C++ online submissions for Next Permutation.
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		const size_t n = nums.size();
		int invIdx = -1;
		for (int i = n - 1; i > 0; --i) {
			if (nums[i] > nums[i - 1]) {
				invIdx = i - 1;
				break;
			}
		}
		if (invIdx == -1) {
			sort(begin(nums), end(nums));
			return;
		}
		for (int i = n - 1; i > invIdx; --i) {
			if (nums[i] > nums[invIdx]) {
				swap(nums[i], nums[invIdx]);
				reverse(begin(nums) + invIdx + 1, begin(nums) + n);
				return;
			}
		}
	}
};

void print(const vector<int>& v) {
	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
}

void runTest(vector<int> p) {
	Solution().nextPermutation(p);
	print(p);
}

int main()
{
	runTest({ 1,2,3 }); // 1 3 2
	runTest({ 3,2,1 }); // 1 2 3
	runTest({ 1,1,5 }); // 1 5 1

    return 0;
}

