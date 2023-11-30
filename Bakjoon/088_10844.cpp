#include <iostream>
#include <vector>

using namespace std;

vector<long long> D;

int main()
{
	int n;
	cin >> n;

	vector<vector<long long>> arr(n + 1, vector<long long>(11));

	int total = 0;
	for (int i = 0; i < 10; i++)
	{
		if (i == 0) arr[1][i] = 0;
		else arr[1][i] = 1;

		total += arr[1][i];
	}

	arr[1][10] = total;

	if (n == 1)
	{
		printf("%lld\n", arr[1][10]);
		
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			total = 0;

			for (int j = 0; j < 10; j++)
			{
				if (j == 0)
					arr[i][j] = arr[i - 1][j + 1] % 1000000000;
				else if (j == 9)
					arr[i][j] = arr[i - 1][j - 1] % 1000000000;
				else
					arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;

				total += arr[i][j];
			}

			arr[i][10] = total;
		}

		printf("%lld\n", arr[n][10]);
	}

	return 0;
}


