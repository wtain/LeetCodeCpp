
#include <iostream>
#include <vector>
#include <unordered_set>
#include <iomanip>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {

	int changeBit(int v, int bit)
	{
		int mask = 1 << bit;
		int maskI = ~mask;

		return v & maskI | ~(v & mask) & mask;
	}

public:

	vector<int> grayCode(int n) 
	{
		vector<int> result;
		unordered_set<int> used;
		int v = 0;
		used.insert(v);
		do
		{
			//cout << setbase(2) << v << endl;
			result.push_back(v);
			int v1 = 0;
			for (int i = 0; i < n; ++i)
			{
				v1 = changeBit(v, i);
				auto it = used.find(v1);
				if (used.end() == it)
				{
					used.insert(it, v1);
					break;
				}
			}
			v = v1;
		} while (v);
		return result;
	}
};

int main()
{
	auto v = Solution().grayCode(3);
	copy(begin(v), end(v), ostream_iterator<int>(cout, ", "));
	cout << endl;

    return 0;
}

