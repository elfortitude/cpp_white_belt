#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int>	BuildCharCounters(const string& word)
{
	map<char, int>	counter;
	for (char c : word)
		++counter[c];
	return counter;
}

int			main(void)
{
	int		n;
	string	word1, word2;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> word1 >> word2;

		if (word1.size() != word2.size())
			cout << "NO" << endl;
		else
		{
			if (BuildCharCounters(word1) == BuildCharCounters(word2))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}
