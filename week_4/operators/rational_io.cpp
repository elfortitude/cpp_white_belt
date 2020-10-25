/*
 * В этой части вам нужно реализовать операторы ввода и вывода для класса Rational.
*/

#include <iostream>
#include <sstream>

using namespace std;

int		nod(int a, int b)
{
	while (a > 0 && b > 0)
	{
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return a + b;
}

class	Rational
{
public:
	Rational()
	{
		p = 0;
		q = 1;
	}

	Rational(int numerator, int denominator)
	{
		int		sign_num;
		int		sign_denom;

		sign_num = 1;
		sign_denom = 1;
		if (numerator == 0)
		{
			p = 0;
			q = 1;
		}
		else
		{
			if (numerator < 0)
			{
				numerator *= -1;
				sign_num *= -1;
			}
			if (denominator < 0)
			{
				denominator *= -1;
				sign_denom *= -1;
			}
			p = numerator / nod(numerator, denominator);
			q = denominator / nod(numerator, denominator);
			if ((sign_num < 0 && sign_denom > 0) || (sign_num > 0 && sign_denom < 0))
				p *= -1;
		}
	}

	int	Numerator() const
	{
		return p;
	}

	int	Denominator() const
	{
		return q;
	}

private:
	int		p;
	int		q;
};

bool	operator==(const Rational& lhs, const Rational& rhs)
{
	return (lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator());
}

istream&	operator>>(istream& stream, Rational& rational)
{
	int		p;
	int		q;
	char	symb;

	stream >> p;
	stream >> symb;
	stream >> q;
	if (stream && symb == '/')
		rational = Rational(p, q);
	return stream;
}

ostream&	operator<<(ostream& stream, const Rational& rational)
{
	stream << rational.Numerator();
	stream << "/";
	stream << rational.Denominator();
	return stream;
}

int		main(void)
{
	{
		ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4")
		{
			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
			return 1;
		}
	}

	{
		istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal)
		{
			cout << "5/7 is incorrectly read as " << r << endl;
			return 2;
		}
	}

	{
		istringstream input("");
		Rational r;
		bool correct = !(input >> r);
		if (!correct)
		{
			cout << "Read from empty stream works incorrectly" << endl;
			return 3;
		}
	}

	{
		istringstream input("");
		Rational r (2, 3);
		input >> r;
		bool equal = r == Rational(2, 3);
		if (!equal)
		{
			cout << "кривое чтение из пустого потока" << endl;
			return 12;
		}
	}

	{
		istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct)
		{
			cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
			return 4;
		}
		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct)
		{
			cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
			return 5;
		}
	}

	{
		istringstream input1("1*2"), input2("1/"), input3("/4");
		Rational r1, r2, r3;
		input1 >> r1;
		input2 >> r2;
		input3 >> r3;
		bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
		if (!correct)
		{
			cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
					<< r1 << " " << r2 << " " << r3 << endl;

			return 6;
		}
	}

	cout << "OK" << endl;
	return 0;
}
