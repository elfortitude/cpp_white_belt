/*
 * Реализуйте класс ReversibleString, хранящий строку и
 * поддерживающий методы Reverse для переворота строки и
 * ToString для получения строки.
*/

#include <iostream>
#include <string>

using namespace std;

class	ReversibleString
{
public:
	ReversibleString() {}
	ReversibleString(const string& str)
	{
		line = str;
	}
	void	Reverse()
	{
		char	swap;

		for (int i = 0; i < line.size() / 2; ++i)
		{
			swap = line[i];
			line[i] = line[line.size() - 1 - i];
			line[line.size() - 1 - i] = swap;
		}
	}
	string	ToString() const
	{
		return line;
	}
private:
	string	line;
};
