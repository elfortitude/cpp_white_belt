/*
 * Вам надо написать программу, которая считывает из стандартного ввода одну строку
 * в формате ДРОБЬ_1 операция ДРОБЬ_2. ДРОБЬ_1 и ДРОБЬ_2 имеют формат X/Y, где X — целое,
 * а Y — целое неотрицательное число. операция — это один из символов '+', '-', '*', '/'.
 *
 * Если ДРОБЬ_1 или ДРОБЬ_2 является некорректной обыкновенной дробью, ваша программа должна
 * вывести в стандартный вывод сообщение "Invalid argument". Если считанная операция — это деление
 * на ноль, выведите в стандартный вывод сообщение "Division by zero". В противном случае
 * выведите результат операции.
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
			throw invalid_argument("Invalid argument");
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

Rational	operator+(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}

Rational	operator-(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}

Rational	operator*(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational	operator/(const Rational& lhs, const Rational& rhs)
{
	if (rhs.Numerator() == 0)
		throw domain_error("Division by zero");
	return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
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
	Rational	rational_1;
	Rational	rational_2;
	Rational	rational_3;
	char		operation;

	try
	{
		cin >> rational_1;
		cin >> operation;
		cin >> rational_2;

		if (operation == '+')
			rational_3 = rational_1 + rational_2;
		else if (operation == '-')
			rational_3 = rational_1 - rational_2;
		else if (operation == '*')
			rational_3 = rational_1 * rational_2;
		else
			rational_3 = rational_1 / rational_2;
		cout << rational_3 << endl;
	} catch (exception& ex) {
		cout << ex.what() << endl;
	}

	return 0;
}
