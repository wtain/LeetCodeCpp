
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/find-smallest-letter-greater-than-target/
Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

Examples:
Input:
letters = ["c", "f", "j"]
target = "a"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "c"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "d"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "g"
Output: "j"

Input:
letters = ["c", "f", "j"]
target = "j"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "k"
Output: "c"
Note:
letters has a length in range [2, 10000].
letters consists of lowercase letters, and contains at least 2 unique letters.
target is a lowercase letter.
*/

//Runtime: 28 ms, faster than 84.03% of C++ online submissions for Find Smallest Letter Greater Than Target.
//Memory Usage : 16.2 MB, less than 12.77% of C++ online submissions for Find Smallest Letter Greater Than Target.
class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		auto it = upper_bound(begin(letters), end(letters), target);
		if (it == end(letters))
			return *begin(letters);
		return *it;
	}
};

int main()
{
	cout << Solution().nextGreatestLetter(vector<char>{ 'c', 'f', 'j' }, 'a') << endl; // c
	cout << Solution().nextGreatestLetter(vector<char>{ 'c', 'f', 'j' }, 'c') << endl; // f
	cout << Solution().nextGreatestLetter(vector<char>{ 'c', 'f', 'j' }, 'd') << endl; // f
	cout << Solution().nextGreatestLetter(vector<char>{ 'c', 'f', 'j' }, 'g') << endl; // j
	cout << Solution().nextGreatestLetter(vector<char>{ 'c', 'f', 'j' }, 'j') << endl; // c
	cout << Solution().nextGreatestLetter(vector<char>{ 'c', 'f', 'j' }, 'k') << endl; // c

    return 0;
}

