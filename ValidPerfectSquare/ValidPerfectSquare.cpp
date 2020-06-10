
#include <iostream>
#include <iomanip>

using namespace std;

/*
https://leetcode.com/problems/valid-perfect-square/

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
*/

class Solution {
public:
	bool isPerfectSquare(int num) {
		int /*sq = 2, */d = 2, dprev = 0;
		//while (sq < num) {
		while (abs(d - dprev) > 1) {
		//do {
			int n = (d + num / d) / 2;
			dprev = d;
			d = n;
			//sq = d * d;
		}
		//} while (d < dprev);
		//return sq == num;
		return d*d == num;
	}
};

int main()
{
	cout << boolalpha << Solution().isPerfectSquare(16) << endl; // true
	cout << boolalpha << Solution().isPerfectSquare(14) << endl; // false
	cout << boolalpha << Solution().isPerfectSquare(9) << endl; // true
	cout << boolalpha << Solution().isPerfectSquare(25) << endl; // true
	cout << boolalpha << Solution().isPerfectSquare(23) << endl; // false
	cout << boolalpha << Solution().isPerfectSquare(24) << endl; // false
	cout << boolalpha << Solution().isPerfectSquare(100) << endl; // true


    return 0;
}

