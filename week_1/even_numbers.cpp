/*
 *	Дано два целых числа A и B (A <= B, A >= 1, B <= 30000).
 *	Выведите через пробел все чётные числа от A до B (включительно).
*/

#include <iostream>

using namespace std;

int		main(void)
{
	int		a, b;

	cin >> a >> b;
	for (int i = a; i <= b; ++i)
		if (i % 2 == 0)
			cout << i << " ";
	return 0;
}
