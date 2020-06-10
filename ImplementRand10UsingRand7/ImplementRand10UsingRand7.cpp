
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/implement-rand10-using-rand7/
Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.

Do NOT use system's Math.random().


Example 1:

Input: 1
Output: [7]
Example 2:

Input: 2
Output: [8,4]
Example 3:

Input: 3
Output: [8,1,10]


Note:

rand7 is predefined.
Each testcase has one argument: n, the number of times that rand10 is called.


Follow up:

What is the expected value for the number of calls to rand7() function?
Could you minimize the number of calls to rand7()?
*/

int rand7() {
	return 1 + rand() % 7;
}

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
	int rand10() {
		while (true) {
			int v = 7 * (rand7() - 1) + rand7() - 1;

			if (v < 40)
				return v % 10 + 1;
		}
		return -1;
	}
};

void runTest(int nSamples) {
	vector<int> v(10);
	for (int i = 0; i < nSamples; ++i)
		++v[Solution().rand10() - 1];
	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));
	runTest(1000);
    return 0;
}

