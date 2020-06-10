
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
https://leetcode.com/problems/global-and-local-inversions/

We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.

The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].

The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].

Return true if and only if the number of global inversions is equal to the number of local inversions.

Example 1:

Input: A = [1,0,2]
Output: true
Explanation: There is 1 global inversion, and 1 local inversion.
Example 2:

Input: A = [1,2,0]
Output: false
Explanation: There are 2 global inversions, and 1 local inversion.
Note:

A will be a permutation of [0, 1, ..., A.length - 1].
A will have length in range [1, 5000].
The time limit for this problem has been reduced.

*/

// More complex one is solved here...
//class Solution {
//public:
//
//	int countLocalPermutations(const vector<int>& A)
//	{
//		const int N = A.size();
//		int nLocal = 0;
//		for (int i = 1; i < N; ++i)
//		{
//			if (A[i] < A[i - 1])
//				++nLocal;
//		}
//		return nLocal;
//	}
//
//	struct Node
//	{
//		int rangeMin, rangeMax;
//		int value;
//		Node *left, *right;
//
//		Node(int vmin, int vmax)
//			: rangeMin(vmin)
//			, rangeMax(vmax)
//			, value(0)
//			, left(nullptr)
//			, right(nullptr)
//		{
//
//		}
//
//		int getMid() const
//		{
//			return rangeMin + (rangeMax - rangeMin) / 2;
//		}
//
//		Node* getLeft()
//		{
//			if (!left)
//				left = new Node(rangeMin, getMid());
//			return left;
//		}
//
//		Node* getRight()
//		{
//			if (!right)
//				right = new Node(getMid() + 1, rangeMax);
//			return right;
//		}
//	};
//
//	void insert(Node* root, int value)
//	{
//		if (root->rangeMin == root->rangeMax)
//		{
//			++root->value;
//			return;
//		}
//		if (value <= root->getMid())
//			insert(root->getLeft(), value);
//		else
//			insert(root->getRight(), value);
//		root->value = root->getLeft()->value + root->getRight()->value;
//	}
//
//	int count(Node* root, int value)
//	{
//		/*if (root->rangeMin == root->rangeMax)
//			return (root->rangeMin > value) ? 1 : 0;*/
//		if (root->rangeMax <= value)
//			return 0;
//		if (root->rangeMin > value)
//			return root->value;
//		return count(root->getLeft(), value) + count(root->getRight(), value);
//	}
//
//	int countGlobalPermutations(const vector<int>& A)
//	{
//		if (A.empty())
//			return 0;
//		int result = 0;
//		auto p = minmax_element(begin(A), end(A));
//		Node* root = new Node(*p.first, *p.second);
//		for (auto a : A)
//		{
//			result += count(root, a);
//			insert(root, a);
//		}
//		return result;
//	}
//
//	bool isIdealPermutation(vector<int>& A) 
//	{
//		const int nLocal = countLocalPermutations(A);
//		const int nGlobal = countGlobalPermutations(A);
//		return nGlobal == nLocal;
//	}
//};

class Solution {
public:

	bool isIdealPermutation(vector<int>& A)
	{
		const int N = A.size();
		for (int i = 0; i < N; ++i)
		{
			if (abs(i - A[i]) > 1)
				return false;
		}
		return true;
	}
};

int main()
{
	vector<int> v1 = { 1,0,2 };
	vector<int> v2 = { 1,2,0 };

	/*vector<int> v3 = { 1,3,5,4,7 };
	vector<int> v4 = { 2,2,2,2,2 };
	vector<int> v5 = { 1, 2, 4, 3, 5, 4, 7, 2 };
	vector<int> v6;
	vector<int> v7 = { 2, 1 };*/

	vector<int> v3 = { 0,1,3,2,4 };
	vector<int> v4 = { 0 };
	vector<int> v5 = { 0, 1, 3, 2, 4, 5 };
	vector<int> v6;
	vector<int> v7 = { 1, 0 };
	vector<int> v8 = { 0, 2, 1 };

	cout << boolalpha << Solution().isIdealPermutation(v1) << endl; // true
	cout << boolalpha << Solution().isIdealPermutation(v2) << endl; // false

	cout << boolalpha << Solution().isIdealPermutation(v3) << endl; // true 
	cout << boolalpha << Solution().isIdealPermutation(v4) << endl; // true
	cout << boolalpha << Solution().isIdealPermutation(v5) << endl; // true
	cout << boolalpha << Solution().isIdealPermutation(v6) << endl; // true
	cout << boolalpha << Solution().isIdealPermutation(v7) << endl; // true
	cout << boolalpha << Solution().isIdealPermutation(v8) << endl; // true

    return 0;
}

