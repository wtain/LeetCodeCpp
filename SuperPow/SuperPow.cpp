
#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/super-pow/

Your task is to calculate a^b mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example 1:

Input: a = 2, b = [3]
Output: 8
Example 2:

Input: a = 2, b = [1,0]
Output: 1024
*/

//Runtime: 20 ms
//Memory Usage : 11.6 MB
// 38.46%
class Solution {
public:
	int superPow(int a, vector<int>& b) {
		int result = 1;
		const int mod = 1337;
		int am = a % mod;

		for (int i = b.size() - 1; i >= 0; --i) {
			int mul = 1;
			for (int j = 0; j < 10; ++j) {
				if (j < b[i]) {
					result *= am;
					result %= mod;
				}
				mul *= am;
				mul %= mod;
			}
			am = mul;
		}

		return result;
	}
};

int main()
{
	cout << Solution().superPow(2, vector<int>{3}) << endl; // 8
	cout << Solution().superPow(2, vector<int>{1, 0}) << endl; // 1024

    return 0;
}

