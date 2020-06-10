
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/rotated-digits/

X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.  Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other (on this case they are rotated in a different direction, in other words 2 or 5 gets mirrored); 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

Now given a positive number N, how many numbers X from 1 to N are good?

Example:
Input: 10
Output: 4
Explanation:
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
Note:

N  will be in range [1, 10000].

*/

//Runtime: 4 ms, faster than 55.70% of C++ online submissions for Rotated Digits.
//Memory Usage : 6.2 MB, less than 100.00% of C++ online submissions for Rotated Digits.
class Solution {
public:

	//      0 1 2 3 4 5 6 7 8 9
	// GOOD
	//  BAD       V V     V
	bool isRotatedGood(int i) {
		bool found2569 = false;
		while (i) {
			int d = i % 10;
			if (d == 3 || d == 4 || d == 7)
				return false;
			if (d == 2 || d == 5 || d == 6 || d == 9)
				found2569 = true;
			i /= 10;
		}
		return found2569;
	}

	int rotatedDigits(int N) {
		int cnt = 0;
		for (int i = 1; i <= N; ++i)
			if (isRotatedGood(i))
				++cnt;
		return cnt;
	}
};

int main()
{
	cout << Solution().rotatedDigits(10) << endl; // 4
	cout << Solution().rotatedDigits(10000) << endl; // 2320

    return 0;
}

