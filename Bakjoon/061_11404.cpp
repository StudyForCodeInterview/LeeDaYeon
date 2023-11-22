#include <iostream>
#include <vector>

using namespace std;

#define INF 2100000000

vector<vector<long long>> adj;

int main()
{
	int n, m;
	cin >> n;
	cin >> m;

	adj = vector<vector<long long>>(n + 1, vector<long long>(n + 1));

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (i == j) adj[i][j] = 0;
			else adj[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		scanf_s("%d %d %d", &u, &v, &w);

		if (w < adj[u][v])
			adj[u][v] = w;
	}

	for (int k = 1; k < n + 1; k++)
	{
		for (int u = 1; u < n + 1; u++)
		{
			for (int v = 1; v < n + 1; v++)
			{
				if (adj[u][v] > adj[u][k] + adj[k][v])
					adj[u][v] = adj[u][k] + adj[k][v];
			}
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (adj[i][j] == INF)
				printf("0 ");
			else
				printf("%d ", adj[i][j]);
		}
		printf("\n");
	}

	return 0;
}


