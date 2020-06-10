
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Given an array of 0/1. Return the longest contiguous sequence of ones 
which can be obtained after one zero removal.
*/

int longestContiguousSequenceOfOnes(const vector<int>& v)
{
	int maxL = 0;
	int prev = 0;
	int curr = 0;
	const int n = v.size();

	for (int i = 0; i < n; ++i)
	{
		if (v[i] == 1)
		{
			++curr;
			maxL = max(maxL, curr + prev);
		}
		else
		{
			prev = curr;
			curr = 0;
		}
	}
	return maxL;
}

int main()
{
	vector<int> v1 = { 0, 1, 1, 0, 1, 1, 0, 1 }; // 4
	vector<int> v2 = { 0, 1, 1, 0, 1, 1, 0, 1, 0 }; // 4
	vector<int> v3 = { 0, 1, 1, 1, 1, 1, 0, 1, 0 }; // 6
	vector<int> v4 = { 0, 1, 0, 1, 1, 1, 0, 1, 1 }; // 5
	vector<int> v5 = { 0, 1, 0, 1, 1, 1, 0, 0, 1, 1 }; // 4
	vector<int> v6 = { 0, 1, 0, 1, 1, 1, 1, 0, 1, 1 }; // 6

	cout << longestContiguousSequenceOfOnes(v1) << endl;
	cout << longestContiguousSequenceOfOnes(v2) << endl;
	cout << longestContiguousSequenceOfOnes(v3) << endl;
	cout << longestContiguousSequenceOfOnes(v4) << endl;
	cout << longestContiguousSequenceOfOnes(v5) << endl;
	cout << longestContiguousSequenceOfOnes(v6) << endl;

    return 0;
}

