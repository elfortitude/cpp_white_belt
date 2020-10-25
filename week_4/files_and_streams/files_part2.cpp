/*
 * Снова считайте все содержимое файла input.txt, но на этот раз
 * выведите его в файл output.txt . Точно так же гарантируется, что
 * содержимое файла input.txt заканчивается переводом строки.
*/

#include <fstream>
#include <string>

using namespace std;

int		main(void)
{
	ifstream	input("input.txt");
	ofstream	output("output.txt");
	string		line;

	while (getline(input, line))
		output << line << endl;
	return 0;
}
