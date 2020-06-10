
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (!n)
			return 1.0;
		if (x == 1.0)
			return 1.0;
		if (n < 0)
		{
			if (n == numeric_limits<int>::min())
				return myPow(x, n+1)/x;
			n = -n;
			x = 1.0 / x;
		}

		int d = 1 << 30;
		int p = 30;
		while (d > n)
		{
			d >>= 1;
			--p;
		}

		vector<double> powers(32);
		powers[0] = x;
		for (int i = 1; i <= p; ++i)
			powers[i] = powers[i - 1] * powers[i - 1];

		double r = 1.0;

		while (n)
		{
			int dig = n / d;
			n %= d;

			if (dig)
				r *= powers[p];

			d >>= 1;
			p--;
		}

		return r;
	}
};

int main()
{
	//cout << Solution().myPow(34.0515, -3) << endl;
	//cout << Solution().myPow(0.00001, 2147483647) << endl;
	//cout << Solution().myPow(2.0, 10) << endl;
	//cout << Solution().myPow(1.0, -2147483648) << endl;
	

    return 0;
}

