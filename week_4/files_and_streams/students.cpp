/*
 * Определите структуру «Студент» со следующими полями:
 * имя, фамилия, день, месяц и год рождения.
 * Создайте вектор из таких структур, заполните его из входных данных
 * и затем по запросам выведите нужные поля.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct		Student
{
	string	first_name;
	string	second_name;
	int		day;
	int		month;
	int		year;
};


int			main(void)
{
	int					N, M, numb;
	vector<Student>		students;

	cin >> N;
	for (int i = 0; i <N; ++i)
	{
		Student student;
		cin >> student.first_name;
		cin >> student.second_name;
		cin >> student.day;
		cin >> student.month;
		cin >> student.year;
		students.push_back(student);
	}
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		string command;
		cin >> command >> numb;
		if (command == "name" && numb > 0 && numb <= N)
			cout << students[numb - 1].first_name << " " << students[numb - 1].second_name << endl;
		else if (command == "date" && numb > 0 && numb <= N)
			cout << students[numb - 1].day << "." << students[numb - 1].month << "." << students[numb - 1]. year << endl;
		else
			cout << "bad request" << endl;
	}
	return 0;
}
