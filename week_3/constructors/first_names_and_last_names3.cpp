/*
 * Дополните класс Person из задачи «Имена и фамилии — 2» конструктором,
 * позволяющим задать имя и фамилию человека при рождении,
 * а также сам год рождения. Класс не должен иметь конструктора по умолчанию.
 *
 * При получении на вход года, который меньше года рождения:
 * методы GetFullName и GetFullNameWithHistory должны отдавать "No person";
 * методы ChangeFirstName и ChangeLastName должны игнорировать запрос.
 *
 * Кроме того, необходимо объявить константными все методы, которые
 * по сути ими являются.
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

string print_history(const vector<string>& names, const string& present_name)
{
	string	res;
	int		finish;

	if (names[names.size() - 1] == present_name)
		finish = 2;
	else
		finish = 1;
	for (int i = names.size() - finish; i >= 0; --i)
	{
		res += names[i];
		if (i != 0)
			res += ", ";
	}
	return res;
}
bool check_double(const vector<string>& names, const string& name)
{
	for (const auto& i : names)
		if (i == name)
			return true;
	return false;
}

class	Person
{
public:
	Person(const string& first_name, const string& last_name, int year)
	{
		ChangeFirstName(year, first_name);
		ChangeLastName(year, last_name);
	}
	void	ChangeFirstName(int year, const string& first_name)
	{
		if (year >= year_to_first_name.begin()->first)
			year_to_first_name[year] = first_name;
	}
	void	ChangeLastName(int year, const string& last_name)
	{
		if (year >= year_to_last_name.begin()->first)
			year_to_last_name[year] = last_name;
	}
	string	GetFullName(int year) const
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
			res = "No person";
		else if (min_fn != -1 && min_ln == -1)
			res = year_to_first_name.at(min_fn) + " with unknown last name";
		else if (min_fn == -1 && min_ln != -1)
			res = year_to_last_name.at(min_ln) + " with unknown first name";
		else
			res = year_to_first_name.at(min_fn) + " " + year_to_last_name.at(min_ln);
		return res;
	}
	string GetFullNameWithHistory(int year) const
	{
		string		res;
		vector<string>	first_names;
		vector<string>	last_names;

		int		min_fn, min_ln;
		min_fn = -1;
		for (const auto i : year_to_first_name)
		{
			if (i.first <= year)
			{
				if (!(check_double(first_names, i.second)))
					first_names.push_back(i.second);
				min_fn = i.first;
			}
			else
					break;
		}
		min_ln = -1;
		for (const auto i : year_to_last_name)
		{
			if (i.first <= year)
			{
				if (!(check_double(last_names, i.second)))
					last_names.push_back(i.second);
				min_ln = i.first;
			}
			else
				break;
		}
		if (min_fn == -1 && min_ln == -1)
			res = "No person";
		else if (min_fn != -1 && min_ln == -1)
		{
			if (first_names.size() == 0)
				res = year_to_first_name.at(min_fn) + " with unknown last name";
			else
			{
				res = year_to_first_name.at(min_fn);
				if (first_names.size() > 1)
				{
					res += " (";
					res += print_history(first_names, year_to_first_name.at(min_fn));
					res += ")";
				}
				res += " with unknown last name";
			}
		}
		else if (min_fn == -1 && min_ln != -1)
		{
			if (last_names.size() == 0)
				res = year_to_last_name.at(min_ln) + " with unknown first name";
			else
			{
				res = year_to_last_name.at(min_ln);
				if (last_names.size() > 1)
				{
					res += " (";
					res += print_history(last_names, year_to_last_name.at(min_ln));
					res += ")";
				}
				res += " with unknown first name";
			}
		}
		else
		{
			if (first_names.size() == 0 && last_names.size() == 0)
				res = year_to_first_name.at(min_fn) + " " + year_to_last_name.at(min_ln);
			else
			{
				res = year_to_first_name.at(min_fn);
				if (first_names.size() > 1)
				{
					res += " (";
					res += print_history(first_names, year_to_first_name.at(min_fn));
					res += ")";
				}
				res += " ";
				res += year_to_last_name.at(min_ln);
				if (last_names.size() > 1)
				{
					res += " (";
					res += print_history(last_names, year_to_last_name.at(min_ln));
					res += ")";
				}
			}
		}
		return res;
	}
private:
	map<int, string>	year_to_first_name;
	map<int, string>	year_to_last_name;
};
