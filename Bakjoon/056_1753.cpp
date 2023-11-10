#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define INF 2147483647

vector<vector<pair<int, int>>> adj;
vector<bool> visited;
vector<int> cost;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

void BFS()
{
    while (!q.empty())
    {
        int node = q.top().second;
        q.pop();

        if (visited[node]) continue;

        visited[node] = true;

        for (size_t i = 0; i < adj[node].size(); i++)
        {
            int index = adj[node][i].first;
            int weight = adj[node][i].second;

            if (cost[node] + weight < cost[index])
            {
                cost[index] = cost[node] + weight;
                q.push({ cost[index], index });
            }
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    adj.resize(V + 1);
    cost.resize(V + 1);
    visited.resize(V + 1);

    fill(cost.begin(), cost.end(), INF);

    int k;
    cin >> k;

    int u, v, w;

    for (int i = 0; i < E; i++)
    {
        scanf_s("%d %d %d", &u, &v, &w);
        adj[u].push_back({ v, w });
    }

    cost[k] = 0;
    q.push({ 0, k });
    BFS();

    for (size_t i = 1; i < cost.size(); i++)
    {
        if (cost[i] == INF) printf("INF\n");
        else
            printf("%d\n", cost[i]);
    }

    return 0;
}

