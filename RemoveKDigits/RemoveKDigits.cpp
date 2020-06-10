
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
https://leetcode.com/problems/remove-k-digits/
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ? k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

class Solution {
public:
	string removeKdigits(string num, int k) {
		string result;
		result.reserve(num.length());
		const int n = num.size();
		for (int i = 0; i < n; ++i) {
			while (!result.empty() && k > 0 && result[result.length() - 1] > num[i]) {
				--k;
				result.erase(begin(result) + result.length() - 1);
			}
			result += num[i];
			if (result == "0")
				result = "";
			/*if (!result.empty() && k > 0 && result[result.length() - 1] > num[i]) {
				result[result.length() - 1] = num[i];
				if (result == "0")
					result = "";
				--k;
			}
			else {
				result += num[i];
			}*/
		}
		if (k > 0) {
			if (result.length() >= k)
				result = result.substr(0, result.length() - k);
			else
				result = "";
			/*if (result.length() >= k)
				result = result.substr(k);
			else
				result = "";*/
		}
		if (result.empty())
			result = "0";
		return result;
	}
};

int main()
{
	cout << Solution().removeKdigits("112", 1) << endl; // 11

	cout << Solution().removeKdigits("1234567890", 9) << endl; // 0

	cout << Solution().removeKdigits("9", 1) << endl; // 0

	cout << Solution().removeKdigits("1432219", 3) << endl; // 1219
	cout << Solution().removeKdigits("10200", 1) << endl; // 200
	cout << Solution().removeKdigits("10", 2) << endl; // 0

    return 0;
}

