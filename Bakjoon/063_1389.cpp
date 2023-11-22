#include <iostream>
#include <vector>

using namespace std;

#define INF 2100000000

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> result(n + 1);
	vector<vector<long long>> adj(n + 1, vector<long long>(n + 1));

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (i == j) continue;
			
			adj[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		scanf_s("%d %d", &n1, &n2);

		adj[n1][n2] = 1;
		adj[n2][n1] = 1;
	}

	for (int k = 1; k < n + 1; k++)
	{
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				if (adj[i][j] > adj[i][k] + adj[k][j])
				{
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		int total = 0;
		for (int j = 1; j < n + 1; j++)
		{
			total += adj[i][j];
		}
		result[i] = total;
	}

	int min = INF;
	int index = -1;

	for (int i = 1; i < n + 1; i++)
	{
		if (result[i] < min)
		{
			min = result[i];
			index = i;
		}
	}

	printf("%d\n", index);

	return 0;
}


