
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

/*
https://leetcode.com/problems/increasing-decreasing-string/

Given a string s. You should re-order the string using the following algorithm:

Pick the smallest character from s and append it to the result.
Pick the smallest character from s which is greater than the last appended character to the result and append it.
Repeat step 2 until you cannot pick more characters.
Pick the largest character from s and append it to the result.
Pick the largest character from s which is smaller than the last appended character to the result and append it.
Repeat step 5 until you cannot pick more characters.
Repeat the steps from 1 to 6 until you pick all characters from s.
In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.

Return the result string after sorting s with this algorithm.



Example 1:

Input: s = "aaaabbbbcccc"
Output: "abccbaabccba"
Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
Example 2:

Input: s = "rat"
Output: "art"
Explanation: The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.
Example 3:

Input: s = "leetcode"
Output: "cdelotee"
Example 4:

Input: s = "ggggggg"
Output: "ggggggg"
Example 5:

Input: s = "spo"
Output: "ops"


Constraints:

1 <= s.length <= 500
s contains only lower-case English letters.
*/

//Runtime: 16 ms, faster than 71.47% of C++ online submissions for Increasing Decreasing String.
//Memory Usage : 7.5 MB, less than 80.94% of C++ online submissions for Increasing Decreasing String.
//Runtime: 16 ms, faster than 71.47% of C++ online submissions for Increasing Decreasing String.
//Memory Usage : 7.5 MB, less than 84.85% of C++ online submissions for Increasing Decreasing String.
class Solution {
public:

	static constexpr int MaxIndex() {
		return 26;
	}
	
	vector<int> countChars(const string& s) {
		vector<int> result;
		result.resize(MaxIndex());
		for (const auto c : s)
			++result[c - 'a'];
		return result;
	}

	int getSmallestIndex(const vector<int>& counts, int i) {
		while (i < MaxIndex() && !counts[i])
			++i;
		return i;
	}

	int getLargestIndex(const vector<int>& counts, int i) {
		while (i >= 0 && !counts[i])
			--i;
		return i;
	}

	string sortString(string s) {
		auto counts = countChars(s);
		string result;
		while (result.length() < s.length()) {
			int i1 = 0;
			while ((i1 = getSmallestIndex(counts, i1)) < MaxIndex()) {
				result += 'a' + i1;
				--counts[i1++];
			}
			int i2 = MaxIndex() - 1;
			while ((i2 = getLargestIndex(counts, i2)) >= 0) {
				result += 'a' + i2;
				--counts[i2--];
			}
		}
		return result;
	}
};

void runTest(const string& s, const string& expected) {
	const auto result = Solution().sortString(s);
	cout << boolalpha << (result == expected) << " - " << s << endl;
}

int main()
{
	vector<pair<string, string>> tests = {
		{ "aaaabbbbcccc" , "abccbaabccba" },
		{ "rat" , "art" },
		{ "leetcode" , "cdelotee" },
		{ "ggggggg" , "ggggggg" },
		{ "spo" , "ops" }

		, { "" , "" }
		, { "z" , "z" }
	};

	for (const auto& test : tests)
		runTest(test.first, test.second);

    return 0;
}

