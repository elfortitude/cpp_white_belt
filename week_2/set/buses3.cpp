/*
 * В этой задаче вам нужно присваивать номера автобусным маршрутам.
 * А именно, для каждого маршрута, заданного множеством названий остановок,
 * нужно либо выдать новый номер (первому маршруту — 1, второму — 2 и т. д.),
 * либо вернуть номер существующего маршрута, которому соответствует такое
 * множество остановок.
 *
 * В отличие от задачи «Автобусные остановки — 2», наборы остановок,
 * которые можно получить друг из друга перестановкой элементов или
 * добавлением/удалением повторяющихся, следует считать одинаковыми.
*/

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int		main(void)
{
	int		q;
	map<set<string>, int>	routes;

	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int		stop_count, n;
		cin >> stop_count;
		set<string>		stops;
		n = routes.size() + 1;
		for (int j = 0; j < stop_count; ++j)
		{
			string	stop;
			cin >> stop;
			stops.insert(stop);
		}
		if (routes.count(stops) == 0)
		{
			routes[stops] = n;
			cout << "New bus " << routes[stops] << endl;
		}
		else
			cout << "Already exists for " << routes[stops] << endl;
	}
	return 0;
}
