
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <unordered_set>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/

You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.

*/

class Solution {
public:
	int numJewelsInStones(string J, string S) {
		unordered_set<char> jewels;
		copy(begin(J), end(J), inserter(jewels, end(jewels)));
		int cnt = 0;
		for (const char c : S)
			if (jewels.find(c) != end(jewels))
				++cnt;
		return cnt;
	}
};

int main()
{
	cout << Solution().numJewelsInStones("aA", "aAAbbbb") << endl; // 3
	cout << Solution().numJewelsInStones("z", "ZZ") << endl; // 0
    return 0;
}

