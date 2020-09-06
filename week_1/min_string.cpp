/*	В стандартном потоке даны три строки, разделённые пробелом.
 *	Каждая строка состоит из строчных латинских букв и имеет длину
 *	не более 30 символов. Выведите в стандартный вывод
 *	лексикографически минимальную из них.	*/

#include <iostream>
#include <string>

using namespace std;

int		main(void)
{
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	if (s1 <= s2 && s1 <= s3)
		cout << s1 << endl;
	else if (s2 <= s1 && s2 <= s3)
		cout << s2 << endl;
	else
		cout << s3 << endl;
	return 0;
}
