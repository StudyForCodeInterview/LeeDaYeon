#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visited;
vector<int> dis;
vector<vector<pair<int, int>>> adj;
queue<pair<int, int>> q;

void BFS(int i)
{
	q.push({ i, 0 });
	visited[i] = true;
	int oldNode = i;

	while (!q.empty())
	{
		int node = q.front().first;

		q.pop();

		for (int j = 0; j < adj[node].size(); j++)
		{
			if (!visited[adj[node][j].first])
			{
				q.push({adj[node][j].first, adj[node][j].second});
				visited[adj[node][j].first] = true;
				dis[adj[node][j].first] = dis[node] + adj[node][j].second;
			}
		}
	}
}

int main()
{
	int v;
	cin >> v;

	visited = vector<bool>(v + 1, false);
	adj.resize(v + 1);
	dis = vector<int>(v + 1, 0);
	vector<bool> temp = visited;
	vector<int> temp2 = dis;

	int v1, v2, u;

	for (int i = 1; i <= v; i++)
	{
		scanf_s("%d", &v1);

		while (1)
		{
			scanf_s("%d", &v2);

			if (v2 == -1)
				break;

			scanf_s("%d", &u);

			adj[v1].push_back({ v2, u });
		}
	}

	BFS(1);

	int max = 1;

	for (int i = 2; i <= v; i++)
	{
		if (dis[max] < dis[i])
			max = i;
	}

	visited = temp;
	dis = temp2;

	BFS(max);

	sort(dis.begin(), dis.end());

	cout << dis[v] << endl;

	return 0;
}


