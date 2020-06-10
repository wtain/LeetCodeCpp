
#include <iostream>

class Solution {
public:

	int reversePositive(int x)
	{
		int rv = 0;
		const int mx = ((1 << 31) -1) / 10;
		while (x)
		{
			if (rv > mx)
				return 0;
			rv *= 10;
			rv += x % 10;
			x /= 10;
		}
		return rv;
	}

	int reverse(int x) {
		if (x < 0)
		{
			if (x == -x)
				return 0;
			return -reversePositive(-x);
		}
		else
			return reversePositive(x);
	}
};

int main()
{
	Solution s;
	std::cout << s.reverse(-2147483648) << std::endl;

    return 0;
}

