// FindNUniqueIntegersSumUpToZero.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

Given an integer n, return any array containing n unique integers such that they add up to 0.



Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]


Constraints:

1 <= n <= 1000
*/

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find N Unique Integers Sum up to Zero.
//Memory Usage : 6.8 MB, less than 30.43% of C++ online submissions for Find N Unique Integers Sum up to Zero.
class Solution {
public:
	vector<int> sumZero(int n) {
		vector<int> result;
		result.reserve(n);
		int n2 = n >> 1;
		if (n % 2)
			result.push_back(0);
		for (int i = 1; i <= n2; ++i) {
			result.push_back(i);
			result.push_back(-i);
		}
		return result;
	}
};

void print(const vector<int>& s) {
	copy(begin(s), end(s), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	print(Solution().sumZero(5));
	print(Solution().sumZero(3));
	print(Solution().sumZero(1));

    return 0;
}

