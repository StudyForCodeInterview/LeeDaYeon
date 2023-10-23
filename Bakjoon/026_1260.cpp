#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<bool> visited;
vector<vector<int>> adj;
stack<int> dfsS;
queue<int> bfsQ;

void DFS(int v)
{
	dfsS.push(v);


	while (!dfsS.empty())
	{
		int data = dfsS.top();
		dfsS.pop();
		
		if (!visited[data])
			printf("%d ", data);

		visited[data] = true;

		for (int i = adj[data].size() - 1; i >= 0; i--)
		{
			if (!visited[adj[data][i]])
			{
				dfsS.push(adj[data][i]);
				//visited[adj[data][i]] = true;
			}
		}
	}

	printf("\n");
}

void BFS(int v)
{
	bfsQ.push(v);
	visited[v] = true;

	while (!bfsQ.empty())
	{
		int data = bfsQ.front();
		bfsQ.pop();

		printf("%d ", data);

		for (size_t i = 0; i < adj[data].size(); i++)
		{
			if (!visited[adj[data][i]])
			{
				bfsQ.push(adj[data][i]);
				visited[adj[data][i]] = true;
			}
		}
	}

	printf("\n");
}


int main()
{
	int n, m, v;

	cin >> n >> m >> v;

	visited = vector<bool>(n + 1, false);

	vector<bool> temp = visited;

	adj.resize(n + 1);

	int u1, u2;

	for (int i = 1; i <= m; i++)
	{
		scanf_s("%d %d", &u1, &u2);

		adj[u1].push_back(u2);
		adj[u2].push_back(u1);
	}

	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());

	DFS(v);

	visited = temp;


	BFS(v);

	return 0;
}


