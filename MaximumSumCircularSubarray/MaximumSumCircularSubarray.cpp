
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3330/

Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)



Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
Example 4:

Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
Example 5:

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1


Note:

-30000 <= A[i] <= 30000
1 <= A.length <= 30000
*/

//class Solution {
//public:
//	int maxSubarraySumCircular(vector<int>& A) {
//		const size_t n = A.size();
//		int sum = A[0];
//		int maxSum = sum;
//		size_t firstI = 0;
//		for (size_t i1 = 1; i1 < 2 * n; ++i1) {
//			size_t i = i1 % n;
//			int newSum = sum + A[i];
//			if (newSum > A[i] && i1 < firstI + n) {
//				sum = newSum;
//			}
//			else {
//				firstI = i;
//				sum = A[i];
//			}
//			//sum = max(A[i], sum + A[i]);
//			maxSum = max(maxSum, sum);
//		}
//		return maxSum;
//	}
//};

//class Solution {
//public:
//	int maxSubarraySumCircular(vector<int>& A) {
//		const size_t n = A.size();
//		int sum = A[0];
//		int maxSum = sum;
//		size_t j = 0;
//		for (size_t i1 = 1; i1 < 2 * n; ++i1) {
//			size_t i = i1 % n;
//			sum += A[i];
//			if (sum > A[i]) {
//				while (i1 - j > n)
//					sum -= A[j++ % n];
//				while (j < i1 && /*j < n &&*/ A[j % n] < 0) {
//					sum -= A[j++ % n];
//					maxSum = max(maxSum, sum);
//				}
//			}
//			else {
//				sum = A[i];
//				j = i1;
//			}
//			maxSum = max(maxSum, sum);
//		}
//		return maxSum;
//	}
//};

// ACCEPTED
//class Solution {
//public:
//	
//	int kadane_max(const vector<int>& A) {
//		const size_t n = A.size();
//		int sum = A[0];
//		int maxSum = sum;
//		for (size_t i = 1; i < n; ++i) {
//			sum = max(A[i], sum + A[i]);
//			maxSum = max(maxSum, sum);
//		}
//		return maxSum;
//	}
//
//	int maxSubarraySumCircular(vector<int>& A) {
//		const size_t n = A.size();
//		
//		int max1 = kadane_max(A);
//
//		int sum = 0;
//		for (size_t i = 0; i < n; ++i) {
//			sum += A[i];
//			A[i] = -A[i];
//		}
//		int max2 = kadane_max(A);
//		if (abs(max2) == abs(sum))
//			return max1;
//		max2 += sum;
//
//		return max(max1, max2);
//	}
//};

// ACCEPTED
//class Solution {
//public:
//
//	int kadane_max(const vector<int>& A) {
//		const size_t n = A.size();
//		int sum = A[0];
//		int maxSum = sum;
//		for (size_t i = 1; i < n; ++i) {
//			sum = max(A[i], sum + A[i]);
//			maxSum = max(maxSum, sum);
//		}
//		return maxSum;
//	}
//
//	int maxSubarraySumCircular(vector<int>& A) {
//		const int n = A.size();
//		
//		int maxSum = kadane_max(A);
//		vector<int> rmax(n);
//		
//		rmax[n - 1] = A[n - 1];
//		int sum = A[n - 1];
//		for (int i = n - 2; i >= 0; --i) {
//			sum += A[i];
//			rmax[i] = max(rmax[i+1], sum);
//		}
//
//		if (n > 2) {
//			int lSum = A[0];
//			maxSum = max(maxSum, lSum + rmax[2]);
//			//int lSum = 0;
//			for (int i = 1; i < n - 2; ++i) {
//			//for (int i = 0; i < n - 2; ++i) {
//				lSum += A[i];
//				maxSum = max(maxSum, lSum + rmax[i + 1]);
//			}
//		}
//
//		return maxSum;
//	}
//};

// ACCEPTED
class Solution {
public:

	int maxSubarraySumCircular(vector<int>& A) {
		const int n = A.size();

		int result = A[0];
		vector<int> P(2 * n + 1);
		for (int i = 0; i < 2 * n; ++i)
			P[i + 1] = P[i] + A[i % n];

		deque<int> ind;
		ind.push_back(0);
		for (int j = 1; j <= 2 * n; ++j) {
			if (ind.front() < j - n)
				ind.pop_front();

			result = max(result, P[j] - P[ind.front()]);

			while (!ind.empty() && P[j] <= P[ind.back()])
				ind.pop_back();

			ind.push_back(j);
		}
		
		return result;
	}
};

int main()
{
	cout << Solution().maxSubarraySumCircular(vector<int>{52, 183, 124, 154, -170, -191, -240, 107, -178, 171, 75, 186, -125, 61, -298, 284, 21, -73, -294, 253, 146, 248, -248, 127, 26, 289, 118, -22, -300, 26, -116, -113, -44, 29, 252, -278, 47, 254, -106, 246, -275, 42, 257, 15, 96, -298, -69, -104, -239, -95, -4, 76, -202, 156, -14, -178, 188, -84, 78, -195, -125, 28, 109, 125, -25, -53, 58, 287, 55, -296, 198, 281, 53, -160, 146, 298, 25, -41, -3, 27, -242, 169, 287, -281, 19, 91, 213, 115, 211, -218, 124, -25, -272, 278, 296, -177, -166, -192, 97, -49, -25, 168, -81, 6, -94, 267, 293, 146, -1, -258, 256, 283, -156, 197, 28, 78, 267, -151, -230, -66, 100, -94, -66, -123, 121, -214, -182, 187, 65, -186, 215, 273, 243, -99, -76, 178, 59, 190, 279, 300, 217, 67, -117, 170, 163, 153, -37, -147, -251, 296, -176, 117, 68, 258, -159, -300, -36, -91, -60, 195, -293, -116, 208, 175, -100, -97, 188, 79, -270, 80, 100, 211, 112, 264, -217, -142, 5, 105, 171, -264, -247, 138, 275, 227, -86, 30, -219, 153, 10, -66, 267, 22, -56, -70, -234, -66, 89, 182, 110, -146, 162, -48, -201, -240, -225, -15, -275, 129, -117, 28, 150, 84, -264, 249, -85, 70, -140, -259, 26, 162, 5, -203, 143, 184, 101, 140, 207, 131, 177, 274, -178, -79, 14, -36, 104, 52, 31, 257, 273, -52, 74, 276, 104, -133, -255, 188, -252, 229, 200, -74, -39, -250, 142, -201, -196, -43, -40, 255, -149, -299, -197, -175, -96, -155, -196, -24, 12, 79, 71, -144, -59, -120, 227, -256, -163, -297, 116, 286, -283, -31, -221, -41, 121, -170, 160, 205, 8, 88, 25, -272, -107, 292, -180, 299, 94, -97, -81, -134, 37, 238}) << endl; // 5803
	cout << Solution().maxSubarraySumCircular(vector<int>{-3, 3, -4, -1, 8, -7, -7, -5}) << endl; // 8
	cout << Solution().maxSubarraySumCircular(vector<int>{-5, 3, 5}) << endl; // 8
	cout << Solution().maxSubarraySumCircular(vector<int>{1, -2, 3, -2}) << endl; // 3
	cout << Solution().maxSubarraySumCircular(vector<int>{5, -3, 5}) << endl; // 10
	cout << Solution().maxSubarraySumCircular(vector<int>{3, -1, 2, -1}) << endl; // 4
	cout << Solution().maxSubarraySumCircular(vector<int>{3, -2, 2, -3}) << endl; // 3
	cout << Solution().maxSubarraySumCircular(vector<int>{-2, -3, -1}) << endl; // -1
	cout << Solution().maxSubarraySumCircular(vector<int>{1}) << endl; // 1

    return 0;
}

