/*
 * Реализуйте справочник столиц стран.
 * На вход программе поступают следующие запросы:
 *
 * CHANGE_CAPITAL country new_capital — изменение столицы страны country
 * на new_capital, либо добавление такой страны с такой столицей, если
 * раньше её не было.
 *
 * RENAME old_country_name new_country_name — переименование страны из
 * old_country_name в new_country_name.
 *
 * ABOUT country — вывод столицы страны country.
 *
 * DUMP — вывод столиц всех стран.
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int			main(void)
{
	int		q;
	string	command;
	map<string, string>		countries;

	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		cin >> command;
		if (command == "CHANGE_CAPITAL")
		{
			string	country, new_capital;
			cin >> country >> new_capital;
			if (countries.count(country) == 0)
			{
				countries[country] = new_capital;
				cout << "Introduce new country " << country << " with capital " << new_capital << endl;
			}
			else if (countries[country] == new_capital)
				cout << "Country " << country << " hasn't changed its capital"  << endl;
			else if (countries[country] != new_capital)
			{
				cout << "Country " << country << " has changed its capital from " << countries[country] << " to " << new_capital << endl;
				countries[country] = new_capital;
			}
		}
		else if (command == "RENAME")
		{
			string	old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;
			if (old_country_name == new_country_name || countries.count(old_country_name) == 0 || countries.count(new_country_name) != 0)
				cout << "Incorrect rename, skip" << endl;
			else
			{
				string tmp_old_capital = countries[old_country_name];
				countries.erase(old_country_name);
				countries[new_country_name] = tmp_old_capital;
				cout << "Country " << old_country_name << " with capital " << countries[new_country_name] << " has been renamed to " << new_country_name << endl;
			}
		}
		else if (command == "ABOUT")
		{
			string	country;
			cin >> country;
			if (countries.count(country) == 0)
				cout << "Country " << country << " doesn't exist" << endl;
			else
				cout << "Country " << country << " has capital " << countries[country] << endl;
		}
		else if (command == "DUMP")
		{
			if (countries.size() == 0)
				cout << "There are no countries in the world" << endl;
			else
			{
				for (const auto& c : countries)
					cout << c.first << "/" << c.second << " ";
				cout << endl;
			}
		}
	}
	return 0;
}
