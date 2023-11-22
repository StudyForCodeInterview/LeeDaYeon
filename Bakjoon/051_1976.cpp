#include <iostream>
#include <vector>

using namespace std;

vector<int> myUnion;

int find(int a)
{
	if (a == myUnion[a])
		return a;
	else
		return myUnion[a] = find(myUnion[a]);
}

void unionFunc(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
		myUnion[b] = a;
}

int main()
{
	int n, m;
	cin >> n;
	cin >> m;

	myUnion.resize(n + 1);

	for (int i = 1; i < n + 1; i++)
		myUnion[i] = i;

	int num;

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			scanf_s("%d", &num);
			
			if (num == 1)
			{
				if (find(i) != find(j))
				{
					unionFunc(i, j);
				}
			}
		}
	}

	vector<int> path(m);

	for (int i = 0; i < m; i++)
	{
		scanf_s("%d", &path[i]);
	}

	bool flag = true;

	for (int i = 0; i < m - 1; i++)
	{
		if (find(myUnion[path[i]]) != find(myUnion[path[i + 1]]))
		{
			flag = false;
		}
	}

	return 0;
}


