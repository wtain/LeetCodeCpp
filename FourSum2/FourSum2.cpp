
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

/*

https://leetcode.com/problems/4sum-ii

Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) 
there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ? N ? 500. 
All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

//class Solution {
//public:
//
//	struct Value
//	{
//		int v;
//		int arr;
//
//		Value(int val, int arrid)
//			: v(val)
//			, arr(arrid)
//		{
//
//		}
//
//		struct Compare
//		{
//			bool operator() (const Value& v1, const Value& v2) const
//			{
//				return v1.v < v1.v;
//			}
//		};
//	};
//
//	vector<Value> BuildArray(const vector<int>& A, const int arrid)
//	{
//		vector<Value> result;
//		result.reserve(A.size());
//		for (int ai : A)
//			result.push_back(Value(ai, arrid));
//		return result;
//	}
//
//	struct ArrayRef
//	{
//		const vector<Value>* Arr;
//		int index;
//
//		explicit ArrayRef(const vector<Value>& arr)
//			: Arr(&arr), index(0) {}
//
//		bool Passed() const
//		{
//			return index == Arr->size();
//		}
//
//		void MoveNext()
//		{
//			++index;
//		}
//
//		const Value& Val() const
//		{
//			return (*Arr)[index];
//		}
//
//		struct Compare
//		{
//			bool operator() (const ArrayRef& a1, const ArrayRef& a2) const
//			{
//				return a1.Val().v > a2.Val().v;
//			}
//		};
//	};
//
//	const vector<Value> Merge(const vector<vector<Value>>& Arrays)
//	{
//		priority_queue<ArrayRef, vector<ArrayRef>, ArrayRef::Compare> heap;
//		for (const auto& arr : Arrays)
//			heap.emplace(arr);
//
//		vector<Value> result;
//		result.reserve(Arrays.size() * Arrays[0].size());
//
//		while (!heap.empty())
//		{
//			ArrayRef a = heap.top();
//			heap.pop();
//
//			result.push_back(a.Val());
//			a.MoveNext();
//			if (!a.Passed())
//				heap.push(a);
//		}
//
//		return result;
//	}
//
//	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
//	{
//		sort(begin(A), end(A));
//		sort(begin(B), end(B));
//		sort(begin(C), end(C));
//		sort(begin(D), end(D));
//
//		vector<vector<Value>> Arrays =
//		{
//			BuildArray(A, 1),
//			BuildArray(B, 2),
//			BuildArray(C, 3),
//			BuildArray(D, 4)
//		};
//
//		const vector<Value> Arr = Merge(Arrays);
//
//		return fourSumCountImpl(Arr);
//	}
//
//	int fourSumCountImpl(const vector<Value>& nums)
//	{
//		int result = 0;
//		const int n = nums.size();
//
//		for (int i = 0; i < n - 3; ++i)
//		{
//			if (nums[i].v * 4 > 0)
//				return result;
//			for (int j = n - 1; j > i + 2; --j)
//			{
//				if (nums[j].v * 4 < 0)
//					break;
//				int lo = i + 1, hi = j - 1;
//				int t = - nums[i].v - nums[j].v;
//				while (lo < hi)
//				{
//					int s = nums[lo].v + nums[hi].v;
//					if (s < t)
//						++lo;
//					else if (s > t)
//						--hi;
//					else
//					{
//						if (nums[i].arr + nums[lo].arr + nums[hi].arr + nums[j].arr == 1 + 2 + 3 + 4)
//						{
//							++result;
//						}
//						while (++lo < hi && nums[lo - 1].v == nums[lo].v && nums[lo - 1].arr == nums[lo].arr);
//						while (lo < --hi && nums[hi + 1].v == nums[hi].v && nums[hi + 1].arr == nums[hi].arr);
//					}
//				}
//				while (j > i + 2 && nums[j - 1].v == nums[j].v) --j;
//			}
//			while (i < n - 3 && nums[i + 1].v == nums[i].v) ++i;
//		}
//
//		return result;
//	}
//};

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
	{
		int result = 0;
		unordered_map<int, int> countsab;
		for (auto a : A)
		{
			for (auto b : B)
			{
				++countsab[a + b];
			}
		}
		for (auto c : C)
		{
			for (auto d : D)
			{
				const int target = -c - d;
				auto it = countsab.find(target);
				if (it != end(countsab))
					result += it->second;
			}
		}
		return result;
	}
};

int main()
{
	vector<int>
		A = {  1,  2 },
		B = { -2, -1 },
		C = { -1,  2 },
		D = {  0,  2 };

	cout << Solution().fourSumCount(A, B, C, D) << endl;

    return 0;
}

