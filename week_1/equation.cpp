/*	На вход вашей программы в стандартном потоке ввода
 *	подаются действительные коэффициенты A, B и C уравнения
 *	Ax² + Bx + C = 0. Выведите все его различные действительные
 *	корни в поток вывода в любом порядке, при этом разделяя корни
 *	пробелами. Гарантируется, что хотя бы один из коэффициентов
 *	уравнения не равен нулю.	*/

#include <iostream>
#include <cmath>

using namespace std;

int		main(void)
{
	double	a, b, c;
	double	d;
	double	x1, x2;

	cin >> a >> b >> c;
	d = b * b - 4 * a * c;
	if (a != 0)
	{
		if (d > 0)
		{
			x1 = (-b + sqrt(d)) / (2 * a);
			x2 = (-b - sqrt(d)) / (2 * a);
			cout << x1 << " " << x2 << endl;
		}
		else if (d == 0)
			cout << -b / (2 * a) << endl;
		else
			cout << endl;
	}
	else if (b != 0)
		cout << -c / b << endl;
	else
		cout << endl;
	return 0;
}
