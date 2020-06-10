
#include <iostream>
#include <string>

using namespace std;

/*
https://leetcode.com/problems/base-7/

Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].
*/

class Solution {
public:

	string convertToBase7(int num) {
		if (num == numeric_limits<int>::min())
			return "-104134211162";
		if (num < 0)
			return "-" + convertToBase7(-num);
		if (!num)
			return "0";
		string result;

		while (num > 0) {
			char d = '0' + num % 7;
			result = string() + d + result;
			num /= 7;
		}
		
		return result;
	}
};

int main()
{
	cout << Solution().convertToBase7(100) << endl; // 202
	cout << Solution().convertToBase7(-7) << endl; // -10
	cout << Solution().convertToBase7(numeric_limits<int>::max()) << endl; // 104134211161
	cout << Solution().convertToBase7(numeric_limits<int>::min()) << endl; // -104134211162
    return 0;
}

