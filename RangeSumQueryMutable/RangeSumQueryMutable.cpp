
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/*

https://leetcode.com/problems/range-sum-query-mutable

Given an integer array nums, find the sum of the elements between indices i and j (i ? j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:

The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.

*/


/*
// sqrt decomposition
class NumArray {
	size_t n;
	size_t ns;
	size_t l;
	vector<int> blocks, vals;
public:
	NumArray(vector<int> nums) : n(nums.size()), vals(nums)
	{
		ns = static_cast<int>(sqrt(n));
		if (!ns)
			return;
		l = ceil((float)n / (float)ns);
		blocks.resize(ns);
		for (int i = 0; i < n; ++i)
			blocks[i / l] += nums[i];
	}

	void update(int i, int val) 
	{
		blocks[i / l] += val - vals[i];
		vals[i] = val;
	}

	int sumRange(int i, int j) 
	{
		int left = i / l;
		int right = j / l;
		int sum = 0;
		if (left == right)
		{
			for (int k = i; k <= j; ++k)
				sum += vals[k];
		}
		else
		{
			for (int k = i; k < (left+1)*l; ++k)
				sum += vals[k];
			for (int b = left + 1; b < right; ++b)
				sum += blocks[b];
			for (int k = right*l; k <= j; ++k)
				sum += vals[k];
		}
		return sum;
	}
};
*/

// Segment Tree
class NumArray {
	size_t n;
	vector<int> tree;
public:
	NumArray(vector<int> nums) : n(nums.size())
	{
		tree.resize(2 * n);
		for (int i = 0; i < n; ++i)
			tree[n + i] = nums[i];
		for (int i = n - 1; i >= 0; --i)
			tree[i] = tree[2 * i] + tree[2 * i + 1];
	}

	void update(int i, int val)
	{
		i += n;
		tree[i] = val;
		while (i > 0)
		{
			int left = i, right = i;
			if (i % 2 == 0)
				right++;
			else
				left--;
			tree[i / 2] = tree[left] + tree[right];
			i /= 2;
		}
	}

	int sumRange(int i, int j)
	{
		i += n;
		j += n;
		int sum = 0;
		while (i <= j)
		{
			if (i % 2 == 1)
			{
				sum += tree[i];
				i++;
			}
			if (j % 2 == 0)
			{
				sum += tree[j];
				j--;
			}
			i /= 2;
			j /= 2;
		}
		return sum;
	}
};

int main()
{
	NumArray obj({ 1, 4, 3, 6, 7, 5, 2, 0, 9 });
	cout << obj.sumRange(3, 5) << endl;
	obj.update(4, 2);
	cout << obj.sumRange(3, 5) << endl;

	//NumArray obj1({ });

	//NumArray obj({ 1, 3, 5 });
	//cout << obj.sumRange(0, 2) << endl; // 9
	//obj.update(1, 2);
	//cout << obj.sumRange(0, 2) << endl; // 8

	/*
	NumArray obj({ 1, 3, 5 });
	cout << obj.sumRange(0, 2) << endl;
	obj.update(1, 2);
	cout << obj.sumRange(0, 2) << endl;
	*/
	
    return 0;
}

