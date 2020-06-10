
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	
	int nthUglyNumber(int n) 
	{
		vector<int> values;
		int i = 0, j = 0, k = 0;
		values.push_back(1);
		while (--n)
		{
			int next = min(values[i]*2, min(values[j]*3, values[k]*5));
			if (next == values[i] * 2) ++i;
			if (next == values[j] * 3) ++j;
			if (next == values[k] * 5) ++k;
			values.push_back(next);
		}
		return values.back();
	}
};

int main()
{
	cout << boolalpha << Solution().nthUglyNumber(10) << endl;

	return 0;
}

