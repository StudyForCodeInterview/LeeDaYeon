#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	int num;

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &num);
		pq.push(num);
	}

	int i1 = 0;
	int i2 = 0;
	int sum = 0;

	while (pq.size() > 1)
	{
		i1 = pq.top();
		pq.pop();

		i2 = pq.top();
		pq.pop();

		sum += i1 + i2;
		pq.push(i1 + i2);
	}
	
	cout << sum << endl;


	return 0;
}


