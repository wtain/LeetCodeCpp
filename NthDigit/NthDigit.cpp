
#include <iostream>

using namespace std;

//class Solution {
//public:
//	
//	int getDigit(int value, int dig, int p)
//	{
//		for (int i = 0; i < dig; ++i)
//		{
//			value %= p;
//			p /= 10;
//		}
//		return value / p;
//	}
//
//	int findNthDigit(int n) 
//	{
//		int si = 1;
//		int ei = 9;
//		int nDigits = 1;
//		int p = 10;
//		while (n > ei)
//		{
//			++nDigits;
//			si = ei + 1;
//			ei = si + 9 * nDigits * p;
//			p *= 10;
//		}
//		n -= si;
//		int m = n / nDigits;
//		int dig = n % nDigits;
//		p /= 10;
//		int value = p + m;
//		return getDigit(value, dig, p);
//	}
//};

class Solution {
public:

	int findNthDigit(int n)
	{
		--n;
		int start = 1;
		int size = 1;
		while (n / 9 / size >= start)
		{
			n -= 9 * start * size;
			start *= 10;
			++size;
		}

		int number = start + n / size;
		for (int i = n % size; i < size - 1; ++i)
		{
			number /= 10;
		}
		return number % 10;
	}
};

int main()
{
	cout << Solution().findNthDigit(3) << endl; // 3
	cout << Solution().findNthDigit(11) << endl; // 0
	cout << Solution().findNthDigit(12) << endl; // 1
	cout << Solution().findNthDigit(2700) << endl; // 6 X
	cout << Solution().findNthDigit(900) << endl; // 6 X
	cout << Solution().findNthDigit(100) << endl; // 5
	cout << Solution().findNthDigit(200) << endl; // 0 X

	cout << Solution().findNthDigit(190) << endl; // 1
	//cout << Solution().findNthDigit(191) << endl; // 0 // X

	/*for (int i = 186; i <= 191; ++i)
		cout << Solution().findNthDigit(i);*/

	/*for (int i = 1; i <= 200; ++i)
		cout << Solution().findNthDigit(i);*/

    return 0;
}

