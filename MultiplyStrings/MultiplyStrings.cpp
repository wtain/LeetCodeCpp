
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2)
	{
		string result(num1.length() + num2.length(), '0');
		for (int i = 0; i < num1.length(); ++i)
		{
			int i1 = num1.length() - 1 - i;
			int carry = 0;
			string result1(num2.length() + 1, '0');
			int d1 = num1[i1] - '0';
			for (int j = 0; j < num2.length(); ++j)
			{
				int j1 = num2.length() - 1 - j;

				int d2 = num2[j1] - '0';
				int dr = carry + d1*d2;
				carry = dr / 10;
				dr %= 10;
				result1[j1 + 1] = '0' + dr;
			}
			result1[0] = '0' + carry;
			carry = 0;
			for (int j = 0; j < result1.length(); ++j)
			{
				int j1 = result1.length() - 1 - j;
				int i2 = result.length() - 1 - j - i;

				int d1 = result[i2] - '0';
				int d2 = result1[j1] - '0';
				int dr = d1 + d2 + carry;
				carry = dr / 10;
				dr %= 10;
				result[i2] = '0' + dr;
			}
			result[0] = result[0] + carry;
		}
		const size_t pos = result.find_first_not_of('0');
		if (pos != string::npos)
			result.erase(0, pos);
		else
			result = "0";
		return result;
	}
};

int main()
{
	cout << Solution().multiply("11", "11") << endl;
	cout << Solution().multiply("123", "456") << endl;
	cout << Solution().multiply("0", "0") << endl;
	cout << Solution().multiply("0", "10000") << endl;
	cout << Solution().multiply("100000", "10000") << endl;
	cout << Solution().multiply("100000", "0") << endl;

    return 0;
}

