/*
 * Реализуйте класс для человека, поддерживающий историю изменений
 * человеком своих фамилии и имени.
 *
 * Гарантируется, что все имена и фамилии непусты.
 *
 * Строка, возвращаемая методом GetFullName, должна содержать
 * разделённые одним пробелом имя и фамилию человека по состоянию
 * на конец данного года.
 *
 * Если к данному году не случилось ни одного изменения фамилии и имени,
 * верните строку "Incognito".
 *
 * Если к данному году случилось изменение фамилии, но не было ни одного
 * изменения имени, верните "last_name with unknown first name".
 *
 * Если к данному году случилось изменение имени, но не было ни одного
 * изменения фамилии, верните "first_name with unknown last name".
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

class	Person
{
public:
	void	ChangeFirstName(int year, const string& first_name)
	{
		year_to_first_name[year] = first_name;
	}
	void	ChangeLastName(int year, const string& last_name)
	{
		year_to_last_name[year] = last_name;
	}
	string	GetFullName(int year)
	{
		string	res;

		int		min_fn, min_ln;
		min_fn = -1;
		for (const auto i : year_to_first_name)
		{
			if (i.first <= year)
				min_fn = i.first;
			else
					break;
		}
		min_ln = -1;
		for (const auto i : year_to_last_name)
		{
			if (i.first <= year)
				min_ln = i.first;
			else
				break;
		}
		if (min_fn == -1 && min_ln == -1)
			res = "Incognito";
		else if (min_fn != -1 && min_ln == -1)
			res = year_to_first_name[min_fn] + " with unknown last name";
		else if (min_fn == -1 && min_ln != -1)
			res = year_to_last_name[min_ln] + " with unknown first name";
		else
			res = year_to_first_name[min_fn] + " " + year_to_last_name[min_ln];
		return res;
	}
private:
	map<int, string>	year_to_first_name;
	map<int, string>	year_to_last_name;
};
