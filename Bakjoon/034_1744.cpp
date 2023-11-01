#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	// -1000 ~ 1000
	// 1. ���� ���� ��� ���� ���� (�켱���� ť 2�� -> ������ ���� ���� ���� ����, ����� ���� ū ���� ����)
	// 1-1. 0�� ���� ��� ���� ����
	// 2. �������� ���Ͽ� ��� ���� �� total�� �ջ�
	// 2-1. 0�� ���� ���, ���� �� �߿� ���� ���� ���� ���Ͽ� total�� �ջ�
	// 3. ����� ū ������ ���Ͽ� total�� �ջ�
	// �� ť�� �� ������ �ݺ�
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
