
#include <vector>
#include <iostream>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3316/

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version.

*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

static int firstBadVersion = 4;

void setFirstBadVersion(int badVersion) {
	firstBadVersion = badVersion;
}

bool isBadVersion(int version) {
	return version >= firstBadVersion;
}

class Solution {
public:
	int firstBadVersion(int n) {
		int l = 1;
		int r = n;
		if (isBadVersion(1))
			return 1;
		while (r - l > 1) {
			int m = l + (r - l) / 2;
			if (isBadVersion(m))
				r = m;
			else
				l = m;
		}
		return l+1;
	}
};


void runTest(int badVersion, int nVersions) {
	setFirstBadVersion(badVersion);
	cout << Solution().firstBadVersion(nVersions) << endl;
}

int main()
{
	runTest(1702766719, 2126753390);

	runTest(2, 2);

	runTest(1, 1);

	runTest(4, 5);

	runTest(101, 500);

    return 0;
}

