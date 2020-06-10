
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Solution {
public:

	vector<int> getDigits(int n)
	{
		vector<int> result(10);
		while (n)
		{
			int d = n % 10;
			++result[d];
			n /= 10;
		}
		return result;
	}

	bool reorderedPowerOf2(int N) 
	{
		const auto nDigs = getDigits(N);
		for (int p = 0; p < 30; ++p)
		{
			int pp = 1 << p;
			const auto ppDigs = getDigits(pp);
			if (nDigs == ppDigs)
				return true;
		}
		return false;
	}
};

int main()
{
	cout << boolalpha << Solution().reorderedPowerOf2(1) << endl; // true
	cout << boolalpha << Solution().reorderedPowerOf2(10) << endl; // false
	cout << boolalpha << Solution().reorderedPowerOf2(16) << endl; // true
	cout << boolalpha << Solution().reorderedPowerOf2(24) << endl; // false
	cout << boolalpha << Solution().reorderedPowerOf2(46) << endl; // true

    return 0;
}

