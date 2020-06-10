
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <ctype.h>

//class Token
//{
//public:
//
//private:
//
//	std::string m_string;
//};
//
class Expression
{
public:
	Expression()
	{

	}

	static std::shared_ptr<Expression> Parse(const std::string& expression);
};
//
//class Operation : public Expression
//{
//public:
//	Operation(const char sign);
//};

class Tokenizer
{
public:

	explicit Tokenizer(std::string::const_iterator start, std::string::const_iterator end)
		: m_pos(start)
		, m_end(end)
	{

	}

	bool HasNext() const
	{
		return m_pos != m_end;
	}

	const char Character() const
	{
		return *m_pos;
	}

	bool IsSpecial() const
	{
		static const std::string special = "+-*/()^";
		return special.find(Character(), 0) != std::string::npos;
	}

	const std::string MoveNext()
	{
		if (!HasNext())
			return "";

		if (IsSpecial())
			return std::string(1, *m_pos++);

		auto it = m_pos;
		while (HasNext() && !IsSpecial())
			m_pos++;

		return std::string(it, m_pos);
	}

private:
	std::string::const_iterator m_pos, m_end;
};

bool IsNumber(const std::string& token)
{
	if (token.empty())
		return false;
	for (const auto& c : token)
		if (!isdigit(c))
			return false;
	return true;
}

int OperatorPreceedence(const char op)
{
	if (op == '^')
		return 4;
	if (op == '*' || op == '/')
		return 3;
	if (op == '+' || op == '-')
		return 2;
	return 0;
}

bool IsLeftAssociative(const char op)
{
	if (op == '^')
		return false;
	return true;
}

bool IsOperator(const char ch)
{
	static const std::string operators = "+-*/^";
	return operators.find(ch) != std::string::npos;
}

std::shared_ptr<Expression> Expression::Parse(const std::string& expression)
{
	Tokenizer tokenizer(expression.begin(), expression.end());

	std::queue<std::string> output;
	std::stack<char> operations;

	while (tokenizer.HasNext())
	{
		const auto token = tokenizer.MoveNext();
		if (IsNumber(token))
			output.push(token);
		else 
		{
			const char c = token[0];
			if (IsOperator(c))
			{
				const int prec = OperatorPreceedence(c);
				while (!operations.empty() && OperatorPreceedence(operations.top()) >= prec && IsLeftAssociative(operations.top()))
				{
					output.push(std::string(1, operations.top()));
					operations.pop();
				}
				operations.push(c);
			}
			else if (c == '(')
				operations.push(c);
			else if (c == ')')
			{
				while (!operations.empty() && operations.top() != '(')
				{
					output.push(std::string(1, operations.top()));
					operations.pop();
				}
				if (!operations.empty() && operations.top() == '(')
					operations.pop();
				else
					throw 1;
			}
			
		}
	}

	while (!operations.empty())
	{
		output.push(std::string(1, operations.top()));
		operations.pop();
	}

	return nullptr;
}

int main()
{
	std::vector<std::string> tests = 
	{
		"1+2",
		"1+2*3",
		"1+2*(3+4)",
		"3+4*2/(1-5)^2^3"
	};

	for (const auto& test : tests)
	{
		auto pExpr = Expression::Parse(test);
	}

    return 0;
}

