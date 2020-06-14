
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <set>
#include <unordered_map>

using namespace std;

/*
https://leetcode.com/problems/fair-candy-swap/
Alice and Bob have candy bars of different sizes: A[i] is the size of the i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of candy that Bob has.

Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both have the same total amount of candy.  (The total amount of candy a person has is the sum of the sizes of candy bars they have.)

Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, and ans[1] is the size of the candy bar that Bob must exchange.

If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.



Example 1:

Input: A = [1,1], B = [2,2]
Output: [1,2]
Example 2:

Input: A = [1,2], B = [2,3]
Output: [1,2]
Example 3:

Input: A = [2], B = [1,3]
Output: [2,3]
Example 4:

Input: A = [1,2,5], B = [2,4]
Output: [5,4]


Note:

1 <= A.length <= 10000
1 <= B.length <= 10000
1 <= A[i] <= 100000
1 <= B[i] <= 100000
It is guaranteed that Alice and Bob have different total amounts of candy.
It is guaranteed there exists an answer.
*/

// TLE
//class Solution {
//public:
//	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
//		const int suma = accumulate(begin(A), end(A), 0);
//		const int sumb = accumulate(begin(B), end(B), 0);
//		const int diff = sumb - suma;
//		const int diff2 = diff / 2;
//		//sort(begin(A), end(A));
//		//sort(begin(B), end(B));
//		for (int i = 0; i < A.size(); ++i) {
//			int targetB = A[i] + diff2;
//			for (int j = 0; j < B.size(); ++j) {
//				if (B[j] == targetB) {
//					return{A[i], B[j]};
//				}
//			}
//		}
//		return{};
//	}
//};

//Runtime: 324 ms, faster than 13.41% of C++ online submissions for Fair Candy Swap.
//Memory Usage : 39.2 MB, less than 68.51% of C++ online submissions for Fair Candy Swap.
//class Solution {
//public:
//
//	vector<int> fairCandySwapImpl(vector<int>& A, vector<int>& B) {
//		const int suma = accumulate(begin(A), end(A), 0);
//		const int sumb = accumulate(begin(B), end(B), 0);
//		const int diff = sumb - suma;
//		const int diff2 = diff / 2;
//		sort(begin(B), end(B));
//		for (int i = 0; i < A.size(); ++i) {
//			int targetB = A[i] + diff2;
//			if (binary_search(begin(B), end(B), targetB))
//				return{ A[i], targetB };
//		}
//		return{};
//	}
//
//	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
//		if (A.size() > B.size()) {
//			const auto r = fairCandySwapImpl(B, A);
//			return{ r[1], r[0] };
//		}
//		return fairCandySwapImpl(A, B);
//	}
//};

//Runtime: 328 ms, faster than 13.05% of C++ online submissions for Fair Candy Swap.
//Memory Usage : 49.5 MB, less than 39.48% of C++ online submissions for Fair Candy Swap.
//Runtime: 256 ms, faster than 25.12% of C++ online submissions for Fair Candy Swap.
//Memory Usage : 49.8 MB, less than 33.34% of C++ online submissions for Fair Candy Swap.
class Solution {
public:

	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		const int suma = accumulate(begin(A), end(A), 0);
		const int sumb = accumulate(begin(B), end(B), 0);
		const int diff = sumb - suma;
		const int diff2 = diff / 2;
		
		unordered_set<int> Bset;
		for (int i = 0; i < B.size(); ++i)
			Bset.emplace(B[i]);

		for (int i = 0; i < A.size(); ++i) {
			int targetB = A[i] + diff2;
			if (Bset.find(targetB) != end(Bset))
				return{ A[i], targetB };
		}
		return{};
	}
};

////Runtime: 376 ms, faster than 8.90% of C++ online submissions for Fair Candy Swap.
////Memory Usage : 50.6 MB, less than 23.05% of C++ online submissions for Fair Candy Swap.
//class Solution {
//public:
//
//	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
//		const int suma = accumulate(begin(A), end(A), 0);
//		const int sumb = accumulate(begin(B), end(B), 0);
//		const int diff = sumb - suma;
//		const int diff2 = diff / 2;
//
//		set<int> Bset;
//		for (int i = 0; i < B.size(); ++i)
//			Bset.emplace(B[i]);
//
//		for (int i = 0; i < A.size(); ++i) {
//			int targetB = A[i] + diff2;
//			if (Bset.find(targetB) != end(Bset))
//				return{ A[i], targetB };
//		}
//		return{};
//	}
//};

void print(const vector<int>& r) {
	cout << r[0] << " " << r[1] << endl;
}

void runTest(initializer_list<int> A, initializer_list<int> B) {
	print(Solution().fairCandySwap(vector<int>(A), vector<int>(B)));
}

int main()
{
	runTest({ 1,1 }, { 2,2 }); // 1 2
	runTest({ 1,2 }, { 2,3 }); // 1 2
	runTest({ 2 }, { 1,3 }); // 2 3
	runTest({ 1,2,5 }, { 2,4 }); // 5 4

    return 0;
}

