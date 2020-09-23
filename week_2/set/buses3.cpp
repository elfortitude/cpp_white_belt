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
