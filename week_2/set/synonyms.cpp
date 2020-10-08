/*
 * Два слова называются синонимами друг друга, если они имеют похожие значения.
 * Реализуйте следующие операции над словарём синонимов:
 *
 * ADD word1 word2 — добавить в словарь пару синонимов (word1, word2).
 *
 * COUNT word — узнать количество синонимов слова word.
 *
 * CHECK word1 word2 — проверить, являются ли слова word1 и word2 синонимами.
 * Слова word1 и word2 считаются синонимами, если среди запросов ADD
 * был хотя бы один запрос ADD word1 word2 или ADD word2 word1.
 *
 * Замечание
 * Для упрощения, будем считать, что синонимы не обладают транзитивностью,
 * то есть, если A - синоним B, а B - синоним C, то из этого НЕ следует,
 * что A - синоним C.
*/

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
