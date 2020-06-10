
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/maximum-average-subarray-i/

Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:

Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75


Note:

1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].
*/

//class Solution {
//public:
//	double findMaxAverage(vector<int>& nums, int k) {
//		int sum = 0;
//		int i1 = 0;
//		int i2 = 0;
//		for (; i2 < k; ++i2)
//			sum += nums[i2];
//		double maxAve = static_cast<double>(sum) / k;
//		for (; i2 < nums.size(); ++i2, ++i1) {
//			sum += nums[i2];
//			sum -= nums[i1];
//			double ave = static_cast<double>(sum) / k;
//			maxAve = max(maxAve, ave);
//		}
//		return maxAve;
//	}
//};

class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int sum = 0;
		int i1 = 0;
		int i2 = 0;
		for (; i2 < k; ++i2)
			sum += nums[i2];
		int maxSum = sum;
		for (; i2 < nums.size(); ++i2, ++i1) {
			sum += nums[i2];
			sum -= nums[i1];
			maxSum = max(maxSum, sum);
		}
		return static_cast<double>(maxSum) / k;
	}
};

int main()
{
	cout << setprecision(6) << Solution().findMaxAverage(vector<int>({ 1,12,-5,-6,50,3 }), 4) << endl; // 12.75
    return 0;
}

