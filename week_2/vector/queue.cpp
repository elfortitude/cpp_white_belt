/*
 * Реализуйте обработку следующих операций над очередью:
 *
 * WORRY i: пометить i-го человека с начала очереди как беспокоящегося;
 *
 * QUIET i: пометить i-го человека как успокоившегося;
 *
 * COME k: добавить k спокойных человек в конец очереди;
 *
 * COME -k: убрать k человек из конца очереди;
 *
 * WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
 *
 * Изначально очередь пуста.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int		main(void)
{
	int				Q;
	int				n;
	int				worry;
	string			command;
	vector<int>		queue;
	vector<int>		worry_count;

	cin >> Q;
	for (int i = 0; i < Q; ++i)
	{
		cin >> command;
		if (command != "WORRY_COUNT")
		{
			cin >> n;
			if (command == "COME")
			{
				if (n > 0)
					for (int j = 0; j < n; ++j)
						queue.push_back(0);
				else if (n < 0)
					for (int j = 0; j < -n; ++j)
						queue.erase(queue.end() - 1);
			}
			else if (command == "WORRY")
				queue[n] = -1;
			else if (command == "QUIET")
				queue[n] = 0;
		}
		else
		{
			worry = 0;
			for (int j = 0; j < queue.size(); ++j)
				if (queue[j] == -1)
					++worry;
			worry_count.push_back(worry);
		}
	}
	for (int i = 0; i < worry_count.size(); ++i)
		cout << worry_count[i] << endl;
	return 0;
}
