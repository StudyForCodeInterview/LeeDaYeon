#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> temp;

void merge(vector<int>& v, int index1, int m, int index2)
{
	int i = index1;
	int j = m + 1;
	int k = 0;

	while (i <= m && j <= index2)
	{
		if (v[i] <= v[j])
		{
			temp[k++] = v[i++];
		}
		else
		{
			temp[k++] = v[j++];
		}
	}


	// 다른 집합에서 남아있는 데이터 temp에 복사
	if (i > m)
	{
		for (int index = j; index <= index2; index++)
		{
			temp[k++] = v[index];
		}
	}
	// 다른 집합에서 남아있는 데이터 temp에 복사
	else if (j > index2)
	{
		for (int index = i; index <= m; index++)
		{
			temp[k++] = v[index];
		}
	}

	int vIndex = index1;

	// temp를 기존 배열로 복사
	for (int index = 0; index < k; index++)
	{
		v[vIndex] = temp[index];
		vIndex++;
	}

}

void mergeSort(vector<int>& v, int start, int end)
 {
	if (start < end)
	{
		int mid =  (start + end) / 2;
		
		mergeSort(v, start, mid);
		mergeSort(v, mid + 1, end);
		merge(v, start, mid, end);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n, 0);
	temp = vector<int>(n, 0);

	for (int i = 0; i < n; i++)
		scanf_s("%d", &v[i]);


	mergeSort(v, 0, v.size() - 1);

	for (int i = 0; i < v.size(); i++)
		printf("%d\n", v[i]);

	return 0;
}