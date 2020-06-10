
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// https://leetcode.com/problems/sort-colors/

/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/

class Solution {
public:
	void sortColors(vector<int>& nums) 
	{
		const int n = nums.size();
		int l = 0, r = n;
		for (int i = 0; i < r;)
		{
			if (nums[i] == 0 && i >= l)
				swap(nums[i++], nums[l++]);
			else if (nums[i] == 2)
				swap(nums[i], nums[--r]);
			else
				++i;
		}
	}
};

int main()
{
	//vector<int> v = { 2,0,2,1,1,0 };
	vector<int> v = { 0, 1, 0 };
	Solution().sortColors(v);

	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
	cout << endl;

    return 0;
}

