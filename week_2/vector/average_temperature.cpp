#include <iostream>
#include <vector>

using namespace std;

int		average(const vector<int> &list, int n)
{
	int	sum;

	sum = 0;
	for (int i = 0; i < n; ++i)
		sum += list[i];
	return sum / n;
}

int		main(void)
{
	int				n;
	int				mid;
	vector<int>		index;

	cin >> n;
	vector<int>		temp(n);
	for (int i = 0; i < n; ++i)
		cin >> temp[i];
	mid = average(temp, n);
	for (int i = 0; i < n; ++i)
		if (temp[i] > mid)
			index.push_back(i);
	cout << index.size() << endl;
	for (int i = 0; i < index.size(); ++i)
		cout << index[i] << " ";
	cout << endl;
	return 0;
}
