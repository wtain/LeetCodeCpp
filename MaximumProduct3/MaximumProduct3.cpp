
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

//class Solution {
//public:
//
//	int maximumProduct(vector<int>& nums) 
//	{
//		vector<int> mins, maxes;
//		for (int i = 0; i < 3; ++i)
//		{
//			if (i < 2)
//				mins.push_back(nums[i]);
//			maxes.push_back(nums[i]);
//		}
//		make_heap(begin(mins), end(mins), less<int>());
//		make_heap(begin(maxes), end(maxes), greater<int>());
//		for (int i = 3; i < nums.size(); ++i)
//		{
//			if (mins[0] > nums[i])
//			{
//				pop_heap(begin(mins), end(mins), less<int>());
//				mins.pop_back();
//				mins.push_back(nums[i]);
//				push_heap(begin(mins), end(mins), less<int>());
//			}
//			if (maxes[0] < nums[i])
//			{
//				pop_heap(begin(maxes), end(maxes), greater<int>());
//				maxes.pop_back();
//				maxes.push_back(nums[i]);
//				push_heap(begin(maxes), end(maxes), greater<int>());
//			}
//		}
//		
//		pop_heap(begin(maxes), end(maxes), greater<int>());
//		int max1 = maxes.back();
//		maxes.pop_back();
//
//		pop_heap(begin(maxes), end(maxes), greater<int>());
//		int max2 = maxes.back();
//		maxes.pop_back();
//
//		pop_heap(begin(maxes), end(maxes), greater<int>());
//		int max3 = maxes.back();
//		maxes.pop_back();
//		
//		pop_heap(begin(mins), end(mins), less<int>());
//		int min1 = mins.back();
//		mins.pop_back();
//
//		pop_heap(begin(mins), end(mins), less<int>());
//		int min2 = mins.back();
//		mins.pop_back();
//
//		int p1 = min1 * min2 * max3;
//		int p2 = max1 * max2 * max3;
//
//		return max(p1, p2);
//	}
//};

class Solution {
public:

	int maximumProduct(vector<int>& nums)
	{
		const int a0 = nums[0];
		int min1 = INT_MAX, min2 = INT_MAX;
		int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] > max1)
			{
				max3 = max2;
				max2 = max1;
				max1 = nums[i];
			}
			else if (nums[i] > max2)
			{
				max3 = max2;
				max2 = nums[i];
			}
			else if (nums[i] > max3)
			{
				max3 = nums[i];
			}
			
			if (nums[i] < min1)
			{
				min2 = min1;
				min1 = nums[i];
			}
			else if (nums[i] < min2)
			{
				min2 = nums[i];
			}
		}
		return max(min1 * min2 * max1, max1*max2*max3);
	}
};

void runTest(vector<int>& arr)
{
	cout << Solution().maximumProduct(arr) << endl;
}

int main()
{
	vector<int> arr1 = { 1, 2, 3 }; // 6
	vector<int> arr2 = { 1, 2, 3, 4 }; // 24
	vector<int> arr3 = { 1, 2, 3, -4 }; // 6
	vector<int> arr4 = { 1, -2, 3, -4 }; // 24
	vector<int> arr5 = { -1, 2, 3, -4 }; // 12
	vector<int> arr6 = { -1, -2, -3 }; // -6

	runTest(arr1);
	runTest(arr2);
	runTest(arr3);
	runTest(arr4);
	runTest(arr5);
	runTest(arr6);

    return 0;
}

