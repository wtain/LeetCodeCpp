
#include <iostream>

using namespace std;

/*
https://leetcode.com/problems/guess-number-higher-or-lower/

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
1 : My number is higher
0 : Congrats! You got it!
Example :

Input: n = 10, pick = 6
Output: 6
*/

/**
* Forward declaration of guess API.
* @param  num   your guess
* @return 	     -1 if num is lower than the guess number
*			      1 if num is higher than the guess number
*               otherwise return 0
* int guess(int num);
*/

int guess(int num)
{
	const int k = 6; 
	//const int k = 1702766719;
	//const int k = 2147483647;
	if (k > num)
		return 1;
	if (k < num)
		return -1;
	return 0;
}

class Solution {
public:
	int guessNumber(int n) {
		int l = 1;
		//int r = n + 1;
		int r = n;
		//while (l < r) {
		while (l <= r) {
			//int m = (l + r) / 2;
			int m = l + (r - 1 - l) / 2;
			int c = guess(m);
			if (c == 1)
				l = m + 1;
			else if (c == -1)
				//r = m;
				r = m + 1;
			else
				return m;
		}
		return -1;
	}
};

int main()
{
	cout << Solution().guessNumber(10) << endl; // 6
	//cout << Solution().guessNumber(2126753390) << endl; // 1702766719
	//cout << Solution().guessNumber(2147483647) << endl; // 2147483647
	

    return 0;
}

