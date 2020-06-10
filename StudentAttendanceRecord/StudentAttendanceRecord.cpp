
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*
https://leetcode.com/problems/student-attendance-record-i/

You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
*/

class Solution {
public:
	bool checkRecord(string s) {
		int n = s.length();
		bool wasAbsent = false;
		int lCount = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'L') {
				if (++lCount > 2)
					return false;
			}
			else
				lCount = 0;
				
			if (s[i] == 'A') {
				if (wasAbsent)
					return false;
				wasAbsent = true;
			}
		}
		return true;
	}
};

int main()
{
	cout << boolalpha << Solution().checkRecord("PPALLP") << endl; // true
	cout << boolalpha << Solution().checkRecord("PPALLL") << endl; // false
    return 0;
}

