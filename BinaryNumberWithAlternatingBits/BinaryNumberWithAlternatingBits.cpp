
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>
#include <iomanip>

using namespace std;

/*

https://leetcode.com/problems/binary-number-with-alternating-bits/

Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:
Input: 5
Output: True
Explanation:
The binary representation of 5 is: 101
Example 2:
Input: 7
Output: False
Explanation:
The binary representation of 7 is: 111.
Example 3:
Input: 11
Output: False
Explanation:
The binary representation of 11 is: 1011.
Example 4:
Input: 10
Output: True
Explanation:
The binary representation of 10 is: 1010.

*/

class Solution {
public:
	bool hasAlternatingBits(int n) {
		bool firstTime = true;
		bool prev = false;
		while (n)
		{
			bool current = (1 == (n & 1));
			if (!firstTime && current == prev)
				return false;
			prev = current;
			n >>= 1;
			firstTime = false;
		}
		return true;
	}
};


int main()
{
	cout << boolalpha << Solution().hasAlternatingBits(0) << endl; // true
	cout << boolalpha << Solution().hasAlternatingBits(1) << endl; // true
	cout << boolalpha << Solution().hasAlternatingBits(5) << endl; // true
	cout << boolalpha << Solution().hasAlternatingBits(7) << endl; // false
	cout << boolalpha << Solution().hasAlternatingBits(11) << endl; // false
	cout << boolalpha << Solution().hasAlternatingBits(10) << endl; // true

    return 0;
}

