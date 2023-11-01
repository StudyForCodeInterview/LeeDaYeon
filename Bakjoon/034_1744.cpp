#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	// -1000 ~ 1000
	// 1. 음수 따로 양수 따로 관리 (우선순위 큐 2개 -> 음수는 가장 작은 값이 위에, 양수는 가장 큰 값이 위에)
	// 1-1. 0이 있을 경우 따로 관리
	// 2. 음수끼리 곱하여 양수 만든 후 total에 합산
	// 2-1. 0이 있을 경우, 음수 값 중에 가장 높은 값과 곱하여 total에 합산
	// 3. 양수는 큰 값끼리 곱하여 total에 합산
	// 각 큐가 빌 때까지 반복
	int n, num;
	cin >> n;
	priority_queue<int> posQ;
	priority_queue<int, vector<int>, greater<int>> negQ;
	queue<int> zeroQ;

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &num);
		if (num < 0) negQ.push(num);
		else if (num > 0) posQ.push(num);
		else zeroQ.push(num);
	}
	long long total = 0;

	int n1, n2;
	while (negQ.size() > 1)
	{
		n1 = negQ.top();
		negQ.pop();
		n2 = negQ.top();
		negQ.pop();

		total += (n1 * n2);
	}

	while (!zeroQ.empty() && negQ.size() == 1)
	{
		total += (zeroQ.front() * negQ.top());
		zeroQ.pop();
		negQ.pop();
	}

	if (negQ.size() == 1)
	{
		total += negQ.top();
		negQ.pop();
	}
	
	while (posQ.size() > 1)
	{
		n1 = posQ.top();
		posQ.pop();
		n2 = posQ.top();
		posQ.pop();

		if (n1 == 1 || n2 == 1)
			total += n1 + n2;
		else
			total += (n1 * n2);
	}

	if (posQ.size() == 1)
	{
		total += posQ.top();
		posQ.pop();
	}

	cout << total << endl;

	return 0;
}
