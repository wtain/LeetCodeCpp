
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
https://leetcode.com/problems/pancake-sorting/
Given an array A, we can perform a pancake flip: We choose some positive integer k <= A.length, then reverse the order of the first k elements of A.  We want to perform zero or more pancake flips (doing them one after another in succession) to sort the array A.

Return the k-values corresponding to a sequence of pancake flips that sort A.  Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.



Example 1:

Input: [3,2,4,1]
Output: [4,2,4,3]
Explanation:
We perform 4 pancake flips, with k values 4, 2, 4, and 3.
Starting state: A = [3, 2, 4, 1]
After 1st flip (k=4): A = [1, 4, 2, 3]
After 2nd flip (k=2): A = [4, 1, 2, 3]
After 3rd flip (k=4): A = [3, 2, 1, 4]
After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted.
Example 2:

Input: [1,2,3]
Output: []
Explanation: The input is already sorted, so there is no need to flip anything.
Note that other answers, such as [3, 3], would also be accepted.


Note:

1 <= A.length <= 100
A[i] is a permutation of [1, 2, ..., A.length]
*/

//class Solution {
//public:
//	vector<int> pancakeSort(vector<int>& A) {
//		vector<int> result;
//		const auto n = A.size();
//		int maxi = numeric_limits<int>::max();
//		for (int i = 0; i < n - 1; ++i) {
//			// target position
//			int j = n - 1 - i;
//			// considering 0..j
//			// finding max
//			int maxpos = 0;
//			int maxv = maxi;
//			for (int k = 0; k < n; ++k) {
//				if (maxv >= maxi || A[maxpos] < A[k]) {
//					maxpos = k;
//					maxv = A[k];
//				}
//			}
//			if (maxpos == 0) {
//				result.emplace_back(j+1);
//				continue;
//			}
//			result.emplace_back(maxpos+1);
//			result.emplace_back(j + 1);
//		}
//		return result;
//	}
//};

//Runtime: 8 ms, faster than 70.04% of C++ online submissions for Pancake Sorting.
//Memory Usage : 11.4 MB, less than 30.00% of C++ online submissions for Pancake Sorting.
//class Solution {
//public:
//
//	struct compare {
//		const vector<int>& A;
//
//		explicit compare(const vector<int>& A) : A(A) {
//			
//		}
//
//		bool operator() (const int i, const int j) const {
//			return A[i-1] > A[j-1];
//		}
//	};
//
//	vector<int> pancakeSort(vector<int>& A) {
//		vector<int> result;
//		auto n = A.size();
//		vector<int> B(n);
//
//		for (int i = 0; i < n; ++i)
//			B[i] = i + 1;
//
//		sort(begin(B), end(B), compare(A));
//
//		for (auto i : B) {
//			for (const auto f : result)
//				if (i <= f)
//					i = f + 1 - i;
//			if (i > 1)
//				result.emplace_back(i);
//			if (n > 1)
//				result.emplace_back(n);
//			n--;
//		}
//
//		return result;
//	}
//};

//Runtime: 4 ms, faster than 95.24% of C++ online submissions for Pancake Sorting.
//Memory Usage : 11 MB, less than 100.00% of C++ online submissions for Pancake Sorting.
class Solution {
public:

	struct compare {
		const vector<int>& A;

		explicit compare(const vector<int>& A) : A(A) {

		}

		bool operator() (const int i, const int j) const {
			return A[i - 1] < A[j - 1];
		}
	};

	vector<int> pancakeSort(vector<int>& A) {
		vector<int> result;
		auto n = A.size();
		vector<int> B(n);

		for (int i = 0; i < n; ++i)
			B[i] = i + 1;

		sort(begin(B), end(B), compare(A));

		for (int k = n-1; k >= 0; --k) {
			int i = B[k];
			for (const auto f : result)
				if (i <= f)
					i = f + 1 - i;
			if (i != n) {
				if (i > 1)
					result.emplace_back(i);
				if (n > 1)
					result.emplace_back(n);
			}
			n--;
		}

		return result;
	}
};

void print(const vector<int>& r) {
	copy(begin(r), end(r), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	print(Solution().pancakeSort(vector<int>{3, 2, 4, 1})); // 4,2,4,3
	print(Solution().pancakeSort(vector<int>{1, 2, 3})); // []

    return 0;
}

