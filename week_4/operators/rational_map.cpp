/*
 * Наконец, вам нужно реализовать возможность использовать объекты класса Rational
 * в качестве элементов контейнера set и ключей в контейнере map.
*/

#include <iostream>
#include <map>
#include <set>
#include <vector>

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

bool	operator<(const Rational& lhs, const Rational& rhs)
{
	if ((double(lhs.Numerator()) / double(lhs.Denominator())) < (double(rhs.Numerator()) / double(rhs.Denominator())))
		return true;
	else
		return false;
}

int		main(void)
{
	{
		const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
		if (rs.size() != 3)
		{
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs)
		{
			v.push_back(x);
		}
		if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}})
		{
			cout << "Rationals comparison works incorrectly" << endl;
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2)
		{
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}
