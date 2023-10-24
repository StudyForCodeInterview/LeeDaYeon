#include <iostream>
#include <algorithm>

using namespace std;

int a[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, value;
	//scanf_s("%d", &n);
	cin >> n;
	//vector<int> a(n);

	for (int i = 0; i < n; i++)
		//scanf_s("%d", &a[i]);
	{
		cin >> value;
		a[i] = value;
	}
	
	/*sort(a.begin(), a.end());*/
	sort(a, a + n);

	//scanf_s("%d", &m);
	cin >> m;

	int num;

	bool flag;
	int mid;


	for (int i = 0; i < m; i++)
	{
		//scanf_s("%d", &num);
		cin >> num;

		flag = false;

		int start = 0;
		int end = n - 1;

		while (start <= end)
		{
			mid = (start + end) / 2;

			if (a[mid] == num)
			{
				flag = true;
				break;
			}
			else if (a[mid] < num)
				start = mid + 1;
			else if (a[mid] > num)
				end = mid;
		}

		if (flag) cout << "1\n";
		else cout << "0\n";

	}


	return 0;
}


