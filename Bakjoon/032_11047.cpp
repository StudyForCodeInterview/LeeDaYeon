#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k, cnt = 0;

	cin >> n >> k;

	vector<int> money(n);

	for (int i = 0; i < n; i++)
		scanf_s("%d", &money[i]);

	int size = n - 1;

	while (true)
	{
		if (k == 0)
			break;

		if (money[size] > k)
		{
			size--;
			continue;
		}

		k -= money[size];
		cnt++;
	}

	cout << cnt << endl;

	return 0;
}


