
#include <string>
#include <exception>
#include <cctype>
#include <cassert>

class ParserException : std::exception
{
public:
	ParserException()
		: std::exception("ParserException")
	{

	}

	explicit ParserException(const std::string& err)
		: std::exception(("ParserException: " + err).c_str())
	{

	}

	virtual ~ParserException()
	{}
};

//class InvalidFormatException

class NumberParser
{
	std::string::iterator i1, i2;
public:

	NumberParser(std::string::iterator i1, std::string::iterator i2)
		: i1(i1)
		, i2(i2)
	{

	}

	void Throw()
	{
		throw ParserException(std::string(i1, i2));
	}

	int CurrentDigit()
	{
		return *i1 - '0';
	}

	double ParseDigitSequence(double multiplier)
	{
		double rv = 0.0;
		while (std::isdigit(*i1) && i1 != i2)
		{
			rv *= multiplier;
			rv += CurrentDigit();
		}
		return rv;
	}

	double ParseDigitSequenceFraction(double multiplier)
	{
		double frac = 0.0;
		double ord = 1;
		while (std::isdigit(*i1) && i1 != i2) // cp
		{
			ord *= multiplier;
			frac += ord * CurrentDigit();
		}
		return frac;
	}

	bool ParseSign()
	{
		bool positive = true;
		if (*i1 == '-')
		{
			positive = false;
			++i1;
		}
		else if (*i1 == '+')
		{
			++i1;
		}
		return positive;
	}

	double ApplyExponent(double v, int ex, bool exSign)
	{
		assert(false && "Not implemented");
		return 0.0;
	}

	double ParseDouble()
	{
		bool positive = ParseSign();
		if (*i1 != '.' && !std::isdigit(*i1))
			Throw();

		double rv = ParseDigitSequence(10.0);
		if (i1 != i2)
		{
			if (*i1 != '.')
				Throw();
			++i1;
			rv += ParseDigitSequenceFraction(0.1);
		}
		// cp
		if (i1 != i2)
		{
			if (std::toupper(*i1) != 'E')
				Throw();
			++i1;
			bool expos = ParseSign();
			int ex = static_cast<int>(ParseDigitSequence(10.0));
			rv = ApplyExponent(rv, ex, expos);
		}
		return positive ? rv : -rv;
	}
};



int main()
{
	// 0
	// 1
	// +1
	// -1
	// 0.1
	// -0.1
	// .1
	// 1e5
	// 0.1e+5
	// 0.1e-5
	// -0.1e+5
	// -0.12345E+5

	std::string test("-0.12345E+5");
	double v = NumberParser(test.begin(), test.end()).ParseDouble();
	double vex = -0.12345E+5;

    return 0;
}

