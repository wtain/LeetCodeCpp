
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:

	bool isOperation(const std::string& token)
	{
		return 
			token == "+" ||
			token == "-" ||
			token == "*" ||
			token == "/";
	}

	int strToInt(const std::string& token)
	{
		int result = 0;

		int i0 = 0;
		bool sign = true;
		if (!isdigit(token[0]))
		{
			i0 = 1;
			if (token[0] == '-')
				sign = false;
		}
		for (int i = i0; i < token.length(); ++i)
			result = 10 * result + token[i] - '0';
		return sign ? result : -result;
	}

	int evalRPN(vector<string>& tokens) 
	{
		auto token = tokens.back();
		tokens.pop_back();
		if (!isOperation(token))
			return strToInt(token);
		int v2 = evalRPN(tokens);
		int v1 = evalRPN(tokens);
		if (token == "+")
			return v1 + v2;
		if (token == "-")
			return v1 - v2;
		if (token == "*")
			return v1 * v2;
		if (token == "/")
			return v1 / v2;
		return 0;
	}
};

int main()
{
	vector<string> test1 = { "2", "1", "+", "3", "*" };
	cout << Solution().evalRPN(test1) << endl; // 9

	vector<string> test2 = { "4", "13", "5", "/", "+" };
	cout << Solution().evalRPN(test2) << endl; // 6

	vector<string> test3 = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	cout << Solution().evalRPN(test3) << endl; // 22

	vector<string> test4 = { "3","-4","+" };
	cout << Solution().evalRPN(test4) << endl; // -1

    return 0;
}

