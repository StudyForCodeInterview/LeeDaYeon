#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define INF 2100000000

vector<vector<pair<int, int>>> adj;
priority_queue<int> result[1001];

void dijkstra(int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({ 0, 1 });

    // 1->1로 가는 첫번째 최단경로는 0
    result[1].push(0);

    while (!q.empty())
    {
        int curNode = q.top().second;
        int curWeight = q.top().first;
        q.pop();

        for (int i = 0; i < adj[curNode].size(); i++)
        {
            int nextNode = adj[curNode][i].first;
            int cost = curWeight + adj[curNode][i].second;

            if (result[nextNode].size() < k)
            {
                result[nextNode].push(cost);
                q.push({ cost, nextNode });
            }
            else
            {
                if (result[nextNode].top() > cost)
                {
                    result[nextNode].pop();
                    result[nextNode].push(cost);
                    q.push({ cost, nextNode });
                }
            }
        }
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    adj.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf_s("%d %d %d", &u, &v, &w);
        adj[u].push_back({ v,w });
    }

    dijkstra(k);

    for (int i = 1; i < n + 1; i++)
    {
        if (result[i].size() < k)
            printf("-1\n");
        else
            printf("%d\n", result[i].top());
    }


    return 0;
}

