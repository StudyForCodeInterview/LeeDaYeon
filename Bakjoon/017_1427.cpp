#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	string N;
	cin >> N;

	vector<int> num(N.size(), 0);

	for (int i = 0; i < N.size(); i++)
		num[i] = N[i] - '0';

	int i = 0;
	int min = 0;
	int temp;

	while (i < N.size())
	{
		for (int j = i; j < N.size() - 1; j++)
		{
			if (num[min] < num[j + 1])
			{
				min = j + 1;
			}
		}

		temp = num[i];
		num[i] = num[min];
		num[min] = temp;

		i++;

		min = i;
	}

	for (int i = 0; i < N.size(); i++)
		printf("%d", num[i]);

	printf("\n");

	return 0;
}