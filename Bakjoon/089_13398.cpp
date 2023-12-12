#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<int> leftSum;
vector<int> rightSum;

int main()
{
	int n;
	cin >> n;
	arr.resize(n);
	leftSum.resize(n);
	rightSum.resize(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	leftSum[0] = arr[0];

	int result = leftSum[0];

	for (int i = 1; i < n; i++)
	{
		leftSum[i] = max(leftSum[i - 1] + arr[i], arr[i]);

		// 제거 안했을 때, 최대 합
		result = max(result, leftSum[i]);
	}

	rightSum[n - 1] = arr[n - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		rightSum[i] = max(arr[i], rightSum[i + 1] + arr[i]);
	}

	for (int i = 1; i < n - 1; i++)
	{
		int tmp = leftSum[i - 1] + rightSum[i + 1];
		result = max(result, tmp);
	}

	printf("%d\n", result);


	return 0;
}