
#include <iostream>

using namespace std;

/*
https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3381/
https://leetcode.com/problems/hamming-distance/

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ? x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
?   ?

The above arrows point to positions where the corresponding bits are different.
*/

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Hamming Distance.
//Memory Usage : 5.9 MB, less than 67.28% of C++ online submissions for Hamming Distance.
class Solution {
public:
	int hammingDistance(int x, int y) {
		int d = 0;
		while (x || y)
		{
			if ((x & 1) != (y & 1))
				++d;
			x >>= 1; y >>= 1;
		}
		return d;
	}
};

int main()
{
	cout << Solution().hammingDistance(1, 4) << endl; // 2

    return 0;
}

