
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		int l = 1;
		while (x / l >= 10 || x / l <= -10)
			l *= 10;
		int r = 1;

		int xl = x, xr = x;

		while (l > r)
		{
			int dl = xl / l;
			xl %= l;
			int dr = xr % 10;
			xr /= 10;
			l /= 10;
			r *= 10;
			if (dl != dr)
				return false;
		}
		return true;
	}
};

int main()
{
	cout << Solution().isPalindrome(10) << endl;

    return 0;
}

