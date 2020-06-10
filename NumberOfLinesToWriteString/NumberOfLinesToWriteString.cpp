
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

/*
https://leetcode.com/problems/number-of-lines-to-write-string/

We are to write the letters of a given string S, from left to right into lines. Each line has maximum width 100 units, and if writing a letter would cause the width of the line to exceed 100 units, it is written on the next line. We are given an array widths, an array where widths[0] is the width of 'a', widths[1] is the width of 'b', ..., and widths[25] is the width of 'z'.

Now answer two questions: how many lines have at least one character from S, and what is the width used by the last such line? Return your answer as an integer list of length 2.



Example :
Input:
widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "abcdefghijklmnopqrstuvwxyz"
Output: [3, 60]
Explanation:
All letters have the same length of 10. To write all 26 letters,
we need two full lines and one line with 60 units.
Example :
Input:
widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "bbbcccdddaaa"
Output: [2, 4]
Explanation:
All letters except 'a' have the same length of 10, and
"bbbcccdddaa" will cover 9 * 10 + 2 * 4 = 98 units.
For the last 'a', it is written on the second line because
there is only 2 units left in the first line.
So the answer is 2 lines, plus 4 units in the second line.


Note:

The length of S will be in the range [1, 1000].
S will only contain lowercase letters.
widths is an array of length 26.
widths[i] will be in the range of [2, 10].
*/

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Lines To Write String.
//Memory Usage : 7 MB, less than 100.00% of C++ online submissions for Number of Lines To Write String.
class Solution {
public:
	vector<int> numberOfLines(vector<int>& widths, string S) {
		//int totalCount = accumulate(begin(S), end(S), 0, [&](int v, char c) {return v + widths[c - 'a']; });
		static const int lineWidth = 100;
		//int nFullLines = totalCount / totalCount;

		int nLines = 1, nPos = 0;
		for (size_t i = 0; i < S.length(); ++i) {
			const int cw = widths[S[i] - 'a'];
			if (nPos + cw > lineWidth) {
				nPos = cw;
				++nLines;
			}
			else {
				nPos += cw;
			}
		}
		if (!nPos && nLines)
			--nLines;
		return{ nLines , nPos };
	}
};

void print(const vector<int>& v) {
	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	print(Solution().numberOfLines(vector<int>{10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, "abcdefghijklmnopqrstuvwxyz"));
	// 3 60

	print(Solution().numberOfLines(vector<int>{4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, "bbbcccdddaaa"));
	// 2 4

	print(Solution().numberOfLines(vector<int>{4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, ""));
	// 0 0

	print(Solution().numberOfLines(vector<int>{4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, "a"));
	// 1 4

	print(Solution().numberOfLines(vector<int>{10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, "aaaaaaaaaa"));
	// 1 100

	print(Solution().numberOfLines(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, "abcdefghijk"));
	// 1 65

    return 0;
}

