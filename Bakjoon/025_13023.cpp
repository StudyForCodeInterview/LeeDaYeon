#include <iostream>
#include <vector>

using namespace std;

// 방문 여부
vector<bool> visited;

// 인접 리스트
vector<vector<int>> vec;
bool flag = false;

void DFS(int i, int max, int cnt)
{
	if (cnt == max)
	{
		// 성공
		flag = true;
		return;
	}

	visited[i] = true;

	for (int j = 0; j < vec[i].size(); j++)
	{
		if (!visited[vec[i][j]])
		{
			DFS(vec[i][j], max, cnt + 1);
		}
	}

	visited[i] = false;
}

int main()
{
	int n, m;
	cin >> n >> m;

	// 인접 리스트
	vec = vector<vector<int>>(n);

	// 방문 여부
	visited = vector<bool>(n, false);

	vector<bool> temp(n, false);


	int a, b;
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		DFS(i, 4, 0);
		
		if (flag) 
			break;

		//visited = temp;
	}

	if (flag) printf("1\n");
	else printf("0\n");

	return 0;
}


