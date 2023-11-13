#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

#define INF 210000000L

vector<tuple<int, int, int>> edge;
vector<long> cost;

int main()
{
    int n, m;
    cin >> n >> m;

    //edge.resize(m + 1);
    cost = vector<long>(n + 1, INF);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf_s("%d %d %d", &a, &b, &c);
        edge.push_back(make_tuple(a, b, c));
    }

    cost[1] = 0;

    // n - 1 회 반복
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tuple<int, int, int> tmp = edge[j];
            int start = get<0>(tmp);
            int end = get<1>(tmp);
            int value = get<2>(tmp);

            if (cost[start] != INF && cost[end] > cost[start] + value)
            {
                cost[end] = cost[start] + value;
            }
        }
    }

    bool flag = false;

    for (int i = 0; i < m; i++)
    {
        tuple<int, int, int> tmp = edge[i];
        int start = get<0>(tmp);
        int end = get<1>(tmp);
        int value = get<2>(tmp);

        if (cost[start] != INF && cost[end] > cost[start] + value)
        {
            flag = true;
            break;
        }
    }

    if (!flag)
    {
        for (int i = 2; i < n + 1; i++)
        {
            if (cost[i] == INF)
                printf("-1\n");
            else
                printf("%d\n", cost[i]);
        }
    }
    else
        printf("-1\n");

    return 0;
}

