
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

	string rep(char c, int cnt)
	{
		string result;
		for (int i = 0; i < cnt; ++i)
			result += c;
		return result;
	}

	string intToRoman(int num) 
	{
		string result;
		
		int m = num / 1000;
		num %= 1000;
		result += rep('M', m);
		// num < 1000

		if (num >= 900)
		{
			result += "CM";
			num -= 900;
		}
		// num < 900

		int d = num / 500;
		num %= 500;
		result += rep('D', d);
		// num < 500

		if (num >= 400)
		{
			result += "CD";
			num -= 400;
		}
		// num < 400;

		int c = num / 100;
		num %= 100;
		result += rep('C', c);
		// num < 100

		if (num >= 90)
		{
			result += "XC";
			num -= 90;
		}
		// num < 90

		int l = num / 50;
		num %= 50;
		result += rep('L', l);
		// num < 50

		if (num >= 40)
		{
			result += "XL";
			num -= 40;
		}
		// num < 40

		int x = num / 10;
		num %= 10;
		result += rep('X', x);
		// num < 10

		if (num >= 9)
		{
			result += "IX";
			num -= 9;
		}
		// num < 9

		int v = num / 5;
		num %= 5;
		result += rep('V', v);
		// num < 5

		if (num >= 4)
		{
			result += "IV";
			num -= 4;
		}
		// num < 4

		int i = num;
		result += rep('I', i);
		// num < 10

		return result;
	}
};

int main()
{
	cout << Solution().intToRoman(1994) << endl; // MCMXCIV
	cout << Solution().intToRoman(58) << endl; // LVIII
	cout << Solution().intToRoman(9) << endl; // IX
	cout << Solution().intToRoman(4) << endl; // IV
	cout << Solution().intToRoman(3) << endl; // III

    return 0;
}

