
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

//class Solution {
//public:
//
//	int findKthElement(int k, vector<int>& nums1, vector<int>& nums2, int s1, int s2)
//	{
//		cout << k << " " << s1 << " " << s2 << endl;
//		if (s1 >= nums1.size())
//			return nums2[s2 + k];
//		if (s2 >= nums2.size())
//			return nums1[s1 + k];
//
//		if (!k)
//			return min(nums1[s1], nums2[s2]);
//
//		int k2 = k >> 1;
//
//		int m1 = s1 + k2;
//		int m2 = s2 + k2;
//
//		if (m1 >= nums1.size())
//			return findKthElement(k - nums1.size(), nums1, nums2, m1, s2 + nums1.size());
//
//		if (m2 >= nums2.size())
//			return findKthElement(k - nums2.size(), nums1, nums2, s1 + nums2.size(), m2);
//
//		int Med1 = m1 < nums1.size() ? nums1[m1] : numeric_limits<int>::max();
//		int Med2 = m2 < nums2.size() ? nums2[m2] : numeric_limits<int>::max();
//
//		if (Med1 < Med2)
//			return findKthElement(k - k2-1, nums1, nums2, m1 + 1, s2);
//		if (Med1 == Med2)
//			return findKthElement(k - k2-1, nums1, nums2, m1, m2);
//		return findKthElement(k - k2-1, nums1, nums2, s1, m2 + 1);
//	}
//
//	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//		int n = nums1.size() + nums2.size();
//		int n2 = n >> 1;
//		if (n & 1)
//			return findKthElement(n2, nums1, nums2, 0, 0);
//		return (findKthElement(n2, nums1, nums2, 0, 0) + findKthElement(n2 - 1, nums1, nums2, 0, 0)) / 2.0;
//	}
//};


class Solution {
public:

	int findKthElement(vector<int>& nums1, vector<int>& nums2, int k, int b1, int e1, int b2, int e2)
	{
		int len1 = e1 - b1 + 1;
		int len2 = e2 - b2 + 1;

		if (!len1)
			return nums2[b2 + k];

		if (!len2)
			return nums1[b1 + k];

		if (!k)
			return min(nums1[b1], nums2[b2]);

		int mid1 = len1 * k / (len1 + len2);
		int mid2 = k - mid1 - 1;

		mid1 += b1;
		mid2 += b2;

		if (nums1[mid1] > nums2[mid2])
		{
			k -= mid2 - b2 + 1;
			e1 = mid1;
			b2 = mid2 + 1;
		}
		else
		{
			k -= mid1 - b1 + 1;
			e2 = mid2;
			b1 = mid1 + 1;
		}
		return findKthElement(nums1, nums2, k, b1, e1, b2, e2);
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size() + nums2.size();
		int n2 = n >> 1;
		if (n & 1)
			return findKthElement(nums1, nums2, n2, 0, nums1.size() - 1, 0, nums2.size() - 1);
		return (findKthElement(nums1, nums2, n2, 0, nums1.size() - 1, 0, nums2.size() - 1) + findKthElement(nums1, nums2, n2-1, 0, nums1.size() - 1, 0, nums2.size() - 1)) / 2.0;
	}
};

int main()
{
	/*vector<int> v1 = { 1, 3 };
	vector<int> v2 = { 2 };*/
	/*vector<int> v1 = { 1, 2 };
	vector<int> v2 = { 3, 4 };*/
	/*vector<int> v1 = { 1, 2 };
	vector<int> v2 = { 1, 2 };*/

	vector<int> v1 = { 1 };
	vector<int> v2 = { 2, 3, 4 };

	cout << Solution().findMedianSortedArrays(v1, v2) << endl;

    return 0;
}

