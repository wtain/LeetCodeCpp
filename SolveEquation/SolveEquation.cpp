
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

	bool isOperation(char c)
	{
		return c == '+' || c == '-';
	}

	int parseInt(const string& e, int i1, int i2)
	{
		int result = 0;
		for (int i = i1; i <= i2; ++i)
			result = 10 * result + e[i] - '0';
		return result;
	}

	void parseExpression(const string& e, int& x, int& c)
	{
		int i = 0, n = e.length();
		x = 0; c = 0;
		while (i < n)
		{
			int sign = 1;
			if (isOperation(e[i]))
			{
				if (e[i] == '-')
					sign = -1;
				++i;
			}
			int j = i;
			while (j < n && !isOperation(e[j]))
				++j;

			if (e[j - 1] == 'x')
			{
				if (j - 1 == i)
					x += sign;
				else
					x += sign * parseInt(e, i, j - 2);
			}
			else
				c += sign * parseInt(e, i, j - 1);

			i = j;
		}
	}

	string intToStr(int c)
	{
		string result;
		if (!c)
			return "0";
		if (c < 0)
			return "-" + intToStr(-c);
		while (c)
		{
			char d = ('0' + (c % 10));
			string dig;
			dig += d;
			result = dig + result;
			c /= 10;
		}
		return result;
	}

	string solveEquation(string equation) 
	{
		int leftX = 0;
		int leftC = 0;
		int rightX = 0;
		int rightC = 0;

		auto pos = equation.find('=');
		string left = equation.substr(0, pos);
		string right = equation.substr(pos+1);

		parseExpression(left, leftX, leftC);
		parseExpression(right, rightX, rightC);

		leftX -= rightX; rightX = 0;
		rightC -= leftC; leftC = 0;

		if (!leftX)
		{
			if (!rightC)
				return "Infinite solutions";
			else
				return "No solution";
		}

		int result = rightC / leftX;
		
		return "x=" + intToStr(result);
	}
};

int main()
{
	cout << Solution().solveEquation("x+5-3+x=6+x-2") << endl; // "x=2"
	cout << Solution().solveEquation("x=x") << endl; // "Infinite solutions"
	cout << Solution().solveEquation("2x=x") << endl; // "x=0"
	cout << Solution().solveEquation("2x+3x-6x=x+2") << endl; // "x=-1"
	cout << Solution().solveEquation("x=x+2") << endl; // "No solution"
	cout << Solution().solveEquation("-x=-1") << endl; // "x=1"

    return 0;
}

