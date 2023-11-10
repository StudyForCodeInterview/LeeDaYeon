#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v;
vector<int> answer;
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
	answer.resize(n + 1);

	for(int i=0; i<m; i++)
	{
		int v1,v2;
		cin >> v1 >> v2;
		v[v1].push_back(v2);
	}

	visited.resize(n+1);

	for(int i=0; i<=n; i++)
	{
		fill(visited.begin(), visited.end(), false);
		BFS(i);
	}

	int maxVal;

	for(int i=1; i<=n; i++)
	{
		maxVal = max(maxVal, answer[i]);
	}

	for(int i1; i<=n; i++)
	{
		if(answer[i] == maxVal)
		{
			cout << i << " ";
		}
	}

	return 0;
}
