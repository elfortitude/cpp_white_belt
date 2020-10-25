/*
 * Напишите функцию
 * void EnsureEqual(const string& left, const string& right);
 *
 * В случае, если строка left не равна строке right, функция должна выбрасывать
 * исключение runtime_error с содержанием "<l> != <r>", где <l> и <r> - строки,
 * которые хранятся в переменных left и right соответственно. Обратите внимание,
 * что вокруг знака неравенства в строке, которая помещается в исключение,
 * должно быть ровно по одному пробелу.
 *
 * Если left == right, функция должна корректно завершаться.
*/

#include <iostream>
#include <sstream>

using namespace std;

void	EnsureEqual(const string& left, const string& right)
{
	if (left != right)
	{
		stringstream ss;
		ss << left << " != " << right;
		throw runtime_error(ss.str());
	}
}
