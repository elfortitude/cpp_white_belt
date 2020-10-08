/*
 * Определите тип Incognizable, для которого следующий код будет корректен:
 *
 * int main() {
 *	Incognizable a;
 *	Incognizable b = {};
 *	Incognizable c = {0};
 *	Incognizable d = {0, 1};
 *	return 0;
 * }
*/

#include <iostream>

using namespace std;

struct		Incognizable
{
	int		x = 0;
	int		y = 0;
};
