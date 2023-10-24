#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> miro;
bool visited[101][101] = { false };
queue<pair<int, int>> q;

bool check(int y, int x, int m, int n)
{
	if (x < 0 || x > m || y < 0 || y > n) return false;
	if (miro[y][x] != 1) return false;
	if (visited[y][x]) return false;

	return true;
}

void BFS(int x, int y, int endX, int endY)
{
	q.push({ y,x });
	int i, j;

	while (!q.empty())
	{
		i = q.front().first;
		j = q.front().second;
		q.pop();
		visited[i][j] = true;

		if (i == endY && j == endX)
			break;
		

		if (check(i, j + 1, endX, endY))
		{
			q.push({ i, j + 1 });
			miro[i][j + 1] = miro[i][j] + 1;
		}

		if (check(i + 1, j, endX, endY))
		{
			q.push({ i + 1, j });
			miro[i + 1][j] = miro[i][j] + 1;
		}

		if (check(i, j - 1, endX, endY))
		{
			q.push({ i, j - 1 });
			miro[i][j - 1] = miro[i][j] + 1;
		}
	
		if (check(i - 1, j, endX, endY))
		{
			q.push({ i - 1, j });
			miro[i - 1][j] = miro[i][j] + 1;
		}

	}

}

int main()
{
	int n, m;
	cin >> n >> m;

	miro = vector<vector<int>>(n);

	string v;

	for (int i = 0; i < n; i++)
	{
		cin >> v;

		for (int j = 0; j < m; j++)
			miro[i].push_back(v[j] - '0');
	}


	BFS(0, 0, m - 1, n - 1);

	printf("%d\n", miro[n - 1][m - 1]);

	return 0;
}


