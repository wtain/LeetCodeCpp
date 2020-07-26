
#include <iostream>

using namespace std;

/*
https://leetcode.com/problems/add-digits/

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2.
Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?

A naive implementation of the above process is trivial. Could you come up with other methods?
What are all the possible results?
How do they occur, periodically or randomly?
You may find this Wikipedia article useful. https://wiki2.org/en/Digital_root
*/

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Add Digits.
//Memory Usage : 5.9 MB, less than 68.69% of C++ online submissions for Add Digits.
namespace naive {
	class Solution {
	public:

		int sumDigits(int num)
		{
			int rv = 0;
			while (num)
			{
				rv += num % 10;
				num /= 10;
			}
			return rv;
		}

		int addDigits(int num)
		{
			while (num >= 10)
				num = sumDigits(num);
			return num;
		}
	};
}

//Runtime: 4 ms, faster than 53.99% of C++ online submissions for Add Digits.
//Memory Usage : 6.1 MB, less than 22.22% of C++ online submissions for Add Digits.
namespace advanced {
	class Solution {
	public:

		int addDigits(int num)
		{
			if (!num)
				return 0;
			return 1 + (num - 1) % 9;
		}
	};
}

using naive::Solution;

int main()
{
	cout << Solution().addDigits(38) << endl; // 2
	cout << advanced::Solution().addDigits(38) << endl; // 2

    return 0;
}

