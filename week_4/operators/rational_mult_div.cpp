/*
 * Аналогично предыдущей части, реализуйте операторы * и /.
 * Как и в предыдущем случае, гарантируется, что во всех тестах, на которых будет тестироваться
 * ваша реализация, числители и знаменатели ВСЕХ дробей (как исходных, так и получившихся в результате
 * соответствующих арифметических операций) будут укладываться в диапазон типа int.
 * Кроме того, гарантируется, что ни в одном из тестов, на которых будет тестироваться ваша реализация,
 * не будет выполняться деление на ноль.
*/

#include <iostream>

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

Rational	operator*(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational	operator/(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

int		main(void)
{
	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a * b;
		bool equal = c == Rational(8, 9);
		if (!equal)
		{
			cout << "2/3 * 4/3 != 8/9" << endl;
			return 1;
		}
	}

	{
		Rational a(5, 4);
		Rational b(15, 8);
		Rational c = a / b;
		bool equal = c == Rational(2, 3);
		if (!equal)
		{
			cout << "5/4 / 15/8 != 2/3" << endl;
			return 2;
		}
	}

	cout << "OK" << endl;
	return 0;
}
