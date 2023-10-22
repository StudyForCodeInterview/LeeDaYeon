#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> visited(10, false);
vector<int> result;

bool isPrime(int i)
{
	if (i < 2) return false;

	// 값이 나눠질 경우, 소수가 아님
	for (int j = 2; j * j <= i; j++)
	{
		if (i % j == 0) 
			return false;
	}

	return true;
}

void DFS(int i, int n, int cnt)
{
	if (cnt == n)
	{
		// 소수일 경우 push
		if (isPrime(i))
			result.push_back(i);

		return;
	}

	int num = 10 * i;

	for (int j = 1; j <= 9; j++)
	{
		if (j % 2 == 0) continue;

		if (isPrime(num + j))
		{
			DFS(num + j, n, cnt + 1);
		}
	}
}


int main()
{
	int n;
	cin >> n;

	DFS(2, n, 1);
	DFS(3, n, 1);
	DFS(5, n, 1);
	DFS(7, n, 1);

	for (int i = 0; i < result.size(); i++)
		printf("%d\n", result[i]);

	return 0;
}