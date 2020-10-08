/*
 * Вам нужно реализовать работу со списком таких дел на месяц,
 * а именно, реализовать набор следующих операций:
 *
 * ADD i s
 * Назначить дело с названием s на день i текущего месяца.
 *
 * DUMP i
 * Вывести все дела, запланированные на день i текущего месяца.
 *
 * NEXT
 * Перейти к списку дел на новый месяц. При выполнении данной команды
 * вместо текущего (старого) списка дел на текущий месяц создаётся и
 * становится активным (новый) список дел на следующий месяц:
 * все дела со старого списка дел копируются в новый список.
 * После выполнения данной команды новый список дел и следующий месяц
 * становятся текущими, а работа со старым списком дел прекращается.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int		main(void)
{
	int						Q;
	int						month;
	int						day;
	string					command;
	string					deal;
	vector<vector<string> >	deals(31);

	month = 0;
	cin >> Q;
	for (int i = 0; i < Q; ++i)
	{
		cin >> command;
		if (command == "ADD")
		{
			cin >> day >> deal;
			deals[day - 1].push_back(deal);
		}
		else if (command == "DUMP")
		{
			cin >> day;
			cout << deals[day - 1].size() << " ";
			for (int j = 0; j < deals[day - 1].size(); ++j)
				cout << deals[day - 1][j] << " ";
			cout << endl;
		}
		else if (command == "NEXT")
		{
			month = ++month % 12;
			if (month == 1 || month == 3 || month == 5 || month == 8 || month == 10)
			{
				if (month != 1)
				{
					deals[29].insert(deals[29].end(), deals[30].begin(), deals[30].end());
					deals.resize(30);
				}
				else
				{
					for (int j = 28; j < deals.size(); ++j)
						deals[27].insert(deals[27].end(), deals[j].begin(), deals[j].end());
					deals.resize(28);
				}
			}
			else
				deals.resize(31);
		}
	}
	return 0;
}
