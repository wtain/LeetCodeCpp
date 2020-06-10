
#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Solution {
public:

	string toHexImpl(unsigned num)
	{
		static string digits = "0123456789abcdef";
		string result;
		while (num > 0)
		{
			int d = num % 16;
			num /= 16;
			result = digits[d] + result;
		}
		return result;
	}

	string toHex(int num) 
	{
		if (!num)
			return "0";
		if (num > 0)
			return toHexImpl(num);
		else
			return toHexImpl(0xFFFFFFFF+num+1);
	}
};

int main()
{
	cout << Solution().toHex(26) << endl; // 1a
	cout << Solution().toHex(1) << endl; // 1
	cout << Solution().toHex(16) << endl; // 10
	cout << Solution().toHex(32) << endl; // 20
	cout << Solution().toHex(-1) << endl; // ffffffff
	cout << Solution().toHex(-16) << endl; // fffffff0
	cout << Solution().toHex(-32) << endl; // ffffffe0
	cout << Solution().toHex(0) << endl; // 0
	cout << Solution().toHex(numeric_limits<int>::max()) << endl; // 7fffffff
	cout << Solution().toHex(numeric_limits<int>::min()) << endl; // 80000000

    return 0;
}

