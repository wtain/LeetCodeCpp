
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*

// Naive
const int n = height.size();
int result = 0;
for (int i = 0; i < n; ++i)
{
for (int j = i + 1; j < n; ++j)
{
int area = min(height[i], height[j]) * (j - i);
result = max(area, result);
}
}
return result;
*/

class Solution {
public:
	int maxArea(vector<int>& height) 
	{
		int l = 0, r = height.size() - 1;
		int v = min(height[l], height[r]) * (r - l);
		int maxV = v;
		while (l < r)
		{
			if (height[l] < height[r])
			{
				int l0 = l++;
				v -= height[l0];
				v += (min(height[l], height[r]) - height[l0]) * (r - l);
				maxV = max(maxV, v);
			}
			else
			{
				int r0 = r--;
				v -= height[r0];
				v += (min(height[l], height[r]) - height[r0]) * (r - l);
				maxV = max(maxV, v);
			}
		}
		return maxV;
	}
};

int main()
{
	vector<int> arr = { 1,8,6,2,5,4,8,3,7 };
	cout << Solution().maxArea(arr) << endl; // 49

    return 0;
}

