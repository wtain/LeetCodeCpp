
#include <iostream>
#include <cmath>

using namespace std;

/*
https://leetcode.com/problems/arranging-coins/
https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3377/

You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.

*/

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Arranging Coins.
//Memory Usage : 5.9 MB, less than 73.61% of C++ online submissions for Arranging Coins.
class Solution {
public:
	int arrangeCoins(int n)
	{
		if (n == 0)
			return 0;
		int n1 = (2 * sqrt(2 * static_cast<double>(n) + 1.0) - 1.0) / 2.0;
		return n1;
	}
};

int main()
{
	cout << Solution().arrangeCoins(5) << endl; // 2
	cout << Solution().arrangeCoins(8) << endl; // 3

    return 0;
}

