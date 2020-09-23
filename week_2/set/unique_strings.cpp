#include <iostream>
#include <string>
#include <set>

using namespace std;

int		main(void)
{
	int		n;
	set<string>		unique_strings;
	string	str;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		unique_strings.insert(str);
	}
	cout << unique_strings.size() << endl;
	return 0;
}
