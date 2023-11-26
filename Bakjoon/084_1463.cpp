#include <iostream>
#include <vector>

using namespace std;

vector<int> D;

int makeOne(int num)
{
    if (num == 1) return 0;
    if (D[num] != 0) return D[num];

    D[num] = makeOne(num - 1) + 1;

    if (num % 2 == 0)
    {
        int tmp = makeOne(num / 2) + 1;
        D[num] = min(tmp, D[num]);
    }

    if (num % 3 == 0)
    {
        int tmp = makeOne(num / 3) + 1;
        D[num] = min(tmp, D[num]);
    }

    return D[num];

}

int main()
{
    int num;
    cin >> num;

    D.resize(num + 1);

    D[1] = 0;

    cout << makeOne(num) << endl;


	return 0;
}


