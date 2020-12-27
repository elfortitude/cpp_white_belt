#include <iostream>
#include <exception>
#include <sstream>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

class	Date
{
public:
	Date()
	{
		year = 0;
		month = 0;
		day = 0;
	}
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	void	SetYear(int y)
	{
		year = y;
	}
	void	SetMonth(int m)
	{
		if (m < 1 || m > 12)
			throw invalid_argument("Month value is invalid: " + to_string(m));
		month = m;
	}
	void	SetDay(int d)
	{
		if (d < 1 || d > 31)
			throw invalid_argument("Day value is invalid: " + to_string(d));
		day = d;
	}
	int	GetYear() const
	{
		return year;
	}
	int	GetMonth() const
	{
		return month;
	}
	int	GetDay() const
	{
		return day;
	}
private:
	int	year;
	int	month;
	int	day;
};

bool	operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() < rhs.GetYear())
		return true;
	else if ((lhs.GetYear() == rhs.GetYear()) && (lhs.GetMonth() < rhs.GetMonth()))
		return true;
	else if ((lhs.GetYear() == rhs.GetYear()) && (lhs.GetMonth() == lhs.GetMonth())
			&& (lhs.GetDay() < lhs.GetDay()))
		return true;
	else
		return false;
}

class	Database
{
public:
	void	AddEvent(const Date& date, const string& event)
	{
		mapDates[date].insert(event);
	}
	bool	DeleteEvent(const Date& date, const string& event)
	{
		if (mapDates.count(date) != 0)
		{
			if (mapDates.at(date).count(event) == 0)
				return false;
			else
			{
				mapDates.at(date).erase(event);
				return true;
			}
		}
		return false;
	}
	int		DeleteDate(const Date& date)
	{
		int	count;

		count = 0;
		if (mapDates.count(date) != 0)
		{
			for (auto& event : mapDates.at(date))
				++count;
			mapDates.erase(date);
		}
		return count;
	}

	void	Find(const Date& date) const
	{
		if (mapDates.count(date) > 0)
		{
			if (mapDates.at(date).size() > 0)
			{
				for (auto& event : mapDates.at(date))
				{
					cout << event << endl;
				}
			}
		}
	}

	void	Print() const
	{
		for (auto& date : mapDates)
		{
			for (auto& event : date.second)
			{
				cout << setw(4) << setfill('0') << date.first.GetYear() << "-"
					 << setw(2) << setfill('0') << date.first.GetMonth() << "-"
					 << setw(2) << setfill('0') << date.first.GetDay() << " "
					 << event << endl;
			}
		}
	}
private:
	map<Date, set<string>>	mapDates;
};

void	commands_handler(const Date& date, const string& command, const string& event, Database& db, bool flag)
{
	if (command == "Add")
		db.AddEvent(date, event);
	else if (command == "Find")
		db.Find(date);
	else if (command == "Print")
		db.Print();
	else if (command == "Del")
	{
		if (flag)
			cout << "Deleted " << to_string(db.DeleteDate(date)) << " events" << endl;
		else
		{
			if (db.DeleteEvent(date, event))
				cout << "Deleted successfully" << endl;
			else
				cout << "Event not found" << endl;
		}
	}
}

void	EnsureNextSymbolSkip(char def, string date)
{
	if (def != '-')
	{
		stringstream stream;
		stream << "Wrong date format: " << date;
		throw invalid_argument(stream.str());
	}
}

void	parser(const string& command, Database& db)
{
	stringstream	ss;
	stringstream	ss_date;
	string			cmd;
	string			d;
	Date			date;
	bool			check_empty_event;

	ss << command;
	ss >> cmd;
	check_empty_event = false;
	if (cmd != "Add" && cmd != "Del" && cmd != "Find" && cmd != "Print")
		throw invalid_argument("Unknown command: " + cmd);
	if (cmd != "Print")
	{
		int year, month, day;
		char def1, def2;
		ss >> d;
		ss_date << d;
		if (ss_date >> year >> def1 >> month >> def2 >> day && ss_date.peek() == EOF)
		{
			date.SetYear(year);
			EnsureNextSymbolSkip(def1, d);
			date.SetMonth(month);
			EnsureNextSymbolSkip(def2, d);
			date.SetDay(day);
		}
		else
		{
			stringstream stream;
			stream << "Wrong date format: " << d;
			throw invalid_argument(stream.str());
		}
		if (ss.peek() == -1)
			check_empty_event = true;
		ss >> d;
	}
	commands_handler(date, cmd, d, db, check_empty_event);
}

int		main(void)
{
	Database db;

	string command;
	while (getline(cin, command))
	{
		if (command.size() > 0)
		{
			try
			{
				parser(command, db);
			}
			catch(const exception& e)
			{
				cout << e.what() << endl;
				return 0;
			}
		}
	}
	return 0;
}
