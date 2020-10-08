/*
 * Отсортируйте массив А по модулю и выведите его в стандартный поток.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int		main(void)
{
	int		n;

	cin >> n;
	vector<int>		A(n);
	for (auto& i : A)
		cin >> i;
	sort(begin(A), end(A), [](int x, int y){return(abs(x) < abs(y));});
	for (const auto& i : A)
		cout << i << " ";
	cout << endl;
	return 0;
}
