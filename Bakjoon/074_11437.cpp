#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;

vector<vector<int>> tree;
vector<int> depth;
vector<int> parent;
vector<bool> visited;

int myLCA(int a, int b)
{
	if (depth[a] < depth[b])
		swap(a, b);

	while (depth[a] != depth[b])
	{
		a = parent[a];
	}

	while (a != b)
	{
		a = parent[a];
		b = parent[b];
	}

	return a;
}

void BFS(int node)
{
	queue<int> q;
	q.push(node);
	visited[node] = true;
	int level = 1;
	int now_size = 1;
	int count = 0;

	while (!q.empty())
	{
		int now_node = q.front();
		q.pop();

		for (auto next : tree[now_node])
		{
			if (!visited[next])
			{
				visited[next] = true;
				q.push(next);
				parent[next] = now_node;
				depth[next] = level;
			}
		}
		count++;
		if (count == now_size)
		{
			count = 0;
			now_size = q.size();
			level++;
		}
	}

}

int main()
{
	cin >> n;
	tree.resize(n + 1);
	depth.resize(n + 1);
	parent.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		scanf_s("%d %d", &u, &v);

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	// depth 구하기
	BFS(1);
	
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		// 공통 조상 구할 두 노드
		int a, b;
		scanf_s("%d %d", &a, &b);
		
		int LCA = myLCA(a, b);
		printf("%d\n", LCA);
	}

	return 0;
}


