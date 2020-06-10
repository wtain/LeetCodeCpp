
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

/*
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
[ 1,  5,  9],
[10, 11, 13],
[12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ? k ? n2.
*/

//class Solution {
//public:
//	int kthSmallest(vector<vector<int>>& matrix, int k) {
//		int n = matrix.size();
//		int m = matrix[0].size();
//		return matrix[(k - 1) / n][(k - 1) % n];
//	}
//};

//class Solution {
//public:
//	int kthSmallest(vector<vector<int>>& matrix, int k) {
//		int n = matrix.size();
//		int m = matrix[0].size();
//		
//		int i = 0, j = 0;
//		--k;
//
//		while (--k) {
//			
//		}
//
//		return matrix[i][j];
//	}
//};


// NAIVE - n*m*log(k)
//Runtime: 128 ms, faster than 23.51% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
//Memory Usage : 14.4 MB, less than 9.09% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
//class Solution {
//public:
//	int kthSmallest(vector<vector<int>>& matrix, int k) {
//		int n = matrix.size();
//		int m = matrix[0].size();
//		priority_queue<int> numbers;
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < m; ++j) {
//				numbers.push(matrix[i][j]);
//				if (numbers.size() > k)
//					numbers.pop();
//			}
//		}
//		return numbers.top();
//	}
//};

//Runtime: 144 ms, faster than 15.26% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
//Memory Usage : 13.4 MB, less than 31.82% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
// k * log(n)
class Solution {
public:

	struct Sequence {
		const vector<int>* v;
		size_t it;

		explicit Sequence(const vector<int>& v) : v(&v), it(0) {

		}

		bool hasValue() const {
			return it < v->size();
		}

		int value() const { return (*v)[it]; }

		void advance() { ++it; }

		bool operator< (const Sequence& other) const {
			if (!hasValue())
				return false;
			if (!other.hasValue())
				return true;
			return value() < other.value();
		}

		bool operator> (const Sequence& other) const {
			return other < *this;
		}
	};

	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int m = matrix[0].size();
		
		priority_queue<Sequence, vector<Sequence>, greater<Sequence>> iterators;

		for (int i = 0; i < n; ++i)
			iterators.emplace(Sequence(matrix[i]));

		for (int p = 1; p < k; ++p) {
			auto seq = iterators.top(); iterators.pop();
			seq.advance();
			if (seq.hasValue())
				iterators.push(seq);
		}
		return iterators.top().value();
	}
};

int main()
{
	cout << Solution().kthSmallest(
		vector<vector<int>>
	{
		{  1,  5,  9},
		{ 10, 11, 13 },
		{ 12, 13, 15 }
	}, 8) << endl; // 13

	cout << Solution().kthSmallest(
		vector<vector<int>>
	{
		{  1, 5, 9},
		{ 10, 11, 13 },
		{ 12, 13, 15 }
	}, 1) << endl; // 1

	cout << Solution().kthSmallest(
		vector<vector<int>>
	{
		{  1, 5, 9},
		{ 10, 11, 13 },
		{ 12, 13, 15 }
	}, 9) << endl; // 15

	cout << Solution().kthSmallest(
		vector<vector<int>>
	{
		{ 1, 2 },
		{ 1, 3 }
	}, 2) << endl; // 1

    return 0;
}

