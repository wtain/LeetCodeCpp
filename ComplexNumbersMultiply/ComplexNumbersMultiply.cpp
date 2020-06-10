
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

	class Complex
	{
		int a, b;
	public:

		static int parseInt(const string& s, int& i)
		{
			int result = 0;
			bool pos = true;
			if (s[i] == '-')
			{
				pos = false;
				++i;
			}
			else if (s[i] == '+')
				++i;
			while (isdigit(s[i]))
			{
				result *= 10;
				result += s[i] - '0';
				++i;
			}
			return pos ? result : -result;
		}

		Complex(int r, int i)
			: a(r)
			, b(i)
		{

		}

		explicit Complex(const string& s)
		{
			int i = 0;
			a = parseInt(s, i);
			++i;
			b = parseInt(s, i);
		}

		static string intToStr(int v)
		{
			string result;
			bool sign = true;
			if (v < 0)
			{
				sign = false;
				v = -v;
			}
			if (!v)
				return "0";
			while (v)
			{
				string vi;
				vi += '0' + (v % 10);
				result = vi + result;
				v /= 10;
			}
			if (!sign)
				result = "-" + result;
			return result;
		}

		string toString() const
		{
			string result;
			result += intToStr(a);
			result += "+";
			result += intToStr(b);
			result += "i";
			return result;
		}

		friend Complex operator* (const Complex& A, const Complex& B)
		{
			int real = A.a * B.a - A.b * B.b;
			int im = A.b * B.a + A.a * B.b;
			return Complex(real, im);
		}
	};

	string complexNumberMultiply(string a, string b) 
	{
		Complex A(a);
		Complex B(b);
		Complex C = A * B;
		return C.toString();
	}
};

int main()
{
	auto r = Solution().complexNumberMultiply("1+1i", "1+1i"); // "0+2i"
	cout << r << endl;
	r = Solution().complexNumberMultiply("1+-1i", "1+-1i"); // "0+-2i"
	cout << r << endl;
    return 0;
}

