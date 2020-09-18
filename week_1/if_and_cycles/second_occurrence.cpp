/*	Дана строка. Найдите в этой строке второе вхождение буквы f
 *	и выведите индекс этого вхождения. Если буква f в данной строке
 *	встречается только один раз, выведите число -1, а если не
 *	встречается ни разу, выведите число -2. Индексы нумеруются с нуля.	*/

#include <iostream>
#include <string>

using namespace std;

int		main(void)
{
	string	str;
	int		n;

	cin >> str;
	n = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == 'f')
		{
			++n;
			if (n == 2)
			{
				cout << i << endl;
				break;
			}
		}
	}
	if (n == 1)
		cout << -1 << endl;
	else if (n == 0)
		cout << -2 << endl;
	return 0;
}
