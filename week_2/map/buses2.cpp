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
