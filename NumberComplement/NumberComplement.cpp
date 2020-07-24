
#include <iostream>

using namespace std;

/*
https://leetcode.com/problems/number-complement/
Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.



Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.


Constraints:

The given integer num is guaranteed to fit within the range of a 32-bit signed integer.
num >= 1
You could assume no leading zero bit in the integer’s binary representation.
This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/
*/

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number Complement.
//Memory Usage : 6.1 MB, less than 39.27% of C++ online submissions for Number Complement.
class Solution {
public:
	int findComplement(int num) {
		int rv = 0;
		int mask = 1;
		while (num)
		{
			int d = 1 - (num & 1);
			if (d)
				rv |= mask;
			mask <<= 1;
			num >>= 1;
		}
		return rv;
	}
};

int main()
{
	cout << Solution().findComplement(5) << endl; // 2
	cout << Solution().findComplement(1) << endl; // 0

    return 0;
}

