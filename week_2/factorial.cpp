/*	Напишите функцию, которая:
 *	называется Factorial, возвращает int,
 *	принимает int и возвращает факториал своего аргумента.
 *	Гарантируется, что аргумент функции по модулю не превышает 10.
 *	Для отрицательных аргументов функция должна возвращать 1.	*/

#include <iostream>

using namespace std;

int		Factorial(int n)
{
	int		fact;

	fact = 1;
	if (n > 0)
	{
		for (int i = 1; i <= n; ++i)
			fact *= i;
	}
	return fact;
}
