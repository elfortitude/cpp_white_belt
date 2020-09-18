#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int		main(void)
{
	map<string, vector<string>>		bus_to_stops;
	map<string, vector<string>>		stop_to_buses;
	int								q;

	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		string	command;
		cin >> command;
		if (command == "NEW_BUS")
		{
			string	bus, stop;
			int		stop_count;
			cin >> bus >> stop_count;
			for (int j = 0; j < stop_count; ++j)
			{
				cin >> stop;
				bus_to_stops[bus].push_back(stop);
				stop_to_buses[stop].push_back(bus);
			}
		}
		else if (command == "BUSES_FOR_STOP")
		{
			string	stop;
			cin >> stop;
			if (stop_to_buses.count(stop) == 0)
				cout << "No stop" << endl;
			else
			{
				for (int j = 0; j < stop_to_buses[stop].size(); ++j)
					cout << stop_to_buses[stop][j] << " ";
				cout << endl;
			}
		}
		else if (command == "STOPS_FOR_BUS")
		{
			string	bus;
			cin >> bus;
			if (bus_to_stops.count(bus) == 0)
				cout << "No bus" << endl;
			else
			{
				for (int j = 0; j < bus_to_stops[bus].size(); ++j)
				{
					cout << "Stop " << bus_to_stops[bus][j] << ": ";
					if (stop_to_buses[bus_to_stops[bus][j]].size() == 1)
						cout << "no interchange" << endl;
					else
					{
						for (int k = 0; k < stop_to_buses[bus_to_stops[bus][j]].size(); ++k)
						{
							if (stop_to_buses[bus_to_stops[bus][j]][k] != bus)
								cout << stop_to_buses[bus_to_stops[bus][j]][k] << " ";
						}
						cout << endl;
					}
				}
			}
		}
		else if (command == "ALL_BUSES")
		{
			if (bus_to_stops.size() == 0)
				cout << "No buses" << endl;
			else
			{
				for (const auto& bus : bus_to_stops)
				{
					cout << "Bus " << bus.first << ": ";
					for (int j = 0; j < bus.second.size(); ++j)
						cout << bus.second[j] << " ";
					cout << endl;
				}
			}
		}
	}
	return 0;
}
