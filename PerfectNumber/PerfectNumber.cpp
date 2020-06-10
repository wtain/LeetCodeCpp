
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*
https://leetcode.com/problems/perfect-number/

We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Note: The input number n will not exceed 100,000,000. (1e8)
*/

// TLE
//class Solution {
//public:
//	bool checkPerfectNumber(int num) {
//		if (num <= 0)
//			return false;
//		int sum = 0;
//		//int s = sqrt(num);
//		for (int i = 1; i < num; ++i) { // <= s
//			if (!(num % i))
//				sum += i; //  + num / i
//		}
//		return sum == num;
//	}
//};

class Solution {
public:
	bool checkPerfectNumber(int num) {
		if (num <= 1)
			return false;
		int sum = 0;
		int s = sqrt(num);
		for (int i = 1; i <= s; ++i) {
			if (!(num % i)) {
				sum += i;
				if (1 != i)
					sum += num / i;
				if (sum > num)
					return false;
			}
		}
		return sum == num;
	}
};


int main()
{
	cout << boolalpha << Solution().checkPerfectNumber(28) << endl; // true
	cout << boolalpha << Solution().checkPerfectNumber(0) << endl; // false
	cout << boolalpha << Solution().checkPerfectNumber(1) << endl; // false
    return 0;
}

