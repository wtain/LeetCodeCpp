
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

/*
https://leetcode.com/problems/bulls-and-cows/

You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows.

Please note that both secret number and friend's guess may contain duplicate digits.

Example 1:

Input: secret = "1807", guess = "7810"

Output: "1A3B"

Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
Example 2:

Input: secret = "1123", guess = "0111"

Output: "1A1B"

Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
Note: You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

*/


//Runtime: 16 ms, faster than 30.53% of C++ online submissions for Bulls and Cows.
//Memory Usage : 6.8 MB, less than 29.39% of C++ online submissions for Bulls and Cows.
class Solution {
public:
	string getHint(string secret, string guess) {
		const auto n = secret.length();
		int bulls = 0, cows = 0;
		unordered_map<char, int> unmatched;
		for (auto i = 0; i < n; ++i)
			if (secret[i] == guess[i])
				++bulls;
			else
				unmatched[secret[i]]++;

		for (auto i = 0; i < n; ++i)
			if (secret[i] != guess[i] && unmatched[guess[i]] > 0) {
				++cows;
				unmatched[guess[i]]--;
			}
		ostringstream str;
		str << bulls << "A" << cows << "B";
		return str.str();
	}
};

int main()
{
	cout << Solution().getHint("1807", "7810") << endl; // "1A3B"
	cout << Solution().getHint("1123", "0111") << endl; // "1A1B"

    return 0;
}

