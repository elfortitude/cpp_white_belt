/*	Напишите функцию MoveStrings, которая принимает два вектора строк,
 *	source и destination, и дописывает все строки из первого вектора
 *	в конец второго. После выполнения функции вектор source должен
 *	оказаться пустым.	*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void	MoveStrings(vector<string> &source, vector<string> &destination)
{
	for (int i = 0; i < source.size(); ++i)
		destination.push_back(source[i]);
	source.clear();
}
