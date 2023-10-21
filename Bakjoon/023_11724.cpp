#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<bool> visited(n + 1, false);
	vector<vector<int>> list(n + 1);

	int u, v;

	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d", &u, &v);

		list[u].push_back(v);
		list[v].push_back(u);
	}

	stack<int> s;
	s.push(1);
	visited[1] = true;

	int node, count = 0;
	bool fin = true;

	while (1)
	{
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				fin = false;
				break;
			}
		}

		// 모든 정점이 다 방문했다면 종료
		if (fin && s.empty()) break;

		fin = true;

		node = s.top();
		s.pop();
		//visited[node] = true;

		// 인접 노드 방문 여부 확인 후 push
		for (int i = 0; i < list[node].size(); i++)
		{
			if (!visited[list[node][i]])
			{
				s.push(list[node][i]);
				visited[list[node][i]] = true;
			}
		}

		if (s.empty())
		{
			count++;

			// 방문하지 않은 노드 아무거나 골라서 push
			for (int i = 1; i <= n; i++)
			{
				if (!visited[i])
				{
					s.push(i);
					visited[i] = true;
					break;
				}
			}
		}
	}

	cout << count << endl;

	return 0;
}