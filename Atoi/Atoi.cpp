
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {

		if (str.empty())
			return 0;

		int i = 0;
		while (isspace(str[i]) && i < str.size())
			++i;

		if (i == str.size())
			return 0;

		int sign = 1;
		if (str[i] == '-')
		{
			sign = -1;
			++i;
		}
		else if (str[i] == '+')
			++i;

		if (i == str.size())
			return 0;

		if (!isdigit(str[i]))
			return 0;

		int rv = 0;
		while (i < str.size() && isdigit(str[i]))
		{
			if (rv >= 214748364 && (str[i] - '0') > 7 || rv > 214748365)
				return INT_MAX;
			else if (rv <= -214748364 && (str[i] - '0') > 8 || rv < -214748365)
				return INT_MIN;
			rv *= 10;
			if (sign > 0)
				rv += str[i] - '0';
			else
				rv -= str[i] - '0';
			++i;
		}
		return rv;
	}
};

int main()
{
	cout << Solution().myAtoi("    +11191657170") << endl;

    return 0;
}

