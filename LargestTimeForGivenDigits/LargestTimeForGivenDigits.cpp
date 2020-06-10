
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iomanip>

using namespace std;

/*
https://leetcode.com/problems/largest-time-for-given-digits/

Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.



Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""


Note:

A.length == 4
0 <= A[i] <= 9
*/


// WRONG
//class Solution {
//public:
//	string largestTimeFromDigits(vector<int>& A) {
//		vector<int> maxes = { 2, 9, 5, 9 };
//		map<int, int> digits;
//		//copy(begin(A), end(A), inserter(digits, end(digits)));
//		for (int i = 0; i < 4; ++i)
//			++digits[A[i]];
//
//		string result;
//
//		for (int i = 0; i < 4; ++i) {
//			/*auto it = digits.lower_bound(maxes[i]);
//			if (it == end(digits))
//				return{};*/
//			auto it = rbegin(digits);
//			while (it != rend(digits) && it->first > maxes[i])
//				++it;
//			if (it == rend(digits))
//				return "";
//			result += to_string(it->first);
//			if (i == 0 && it->first == 2)
//				maxes[1] = 3;
//			if (i == 1)
//				result += ":";
//			if (!--it->second)
//				digits.erase(it->first);
//		}
//		return result;
//	}
//};

class Solution {
public:
	string largestTimeFromDigits(vector<int>& A) {
		int result = -1;

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; j++) if (i != j) {
				for (int k = 0; k < 4; k++) if (k != j && k != i) {
					int l = 6 - i - j - k;
					int hours = 10 * A[i] + A[j];
					if (hours >= 24)
						continue;
					int minutes = 10 * A[k] + A[l];
					if (minutes >= 60)
						continue;
					result = max(result, hours * 60 + minutes);
				}
			}
		}

		if (-1 == result)
			return{};

		ostringstream stream;
		stream << setfill('0') << setw(2) << result / 60 << ":" << setfill('0') << setw(2) << result % 60;
		return stream.str();
	}
};

int main()
{
	cout << Solution().largestTimeFromDigits(vector<int>{2, 0, 6, 6}) << endl; // "06:26"
	cout << Solution().largestTimeFromDigits(vector<int>{0, 0, 0, 0}) << endl; // "00:00"
	cout << Solution().largestTimeFromDigits(vector<int>{1, 2, 3, 4}) << endl; // "23:41"
	cout << Solution().largestTimeFromDigits(vector<int>{5, 5, 5, 5}) << endl; // ""

    return 0;
}

