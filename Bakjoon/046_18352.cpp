// 021_1517
// 030_2343

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v;
vector<int> visited;
queue<int> q;

void BFS(int x)
{
	q.push(x);
	int index;
	visited[x]++;

	while(!q.empty())
	{
		index = q.front();
		q.pop();
		
		for (int i = 0; i < v[index].size(); i++)
		{
			int data = v[index][i];

			if (visited[data] == -1)
			{
				visited[data] = visited[index] + 1;
				q.push(data);
			}
		}
	}
}

int main()
{
	int n, m, k, x;
	cin >> n >> m >> k >> x;

	v.resize(n + 1);
	visited = vector<int>(n + 1, -1);

	int v1, v2;
	for (int i = 1; i <= m; i++)
	{
		scanf_s("%d %d", &v1, &v2);
		v[v1].push_back(v2);
	}

	BFS(x);

	bool flag = false;

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == k)
		{
			flag = true;
			printf("%d\n", i);
		}
	}

	if (!flag) cout << "-1" << endl;

	return 0;
}
