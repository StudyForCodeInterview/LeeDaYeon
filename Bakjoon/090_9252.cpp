#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int D[1001][1001];

string a;
string b;

int main()
{
	cin >> a;
	cin >> b;


	for (int i = 1; i <= a.size(); i++)
	{
		for (int j = 1; j <= b.size(); j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				D[i][j] = D[i - 1][j - 1] + 1;
			}
			else
			{
				D[i][j] = max(D[i][j - 1], D[i - 1][j]);
			}
		}
	}

	stack<char> result;

	printf("%d\n", D[a.size()][b.size()]);
	bool flag = false;

	for (int i = a.size(); i >= 1;)
	{
		for (int j = b.size(); j >= 1;)
		{

			if (a[i - 1] == b[j - 1])
			{
				result.push(a[i - 1]);
				i--;
				j--;
			}
			else
			{
				//if (i == 0 && j != 0)
				//	j--;
				//else if (j == 0 && i != 0)
				//	i--;
				 if (D[i][j - 1] > D[i - 1][j])
					j--;
				else if (D[i][j - 1] <= D[i - 1][j])
					i--;
			}

			if (i == 0 || j == 0)
			{
				flag = true;
				break;
			}
		}

		if (flag)
			break;
	}

	while (!result.empty())
	{
		printf("%c", result.top());
		result.pop();
	}

	printf("\n");

	return 0;
}