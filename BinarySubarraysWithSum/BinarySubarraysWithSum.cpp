
#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include <unordered_map>

using namespace std;

/*
https://leetcode.com/problems/binary-subarrays-with-sum/

In an array A of 0s and 1s, how many non-empty subarrays have sum S?



Example 1:

Input: A = [1,0,1,0,1], S = 2
Output: 4
Explanation:
The 4 subarrays are bolded below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]


Note:

A.length <= 30000
0 <= S <= A.length
A[i] is either 0 or 1.
*/

//class Solution {
//public:
//	int numSubarraysWithSum(vector<int>& A, int S) {
//		int cnt = 0;
//		const size_t n = A.size();
//		size_t i1 = 0;
//		size_t i2 = 0;
//		int currentSum = 0;
//		while (i1 < n) {
//			if (i2 < n && currentSum <= S)
//				currentSum += A[i2++];
//			if (currentSum == S)
//				++cnt;
//			if (i1 <= i2 && currentSum >= S)
//				currentSum -= A[i1++];
//			if (currentSum == S)
//				++cnt;
//		}
//
//		return cnt;
//	}
//};

// ACCEPTED
//class Solution {
//public:
//	int numSubarraysWithSum(vector<int>& A, int S) {
//		const size_t n = A.size();
//		int sum = accumulate(begin(A), end(A), 0);
//		vector<int> index(sum + 2);
//		int t = 0;
//		index[t++] = -1;
//		for (int i = 0; i < n; ++i)
//			if (A[i])
//				index[t++] = i;
//		index[t] = n;
//
//		int result = 0;
//		if (!S) {
//			for (int i = 0; i < index.size() - 1; ++i) {
//				int si = index[i + 1] - index[i] - 1;
//				result += si * (si + 1) / 2;
//			}
//			return result;
//		}
//
//		for (int i = 1; i < index.size() - S; ++i) {
//			int j = i + S - 1;
//			int left = index[i] - index[i - 1];
//			int right = index[j + 1] - index[j];
//			result += left * right;
//		}
//
//		return result;
//	}
//};

// ACCEPTED
//class Solution {
//public:
//	int numSubarraysWithSum(vector<int>& A, int S) {
//		const size_t n = A.size();
//		vector<int> ps;
//		ps.reserve(n + 1);
//		ps.push_back(0);
//		partial_sum(begin(A), end(A), back_inserter(ps));
//
//		int result = 0;
//
//		unordered_map<int, int> counts;
//		for (int i = 0; i < n+1; ++i) {
//			result += counts[ps[i]];
//			++counts[ps[i] + S];
//		}
//
//		return result;
//	}
//};

class Solution {
public:
	int numSubarraysWithSum(vector<int>& A, int S) {
		const size_t n = A.size();
		
		int result = 0;

		int ilo = 0, ihi = 0;
		int sumlo = 0, sumhi = 0;
		for (int j = 0; j < n; ++j) {
			sumlo += A[j];
			while (ilo < j && sumlo > S)
				sumlo -= A[ilo++];

			sumhi += A[j];
			while (ihi < j && (sumhi > S || sumhi == S && A[ihi] == 0))
				sumhi -= A[ihi++];

			if (sumlo == S)
				result += ihi - ilo + 1;
		}

		return result;
	}
};

int main()
{
	cout << Solution().numSubarraysWithSum(vector<int>{1, 0, 1, 0, 1}, 2) << endl; // 4
	cout << Solution().numSubarraysWithSum(vector<int>{1, 0, 0, 1, 0, 1}, 2) << endl; // 5
    return 0;
}

