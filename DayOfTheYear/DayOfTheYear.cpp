
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
https://leetcode.com/problems/day-of-the-year/

Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.



Example 1:

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.
Example 2:

Input: date = "2019-02-10"
Output: 41
Example 3:

Input: date = "2003-03-01"
Output: 60
Example 4:

Input: date = "2004-03-01"
Output: 61
*/

class Solution {
public:

	bool isLeapYear(int year) {
		return year % 400 == 0 ||
			year % 100 != 0 && year % 4 == 0;
	}

	int dayOfYear(string date) {
		int year = stoi(date.substr(0, 4));
		int month = stoi(date.substr(5, 2));
		int day = stoi(date.substr(8, 2));
		vector<int> lengths = {31, 28, 31, 30, 31, 30, 
							   31, 31, 30, 31, 30, 31};

		if (isLeapYear(year))
			++lengths[1];

		int n = 0;

		for (int m = 0; m < month - 1; ++m)
			n += lengths[m];

		n += day;

		return n;
	}
};

int main()
{
	cout << Solution().dayOfYear("2019-01-09") << endl; // 9
	cout << Solution().dayOfYear("2019-02-10") << endl; // 41
	cout << Solution().dayOfYear("2003-03-01") << endl; // 60
	cout << Solution().dayOfYear("2004-03-01") << endl; // 61

    return 0;
}

