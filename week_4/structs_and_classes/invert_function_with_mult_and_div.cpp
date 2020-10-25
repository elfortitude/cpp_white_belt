/*
 *
 * Добавьте в класс Function из задачи «Обратимая функция»
 * обработку умножения ('*') и деления ('/').
 * Гарантируется отсутствие элементарных операций умножения и деления на 0.
 *
*/

#include <vector>
#include <algorithm>

using namespace std;

struct		Image
{
	double	quality;
	double	freshness;
	double	rating;
};

struct		Params
{
	double	a;
	double	b;
	double	c;
};

class		FunctionPart
{
public:
	FunctionPart(char new_operation, double new_value)
	{
		operation = new_operation;
		value = new_value;
	}
	double	Apply(double old_value) const
	{
		if (operation == '+')
			return old_value + value;
		else if (operation == '-')
			return old_value - value;
		else if (operation == '*')
			return old_value * value;
		else
			return old_value / value;
	}
	void	Invert()
	{
		if (operation == '+')
			operation = '-';
		else if (operation == '-')
			operation = '+';
		else if (operation == '*')
			operation = '/';
		else
			operation = '*';
	}
private:
	char	operation;
	double	value;
};

class		Function
{
public:
	void	AddPart(char operation, double value)
	{
		parts.push_back({operation, value});
	}
	double	Apply(double value) const
	{
		for (const FunctionPart& part : parts)
			value = part.Apply(value);
		return value;
	}
	void	Invert()
	{
		for (FunctionPart& part : parts)
			part.Invert();
		reverse(begin(parts), end(parts));
	}
private:
	vector<FunctionPart>	parts;
};
