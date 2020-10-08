/*
 * В этой задаче вам нужно присваивать номера автобусным маршрутам.
 * А именно, для каждого маршрута, заданного набором названий остановок,
 * нужно либо выдать новый номер (первому маршруту — 1, второму — 2 и т. д.),
 * либо вернуть номер существующего маршрута, которому соответствует такой
 * набор остановок.
 *
 * Наборы остановок, полученные друг из друга перестановкой остановок,
 * считаются различными
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int		main(void)
{
	map<vector<string>, int>	routes;
	int							q;

	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int		stop_count, n;
		vector<string>	stops;
		cin >> stop_count;
		n = routes.size() + 1;
		for (int j = 0; j < stop_count; ++j)
		{
			string	stop;
			cin >> stop;
			stops.push_back(stop);
		}
		if (routes.count(stops) == 0)
		{
			routes[stops] = n;
			cout << "New bus " << routes[stops];
		}
		else
			cout << "Already exists for " << routes[stops];
		cout << endl;
	}
	return 0;
}
