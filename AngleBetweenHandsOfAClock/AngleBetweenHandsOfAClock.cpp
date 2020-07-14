
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/explore/featured/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3390/
https://leetcode.com/problems/angle-between-hands-of-a-clock/
Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.



Example 1:



Input: hour = 12, minutes = 30
Output: 165
Example 2:



Input: hour = 3, minutes = 30
Output: 75
Example 3:



Input: hour = 3, minutes = 15
Output: 7.5
Example 4:

Input: hour = 4, minutes = 50
Output: 155
Example 5:

Input: hour = 12, minutes = 0
Output: 0


Constraints:

1 <= hour <= 12
0 <= minutes <= 59
Answers within 10^-5 of the actual value will be accepted as correct.
*/

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Angle Between Hands of a Clock.
//Memory Usage : 5.9 MB, less than 83.14% of C++ online submissions for Angle Between Hands of a Clock.
class Solution {
public:
	double angleClock(int hour, int minutes) {
		double ma = minutes * 6.0;
		double ha = (hour + minutes / 60.0) * 30.0;
		double angle = abs(ma - ha);
		return min(angle, 360.0 - angle);
	}
};

int main()
{
	cout << setprecision(4) << Solution().angleClock(12, 30) << endl; // 165
	cout << setprecision(4) << Solution().angleClock(3, 30) << endl; // 75
	cout << setprecision(4) << Solution().angleClock(3, 15) << endl; // 7.5
	cout << setprecision(4) << Solution().angleClock(4, 50) << endl; // 155
	cout << setprecision(4) << Solution().angleClock(12, 0) << endl; // 0

    return 0;
}

