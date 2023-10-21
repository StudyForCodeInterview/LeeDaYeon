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

		// ��� ������ �� �湮�ߴٸ� ����
		if (fin && s.empty()) break;

		fin = true;

		node = s.top();
		s.pop();
		//visited[node] = true;

		// ���� ��� �湮 ���� Ȯ�� �� push
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

			// �湮���� ���� ��� �ƹ��ų� ��� push
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