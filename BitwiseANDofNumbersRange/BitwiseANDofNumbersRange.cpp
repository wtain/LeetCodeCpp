
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/bitwise-and-of-numbers-range/

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
*/

//class Solution {
//public:
//
//	int rangeBitwiseAnd(int m, int n) {
//		int result = 0;
//
//		unsigned long mask = 1 << 31; // 1000...000
//
//		//int mask2 = 0;
//
//		while (mask > m) {
//			//mask2 |= mask;
//			mask >>= 1;
//		}
//
//		while (mask) {
//			if ((mask & m) && (mask & n))
//			{
//				//  mask2 = 1..100..0
//				// ~mask2 = 0..011..1
//				//  mask  = 0..010..0
//				unsigned long x = (mask << 1);
//				if (x > n)
//					result |= mask;
//			}
//			/*m &= ~mask;
//			n &= ~mask;*/
//			//mask2 |= mask;
//			/*if (mask == 1)
//				break;*/
//			mask >>= 1;
//		}
//
//		return result;
//	}
//};

//class Solution {
//public:
//
//	int rangeBitwiseAnd(int m, int n) {
//		int result = 0;
//
//		unsigned long mask = 1ull << 31;
//
//		while (mask > m) {
//			mask >>= 1;
//		}
//
//		unsigned long mask_c = 0;
//		while (mask) {
//			mask_c |= (mask << 1);
//			if ((mask & m) && (mask & n))
//			{
//				/*
//				min   .....1......
//				max   .....1......
//				mask  000001000000
//				maskc 111110000000
//				*/
//
//				unsigned long x = m & mask_c | (mask << 1);
//				if (x > n || x < m)
//					result |= mask;
//				
//			}
//			mask >>= 1;
//		}
//
//		return result;
//	}
//};

//Runtime: 12 ms, faster than 60.81% of C++ online submissions for Bitwise AND of Numbers Range.
//Memory Usage : 6.1 MB, less than 100.00% of C++ online submissions for Bitwise AND of Numbers Range.
class Solution {
public:

	int rangeBitwiseAnd(int m, int n) {

		unsigned long long M = m;
		unsigned long long N = n;

		unsigned long long result = 0;

		unsigned long long mask = 1ull << 31;

		while (mask > M) {
			mask >>= 1;
		}

		unsigned long long mask_c = 0;
		while (mask) {
			//cout << mask << endl;
			mask_c |= (mask << 1);
			if ((mask & M) && (mask & N))
			{
				/*
				min   .....1......
				max   .....1......
				mask  000001000000
				maskc 111110000000
				*/

				unsigned long long x = (M & mask_c) + (mask << 1);
				if (x > N || x < M)
					result |= mask;

			}
			mask >>= 1;
		}

		return result;
	}
};

//#pragma message("!!!!!!!!!!!!!!!!!!!!!!!! Not solved problem, MEDIUM")

int main()
{
	cout << Solution().rangeBitwiseAnd(3, 5) << endl; // 0

	cout << Solution().rangeBitwiseAnd(1, 10) << endl; // 0
	cout << Solution().rangeBitwiseAnd(127, 128) << endl; // 0
	cout << Solution().rangeBitwiseAnd(126, 127) << endl; // 126

	cout << Solution().rangeBitwiseAnd(6, 7) << endl; // 6
	cout << Solution().rangeBitwiseAnd(5, 7) << endl; // 4
	cout << Solution().rangeBitwiseAnd(0, 1) << endl; // 0
	cout << Solution().rangeBitwiseAnd(2147483646, 2147483647) << endl; // 2147483646

    return 0;
}

