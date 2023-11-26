#include <iostream>
#include <vector>

using namespace std;

vector<long long> D;

int main()
{
	int n;
	cin >> n;

	D.resize(n + 1);

	D[1] = 1;
	D[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		D[i] = D[i - 2] + D[i - 1];
	}

	cout << D[n] << endl;

	return 0;
}


