#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int>time(N, 0);

	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &time[i]);
	}


	// 선택 정렬
	for (int i = 0; i < N - 1; i++)
	{
		int min = time[i];
		int index = i;

		for (int j = i + 1; j < N; j++)
		{
			if (min > time[j])
			{
				min = time[j];
				index = j;
			}
		}

		swap(time[i], time[index]);
	}

	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			sum += time[j];
		}
	}

	cout << sum << endl;


	return 0;
}