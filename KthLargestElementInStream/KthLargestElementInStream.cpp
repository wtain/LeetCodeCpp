
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class KthLargest {
	vector<int> maxes;
	int K;
public:
	KthLargest(int k, vector<int> nums) 
		: K(k)
	{
		for (auto v : nums)
			add(v);
	}

	int add(int val) 
	{
		if (maxes.size() == K)
		{
			if (maxes[0] < val)
			{
				pop_heap(begin(maxes), end(maxes), greater<int>());
				maxes[K - 1] = val;
				push_heap(begin(maxes), end(maxes), greater<int>());
			}
		}
		else
		{
			maxes.push_back(val);
			push_heap(begin(maxes), end(maxes), greater<int>());
		}
		return maxes[0];
	}
};

int main()
{
	int k = 3;
	vector<int> arr = { 4, 5, 8, 2 };
	KthLargest kthLargest (3, arr);
	cout << kthLargest.add(3) << endl;   // returns 4
	cout << kthLargest.add(5) << endl;   // returns 5
	cout << kthLargest.add(10) << endl;  // returns 5
	cout << kthLargest.add(9) << endl;   // returns 8
	cout << kthLargest.add(4) << endl;   // returns 8
    return 0;
}

