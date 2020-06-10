
#include <iostream>
#include <iomanip>

using namespace std;

class Solution {
public:
	bool isUgly(int num) 
	{
		if (num < 0)
			return false;
		while (num > 1)
		{
			int num1 = num;
			if (num % 2 == 0)
				num /= 2;
			if (num % 3 == 0)
				num /= 3;
			if (num % 5 == 0)
				num /= 5;
			if (num1 == num)
				break;
		}
		return num == 1;
	}
};

int main()
{
	cout << boolalpha << Solution().isUgly(6) << endl;
	cout << boolalpha << Solution().isUgly(14) << endl;
	cout << boolalpha << Solution().isUgly(-6) << endl;
	cout << boolalpha << Solution().isUgly(-14) << endl;
	cout << boolalpha << Solution().isUgly(INT_MAX) << endl;
	cout << boolalpha << Solution().isUgly(INT_MIN) << endl;

    return 0;
}

