#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int		main(void)
{
	int		q;
	map<string, set<string>>	synonyms;

	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		string	command;
		cin >> command;
		if (command == "ADD")
		{
			string	word1, word2;
			cin >> word1 >> word2;
			synonyms[word1].insert(word2);
			synonyms[word2].insert(word1);
		}
		else if (command == "COUNT")
		{
			string	word;
			cin >> word;
			cout << synonyms[word].size() << endl;
		}
		else if (command == "CHECK")
		{
			string	word1, word2;
			cin >> word1 >> word2;
			if (synonyms[word1].count(word2) != 0 || synonyms[word2].count(word1))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}
