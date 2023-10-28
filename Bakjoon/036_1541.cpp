#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int getSum(string modifier)
{

	// + �� �������� ����
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

	// - �� ������ ���� -�� ���ö����� ���� ���Ͽ� ��
	// - �� ��ū���� ���ڿ� �и�
	vector<string> str;
	istringstream ss(modifier);
	string tmp;

	while (getline(ss, tmp, '-'))
	{
		str.push_back(tmp);
	}

	int result = 0;
	// + ���� ���ؾ� ��
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