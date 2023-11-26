#include <iostream>
#include <vector>

using namespace std;

vector<int> D;
vector<int> T;
vector<int> P;

int main()
{
	int n;
	cin >> n;

	D.resize(n + 2);
	T.resize(n + 1);
	P.resize(n + 1);

	int t, p;

	for (int i = 1; i <= n; i++)
	{
		cin >> t >> p;

		T[i] = t;
		P[i] = p;
	}

	for (int i = n; i >= 0; i--)
	{
		if (i + T[i] > n + 1)
			D[i] = D[i + 1];
		else
		{
			D[i] = max(D[i + 1], D[i + T[i]] + P[i]);
		}
	}

	cout << D[1] << endl;

	return 0;
}


