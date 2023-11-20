#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> tree;
vector<int> depth;
vector<bool> visited;
int parent[21][100001];

int maxDepth = 0;

int LCA(int a, int b)
{
	// 왼쪽 노드를 더 깊은 노드로 바꿈
	if (depth[a] < depth[b])
		swap(a, b);

	for (int k = maxDepth; k >= 0; k--)
	{
		if (pow(2, k) <= depth[a] - depth[b])
		{
			a = parent[k][a];
		}
	}

	for (int k = maxDepth; k >= 0 && a != b; k--)
	{
		if (parent[k][a] != parent[k][b])
		{
			a = parent[k][a];
			b = parent[k][b];
		}
	}

	int LCA = a;

	if (a != b)
	{
		LCA = parent[0][LCA];
	}

	return LCA;
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
			if(!visited[next])
			{
				visited[next] = true;
				q.push(next);
				parent[0][next] = now_node;
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
	int n;
	cin >> n;

	tree.resize(n + 1);
	depth.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		scanf_s("%d %d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	
	int tmp = 1;

	// 최대 높이 구하기

	while (tmp <= n)
	{
		tmp <<= 1;
		maxDepth++;
	}


	BFS(1);

	// 부모 배열 구하기
	for (int k = 1; k <= maxDepth; k++)
	{
		for (int nn = 1; nn <= n; nn++)
		{
			parent[k][nn] = parent[k - 1][parent[k - 1][nn]];
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int start, end;
		scanf_s("%d %d", &start, &end);
		printf("%d\n", LCA(start, end));
	}


	return 0;
}


