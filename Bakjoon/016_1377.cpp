// 016_1377
// 021_1517
// 030_2343

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> v(n);

	int num;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &num);
		v[i] = { num, i };
	}

	sort(v.begin(), v.end());

	vector<int> index(n);

	for (int i = 0; i < n; i++)
	{
		index[i] = v[i].second - i;
	}

	sort(index.begin(), index.end());


	return 0;
}
