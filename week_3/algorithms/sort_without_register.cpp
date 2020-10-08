/*
 * Отсортируйте строки S в лексикографическом порядке по возрастанию,
 * игнорируя регистр букв, и выведите их в стандартный поток вывода.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool min_string(string s1, string s2)
{
	for (auto& s : s1)
		s = tolower(s);
	for (auto& s : s2)
		s = tolower(s);
	return s1 < s2;
}

int		main(void)
{
	int		n;

	cin >> n;
	vector<string>	S(n);
	for (auto& s : S)
		cin >> s;
	sort(begin(S), end(S), min_string);
	for (const auto& s : S)
		cout << s << " ";
	cout << endl;
	return 0;
}
