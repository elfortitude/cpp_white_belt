/*
 * Поменяйте реализацию конструктора класса Rational так, чтобы он выбрасывал исключение
 * invalid_argument, если знаменатель равен нулю. Кроме того, переделайте реализацию оператора
 * деления для класса Rational так, чтобы он выбрасывал исключение domain_error,
 * если делитель равен нулю.
*/

#include <iostream>
#include <exception>

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
		if (denominator == 0)
			throw invalid_argument("denominator == 0\n");
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

Rational	operator/(const Rational& lhs, const Rational& rhs)
{
	if (rhs.Numerator() == 0)
		throw domain_error("second operand is 0");
	return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

int		main(void)
{
	try
	{
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	} catch (invalid_argument&) {
	}

	try
	{
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	} catch (domain_error&) {
	}

	cout << "OK" << endl;
	return 0;
}
