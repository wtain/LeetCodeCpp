
#include <vector>
#include <iostream>

int SearchSeam(const std::vector<int>& vec)
{
	int N = vec.size();
	int l = 0, r = N - 1;

	if (vec[l] <= vec[r])
		return -1;

	while (r - l > 1)
	{
		size_t m = (l + r) / 2;
		// l..m
		// m..r
		if (vec[l] > vec[m])
			r = m;
		else if (vec[m] > vec[r])
			l = m;
	}
	return r;
}

int BinarySearch(const std::vector<int>& vec, int l, int r, int val)
{
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (vec[m] == val)
			return m;
		else if (vec[m] < val)
			l = m + 1; 
		else if (vec[m] >= val)
			r = m - 1;
	}
	if (l == r && vec[l] == val)
		return l;
	return -1;
}

int SearchRotated(const std::vector<int>& vec, int val)
{
	int s = SearchSeam(vec);
	int N = vec.size();
	if (-1 == s)
		return BinarySearch(vec, 0, N - 1, val);

	if (vec[0] <= val)
		return BinarySearch(vec, 0, s - 1, val);
	return BinarySearch(vec, s, N - 1, val);
}

int SearchRotated2Impl(const std::vector<int>& a, int x, int l, int u)
{
	while (l <= u)
	{
		int m = l + (u - l) / 2;
		if (a[m] == x)
			return m;
		else if (a[l] <= a[m])
		{
			if (a[m] < x)
				l = m + 1;
			else if (a[l] <= x)
				u = m - 1;
			else
				l = m + 1;
		}
		else if (x < a[m])
			u = m - 1;
		else if (x <= a[u])
			l = m + 1;
		else
			u = m - 1;

	}
	return -1;
}

int SearchRotated2(const std::vector<int>& vec, int val)
{
	return SearchRotated2Impl(vec, val, 0, vec.size() - 1);
}
using namespace std;
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int b = 0, e = nums.size() - 1;
		while (b <= e)
		{
			size_t n = e - b;
			size_t m = b + (n >> 1);
			if (nums[m] == target)
				return m;
			else if (nums[b] <= nums[m])
			{
				if (target > nums[m])
				{
					b = m + 1;
				}
				else if (target >= nums[b])
				{
					e = m - 1;
				}
				else
				{
					b = m + 1;
				}
			}
			else if (target < nums[m])
			{
				e = m - 1;
			}
			else if (target <= nums[e])
			{
				b = m + 1;
			}
			else
			{
				e = m - 1;
			}
		}
		return -1;
	}
};

int main()
{
	/*
	//                       0   1   2   3   4  5  6  7  8  9  10  11
	std::vector<int> v  = { 15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14 };
	std::vector<int> v1 = {  2,  2,  2,  2,  2, 2, 2, 2, 2, 2,  2,  2 };

	std::cout << "  5: " << SearchRotated(v, 5) << std::endl; // 8
	std::cout << "  0: " << SearchRotated(v, 0) << std::endl; // -1
	std::cout << "100: " << SearchRotated(v, 100) << std::endl; // -1
	std::cout << "  2: " << SearchRotated(v, 2) << std::endl; // -1
	std::cout << " 15: " << SearchRotated(v, 15) << std::endl; // 0

	std::cout << std::endl;

	std::cout << "  5: " << SearchRotated2(v, 5) << std::endl; // 8
	std::cout << "  0: " << SearchRotated2(v, 0) << std::endl; // -1
	std::cout << "100: " << SearchRotated2(v, 100) << std::endl; // -1
	std::cout << "  2: " << SearchRotated2(v, 2) << std::endl; // -1
	std::cout << " 15: " << SearchRotated2(v, 15) << std::endl; // 0

	std::cout << std::endl;

	std::cout << "  1: " << SearchRotated(v1, 1) << std::endl;
	std::cout << "  2: " << SearchRotated(v1, 2) << std::endl;
	std::cout << "  3: " << SearchRotated(v1, 3) << std::endl;

	std::cout << std::endl;

	std::cout << "  1: " << SearchRotated2(v1, 1) << std::endl;
	std::cout << "  2: " << SearchRotated2(v1, 2) << std::endl;
	std::cout << "  3: " << SearchRotated2(v1, 3) << std::endl;
	*/

	vector<int> v = { 5, 1, 3 };
	cout << Solution().search(v, 3) << endl;

    return 0;
}

