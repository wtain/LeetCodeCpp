
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/sort-array-by-parity/
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3431/
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.



Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.


Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000
*/

//Runtime: 28 ms, faster than 28.35% of C++ online submissions for Sort Array By Parity.
//Memory Usage : 16.5 MB, less than 36.77% of C++ online submissions for Sort Array By Parity.
class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		const int n = A.size();
		vector<int> result(n);
		int i1 = 0, i2 = n - 1;
		for (const auto a : A) {
			if (a % 2 == 0)
				result[i1++] = a;
			else
				result[i2--] = a;
		}
		return result;
	}
};

void print(const vector<int>& v) {
	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	print(Solution().sortArrayByParity(vector<int>{3, 1, 2, 4}));
	/*[2, 4, 3, 1]
	The outputs[4, 2, 3, 1], [2, 4, 1, 3], and[4, 2, 1, 3] would also be accepted.*/

    return 0;
}

