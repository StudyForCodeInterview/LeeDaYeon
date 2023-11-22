#include <iostream>
#include <vector>

using namespace std;

#define INF 2100000000

int main()
{
	int n;
	cin >> n;
	
	vector<vector<long long>>adj(n + 1, vector<long long>(n + 1));

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			int n;
			scanf_s("%d", &n);
			adj[i][j] = n;
		}
	}

	for (int k = 1; k < n + 1; k++)
	{
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				if (adj[i][k] == 1 && adj[k][j] == 1)
					adj[i][j] = 1;
			}
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			printf("%lld ", adj[i][j]);
		}
		printf("\n");
	}

	return 0;
}


