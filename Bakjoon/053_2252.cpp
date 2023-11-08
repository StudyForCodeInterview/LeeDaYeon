#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v;
vector<int> total;
vector<bool> visited;

void BFS(int node)
{
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty())
	{
		int data = q.front();
		q.pop();

		for (int i = 0; i < v[data].size(); i++)
		{
			int adj = v[data][i];
			if (!visited[adj])
			{
				total[adj]++;
				visited[adj] = true;
				q.push(adj);
			}
		}
	}
}

int main()
{

	int n, m;
	cin >> n >> m;

	v.resize(n + 1);
	total.resize(n + 1);
	visited.resize(n + 1);
	vector<bool> temp = visited;

	int v1, v2;
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d", &v1, &v2);
		v[v1].push_back(v2);
	}


	for (int i = 1; i <= n; i++)
	{
		visited = temp;
		BFS(i);
	}

	int max = 0;

	for (int i = 1; i <= n; i++)
	{
		if (max < total[i])
			max = total[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (max == total[i])
		{
			cout << i << " ";
		}
	}

	return 0;
}