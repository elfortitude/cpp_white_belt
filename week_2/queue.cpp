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
