
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/n-th-tribonacci-number/

The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.



Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537


Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
*/

class Solution {
public:
	int tribonacci(int n) {
		static vector<int> numbers;
		if (numbers.empty()) {
			numbers.resize(37 + 1);
			numbers[0] = 0;
			numbers[1] = 1;
			numbers[2] = 1;
			for (int i = 3; i <= 37; ++i)
				numbers[i] = numbers[i - 1] + numbers[i - 2] + numbers[i - 3];
		}
		return numbers[n];
	}
};

int main()
{
	cout << Solution().tribonacci(4) << endl; // 4
	cout << Solution().tribonacci(25) << endl; // 1389537

    return 0;
}

