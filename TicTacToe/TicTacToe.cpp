#include <iostream>
#include <vector>

enum Cell
{
	Empty, 
	Cross,
	Zero
};

class Field
{
private:
	std::vector<Cell> m_values;

public:

	Field()
	{
		m_values.resize(9, Empty);
	}

	explicit Field(const std::vector<Cell>& vals)
	{
		m_values = vals;
	}

	Cell operator() (int i, int j) const
	{
		return m_values[3 * i + j];
	}

	Cell CheckWinner()
	{
		Cell rv = CheckImpl(0, 0, 1, 1);
		if (rv != Empty)
			return rv;
		rv = CheckImpl(0, 2, 1, -1);
		if (rv != Empty)
			return rv;

		for (int i = 0; i < 3; ++i)
			if ((rv = CheckImpl(i, 0, 0, 1)) != Empty)
				return rv;

		for (int j = 0; j < 3; ++j)
			if ((rv = CheckImpl(0, j, 1, 0)) != Empty)
				return rv;

		return Empty;
	}

private:
	Cell CheckImpl(int i0, int j0, int di, int dj)
	{
		Cell v = (*this) (i0, j0);
		if (v == Empty)
			return Empty;
		if ((*this) (i0 + di, j0 + dj) != v)
			return Empty;
		if ((*this) (i0 + 2 * di, j0 + 2 * dj) != v)
			return Empty;
		return v;
	}
};

int main()
{
	Cell X = Cross;
	Cell O = Zero;
	Cell _ = Empty;
	Field f1({ X, X, X,
	           _, O, _,
	           O, _, O});

	Field f2({ O, X, X,
		  	   _, O, _,
			   O, _, O });

	Field f3({ O, X, X,
		       _, _, _,
		       O, _, O });

	std::cout << f1.CheckWinner() << std::endl;
	std::cout << f2.CheckWinner() << std::endl;
	std::cout << f3.CheckWinner() << std::endl;

    return 0;
}

