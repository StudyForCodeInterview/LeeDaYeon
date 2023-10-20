#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>


using namespace std;

void quickSort(vector<long long>& a, int low, int high)
{
	if (low >= high) return;

	int i = low;
	int j = high;
	int index = (low + high) / 2;
	long long pivot = a[index];

	while (i <= j)
	{
		while (i <= high && pivot > a[i])
			i++;

		while (j >= low && pivot < a[j])
			j--;

		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	if (low < j) quickSort(a, low, j);
	if (i < high) quickSort(a, i, high);

}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<long long> a(n, 0);

	for (int i = 0; i < n; i++)
	{
		scanf_s("%lld", &a[i]);
	}

	int low = 0, high = n - 1;


	quickSort(a, low, high);


	cout << a[k - 1] << endl;

	return 0;
}