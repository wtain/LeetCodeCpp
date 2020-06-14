
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)

Example 1:

Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)
Example 2:

Input: L = 10, R = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
Note:

L, R will be integers L <= R in the range [1, 10^6].
R - L will be at most 10000.
*/

//Runtime: 64 ms, faster than 19.89% of C++ online submissions for Prime Number of Set Bits in Binary Representation.
//Memory Usage : 6.2 MB, less than 27.85% of C++ online submissions for Prime Number of Set Bits in Binary Representation.
//class Solution {
//
//	unordered_map<int, bool> isPrimeCache;
//
//public:
//
//	int countBits(int x) {
//		int cnt = 0;
//		while (x) {
//			if (x & 1)
//				++cnt;
//			x >>= 1;
//		}
//		return cnt;
//	}
//
//	bool isPrimeCheck(int n) {
//		if (n == 1)
//			return false;
//		int i = 2, i2 = i * i;
//		while (i2 <= n) {
//			if (!(n % i))
//				return false;
//			i2 += 2 * i + 1;
//			++i;
//		}
//		return true;
//	}
//
//	bool isPrime(int n) {
//		auto it = isPrimeCache.find(n);
//		if (it != end(isPrimeCache))
//			return it->second;
//		auto result = isPrimeCheck(n);
//		isPrimeCache.emplace_hint(it, n, result);
//		return result;
//	}
//
//	int countPrimeSetBits(int L, int R) {
//		int cnt = 0;
//		for (int i = L; i <= R; ++i)
//			if (isPrime(countBits(i)))
//				++cnt;
//		return cnt;
//	}
//};

//Runtime: 64 ms, faster than 19.89% of C++ online submissions for Prime Number of Set Bits in Binary Representation.
//Memory Usage : 6.1 MB, less than 45.98% of C++ online submissions for Prime Number of Set Bits in Binary Representation.
class Solution {

	vector<bool> isPrimeTable;

public:

	Solution() 
		: isPrimeTable(20, false) {
		isPrimeTable[2] = isPrimeTable[3] = isPrimeTable[5] = isPrimeTable[7]
			= isPrimeTable[11] = isPrimeTable[13] = isPrimeTable[17] = isPrimeTable[19] = true;
	}

	int countBits(int x) {
		int cnt = 0;
		while (x) {
			if (x & 1)
				++cnt;
			x >>= 1;
		}
		return cnt;
	}

	bool isPrime(int n) {
		return isPrimeTable[n];
	}

	int countPrimeSetBits(int L, int R) {
		int cnt = 0;
		for (int i = L; i <= R; ++i)
			if (isPrime(countBits(i)))
				++cnt;
		return cnt;
	}
};

int main()
{
	cout << Solution().countPrimeSetBits(6, 10) << endl; // 4
	cout << Solution().countPrimeSetBits(10, 15) << endl; // 5
	cout << Solution().countPrimeSetBits(842, 888) << endl; // 23

    return 0;
}

