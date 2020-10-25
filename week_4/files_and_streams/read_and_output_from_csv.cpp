/*
 * В первой строке файла input.txt записаны два числа N и M.
 * Далее в файле находится таблица из N строк и M столбцов,
 * представленная в формате CSV (comma-separated values).
 * Ваша задача — вывести данные на экран в виде таблицы.
 *
 * Формат таблицы:
 * 1) размер ячейки равен 10,
 * 2) соседние ячейки отделены друг от друга пробелом,
 * 3) последняя ячейка в строке НЕ оканчивается пробелом,
 * 4) последняя строка НЕ оканчивается символом перевода строки. Гарантируется, что в таблице будет ровно N строк и M столбцов, значение каждой из ячеек — целое число.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int		main(void)
{
	ifstream			input("input.txt");
	int					N, M, tmp;
	vector<vector<int>>	table;

	if (input)
	{
		input >> N >> M;
		for(int i = 0; i < N; ++i)
		{
			vector<int> row;
			table.push_back(row);
			for (int j = 0; j < M; ++j)
			{
				input >> tmp;
				input.ignore(1);
				table[i].push_back(tmp);
			}
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << setw(10) << table[i][j];
			if (j != (M - 1))
				cout << " ";
		}
		if (i != (N - 1))
			cout << endl;
	}
	return 0;
}
