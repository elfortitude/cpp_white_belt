#include <iostream>
#include <vector>
#include <string>
/*
 * Реализуйте класс, поддерживающий набор строк в отсортированном порядке.
 * Класс должен содержать два публичных метода.
*/

#include <algorithm>

using namespace std;

class SortedStrings
{
public:
	void	AddString(const string& s)
	{
		strings.push_back(s);
	}
	vector<string>	GetSortedStrings()
	{
		sort(begin(strings), end(strings));
		return strings;
	}
private:
	vector<string>	strings;
};
