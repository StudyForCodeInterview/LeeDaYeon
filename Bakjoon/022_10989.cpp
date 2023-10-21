#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, num;
	cin >> n;

	vector<int> v(10001, 0);

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &num);
		v[num]++;
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != 0)
		{
			while (v[i] > 0)
			{
				printf("%d\n", i);
				v[i]--;
				n--;
			}
		}

		if (n == 0) break;
	}
		
	return 0;
}