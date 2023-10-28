#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int getSum(string modifier)
{

	// + 를 기준으로 구분
	vector<string> str;

	istringstream ss(modifier);
	string tmp;

	while (getline(ss, tmp, '+'))
	{
		str.push_back(tmp);
	}

	int sum = 0;
	for (int i = 0; i < str.size(); i++)
		sum += stoi(str[i]);
	
	return sum;
}

int main()
{
	string modifier = "";
	cin >> modifier;

	// - 가 나오면 다음 -가 나올때까지 식을 더하여 뺌
	// - 를 토큰으로 문자열 분리
	vector<string> str;
	istringstream ss(modifier);
	string tmp;

	while (getline(ss, tmp, '-'))
	{
		str.push_back(tmp);
	}

	int result = 0;
	// + 식을 더해야 함
	for (int i = 0; i < str.size(); i++)
	{
		string sum = str[i];
		if (i == 0)
		{
			result += getSum(str[i]);
		}
		else
		{
			result -= getSum(str[i]);
		}
	}

	cout << result << endl;

	return 0;
}