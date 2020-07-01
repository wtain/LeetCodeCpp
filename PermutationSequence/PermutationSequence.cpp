
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3366/
https://leetcode.com/problems/permutation-sequence/

The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
*/

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Permutation Sequence.
//Memory Usage : 6.2 MB, less than 20.08% of C++ online submissions for Permutation Sequence.
class Solution {
public:

	int factorial(int n) {
		int result = 1;
		for (int i = 2; i <= n; ++i)
			result *= i;
		return result;
	}

	void getPermutationImpl(string& result, vector<bool>& used, int n, int k) {
		if (result.length() == used.size())
			return;
		int f = factorial(n - 1);
		int i = k / f;

		// take ith unused digit (i - 0-based)

		int j = 0;
		int l = 0;
		while (j < i) {
			if (used[l++])
				continue;
			++j;
		}
		while (used[l])
			l++;
		used[l] = true;
		result += '1' + l;
		getPermutationImpl(result, used, n-1, k - i * f);
	}

	string getPermutation(int n, int k) {
		string result;
		vector<bool> used(n, false);
		getPermutationImpl(result, used, n, k-1);
		return result;
	}
};

int main()
{
	cout << Solution().getPermutation(3, 3) << endl; // 213
	cout << Solution().getPermutation(9, 15) << endl; // 123458769
	cout << Solution().getPermutation(4, 9) << endl; // 2314
	
	

    return 0;
}

