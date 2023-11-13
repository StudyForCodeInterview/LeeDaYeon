#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

#define MIN -9223372036854775807
#define MAX 9223372036854775807

using namespace std;

int main()
{
    vector<tuple<int, int, int>> edge;
    vector<long> cityCost;
    vector<long long> dist;

    int n, startNode, endNode, m;
    cin >> n >> startNode >> endNode >> m;

    cityCost.resize(n);
    dist.resize(n);

    fill(dist.begin(), dist.end(), MIN);

    for (int i = 0; i < m; i++)
    {
        int v1, v2, cost;
        scanf_s("%d %d %d", &v1, &v2, &cost);
        edge.push_back({ v1, v2, cost });
    }

    for (int i = 0; i < n; i++)
        scanf_s("%ld", &cityCost[i]);
    
    dist[startNode] = cityCost[startNode];

    for (int i = 0; i <= n + 50; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int start = get<0>(edge[j]);
            int end = get<1>(edge[j]);
            int cost = get<2>(edge[j]);

            if (dist[start] == MIN)
                continue;
            else if (dist[start] == MAX)
                dist[end] = MAX;
            else if (dist[end] < dist[start] + cityCost[end] - cost)
            {
                dist[end] = dist[start] + cityCost[end] - cost;

                if (i >= n - 1)
                {
                    dist[end] = MAX;
                }
            }
        }
    }


    if (dist[endNode] == MAX)
        cout << "Gee" << endl;
    else if (dist[endNode] == MIN)
        cout << "gg" << endl;
    else
        cout << dist[endNode] << endl;

    return 0;
}

