#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool Compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	else return a.second < b.second;
}

int main()
{
	int n;
	cin >> n;

	long long start, end;
	int count = 0;
	vector<pair<int, int>> mitting;

	for (int i = 0; i < n; i++)
	{
		scanf_s("%lld %lld", &start, &end);
		mitting.push_back({ start, end });
	}

	sort(mitting.begin(), mitting.end(), Compare);

	int i = 0;
	start = mitting[i++].second;
	count++;
	
	while (i < n)
	{
		if (mitting[i].first >= start)
		{
			start = mitting[i].second;
			count++;
		}

		i++;
	}

	cout << count << endl;

	return 0;
}
