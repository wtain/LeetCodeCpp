
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/plus-one/
https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3382/

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/

//Runtime: 4 ms, faster than 57.17% of C++ online submissions for Plus One.
//Memory Usage : 9 MB, less than 12.93% of C++ online submissions for Plus One.
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int c = 1;
		int n = digits.size();
		for (int i = n - 1; i >= 0; --i)
		{
			if (!c)
				break;
			int r = digits[i] + c;
			c = (r > 9) ? 1 : 0;
			r %= 10;
			digits[i] = r;
		}
		vector<int> result;
		if (c)
			result.push_back(1);
		for (const auto i : digits)
			result.push_back(i);
		return result;
	}
};

void print(const vector<int>& v) {
	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	print(Solution().plusOne(vector<int>{1, 2, 3})); // 1 2 4
	print(Solution().plusOne(vector<int>{4, 3, 2, 1})); // 4 3 2 2

    return 0;
}

