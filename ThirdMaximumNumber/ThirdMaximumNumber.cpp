
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
public:

	class MinHeap
	{
		vector<int> data;
		unordered_set<int> distinct;
		int m;
		int sz;
	public:
		MinHeap(const size_t s)
			: sz(s)
		{

		}

		void Push(int v)
		{
			if (distinct.empty() || m < v)
				m = v;
			auto it = distinct.find(v);
			if (it != end(distinct))
				return;
			distinct.insert(it, v);

			if (data.size() == sz)
			{
				if (data[0] < v)
				{
					pop_heap(begin(data), end(data), greater<int>());
					data.pop_back();
				}
			}
			if (data.size() < sz)
			{
				data.push_back(v);
				push_heap(begin(data), end(data), greater<int>());
			}
		}

		int Min() const
		{
			return distinct.size() >= 3 ? data[0] : m;
		}
	};

	int thirdMax(vector<int>& nums)
	{
		MinHeap heap(3);
		for (int i = 0; i < nums.size(); ++i)
			heap.Push(nums[i]);
		return heap.Min();
	}
};

int main()
{
	vector<int> nums = { 5,2,4,1,3,6,0 };
	cout << Solution().thirdMax(nums) << endl;

    return 0;
}

