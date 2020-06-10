
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/binary-prefix-divisible-by-5/

Given an array A of 0s and 1s, consider N_i: the i-th subarray from A[0] to A[i] interpreted as a binary number (from most-significant-bit to least-significant-bit.)

Return a list of booleans answer, where answer[i] is true if and only if N_i is divisible by 5.

Example 1:

Input: [0,1,1]
Output: [true,false,false]
Explanation:
The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.  Only the first number is divisible by 5, so answer[0] is true.
Example 2:

Input: [1,1,1]
Output: [false,false,false]
Example 3:

Input: [0,1,1,1,1,1]
Output: [true,false,false,false,true,false]
Example 4:

Input: [1,1,1,0,1]
Output: [false,false,false,false,false]


Note:

1 <= A.length <= 30000
A[i] is 0 or 1

*/

//Runtime: 16 ms, faster than 96.43% of C++ online submissions for Binary Prefix Divisible By 5.
//Memory Usage : 14 MB, less than 35.27% of C++ online submissions for Binary Prefix Divisible By 5.
class Solution {
public:
	vector<bool> prefixesDivBy5(vector<int>& A) {
		const size_t N = A.size();
		vector<bool> result(N);
		int v = 0;
		for (size_t i = 0; i < N; ++i) {
			v <<= 1;
			v += A[i];
			result[i] = !(v % 5);
			v %= 5;
		}
		return result;
	}
};

void print(const vector<bool>& s) {
	cout << boolalpha;
	copy(begin(s), end(s), ostream_iterator<bool>(cout, " "));
	cout << endl;
}

int main()
{
	print(Solution().prefixesDivBy5(vector<int>{0, 1, 1})); // true false false
	print(Solution().prefixesDivBy5(vector<int>{1, 1, 1})); // false false false
	print(Solution().prefixesDivBy5(vector<int>{0, 1, 1, 1, 1, 1})); // true,false,false,false,true,false
	print(Solution().prefixesDivBy5(vector<int>{1, 1, 1, 0, 1})); // false,false,false,false,false

	print(Solution().prefixesDivBy5(vector<int>{1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1})); // [false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,true,false,false,true,true,true,true,false]

    return 0;
}

