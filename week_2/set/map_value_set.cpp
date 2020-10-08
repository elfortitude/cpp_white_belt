/*
 * Напишите функцию BuildMapValuesSet, принимающую на вход словарь
 * map<int, string> и возвращающую множество значений этого словаря.
*/

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string>		res;

	for (const auto& s : m)
		res.insert(s.second);
	return res;
}
