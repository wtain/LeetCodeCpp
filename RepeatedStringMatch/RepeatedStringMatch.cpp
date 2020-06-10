
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/repeated-string-match/
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
*/

// SIMPLE: Runtime: 12 ms, faster than 76.13% of C++ online submissions for Repeated String Match.
//class Solution {
//public:
//	int repeatedStringMatch(string A, string B) {
//		string big = A;
//		int n = 1;
//		while (big.length() < B.length()) {
//			++n;
//			big += A;
//		}
//		if (big.find(B) != string::npos)
//			return n;
//		++n;
//		big += A;
//		return big.find(B) == string::npos ? -1 : n;
//	}
//};

//Runtime: 8 ms, faster than 86.40% of C++ online submissions for Repeated String Match.
//Memory Usage : 6.5 MB, less than 100.00% of C++ online submissions for Repeated String Match.
class Solution {
public:

	int modInverse(int a, int m) {
		int m0 = m;
		int y = 0, x = 1;

		if (m == 1)
			return 0;

		while (a > 1) {
			int q = a / m;
			int t = m;

			m = a % m, a = t;
			t = y;

			y = x - q * y;
			x = t;
		}

		if (x < 0)
			x += m0;

		return x;
	}

	bool check(int index, const string& A, const string& B) {
		for (int i = 0; i < B.length(); ++i)
			if (A[(i + index) % A.length()] != B[i])
				return false;
		return true;
	}

	//void dbg_print(const deque<char>& d) {
	//	copy(begin(d), end(d), ostream_iterator<char>(cout, ""));
	//	cout << endl;
	//}

	int repeatedStringMatch(string A, string B) {
		int q = (B.length() - 1) / A.length() + 1;
		int p = 113, mod = 1000000007;
		int pinv = modInverse(p, mod);

		//deque<char> dbg_a, dbg_b;

		long long bhash = 0, power = 1;
		for (int i = 0; i < B.length(); ++i) {
			bhash += static_cast<long long>(B[i]) * power;
			bhash %= mod;
			power = (power * p) % mod;
			//dbg_b.push_back(B[i]);
		}
		//if (bhash < 0)
		//	bhash += mod;

		long long ahash = 0; power = 1;
		for (int i = 0; i < B.length(); ++i) {
			ahash += static_cast<long long>(A[i % A.length()]) * power;
			ahash %= mod;
			power = (power * p) % mod;
			//dbg_a.push_back(A[i % A.length()]);
		}

		if (ahash == bhash && check(0, A, B))
			return q;

		//cout << "A: " << ahash << endl;
		//cout << "B: " << bhash << endl;

		//dbg_print(dbg_a);
		//dbg_print(dbg_b);

		power = (power * pinv) % mod;

		for (int i = B.length(); i < (q + 1) * A.length(); ++i) {
			ahash -= static_cast<unsigned>(A[(i - B.length()) % A.length()]);
			ahash *= pinv;
			ahash += power * static_cast<unsigned>(A[i % A.length()]);

			//dbg_a.pop_front();
			//dbg_a.push_back(A[i % A.length()]);

			//if (ahash < 0)
			//	ahash += mod;
			ahash %= mod;

			//cout << "A" << i << ": " << ahash << endl;
			//dbg_print(dbg_a);

			if (ahash == bhash && check(i - B.length() + 1, A, B))
				return i < q*A.length() ? q : q + 1;
		}

		return -1;
	}
};

int main()
{
	cout << Solution().repeatedStringMatch("abcd", "cdabcdab") << endl; // 3
    return 0;
}

