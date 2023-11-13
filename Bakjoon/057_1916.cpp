#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define INF 2100000000

vector<vector<pair<int, int>>> adj;
vector<int> cost;
vector<int> visited;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

void BFS(int end)
{
    while (!q.empty())
    {
        int curNode = q.top().second;
        int curWeight = q.top().first;
        q.pop();

        if (visited[curNode]) continue;
        visited[curNode] = true;

        for (int i = 0; i < adj[curNode].size(); i++)
        {
            int nextNode = adj[curNode][i].first;
            int nextWeight = adj[curNode][i].second;

            if (cost[curNode] + nextWeight < cost[nextNode])
            {
                cost[nextNode] = cost[curNode] + nextWeight;

                if (nextNode != end)
                    q.push({ cost[nextNode], nextNode });
            }

        }
    }
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    
    adj.resize(n + 1);
    cost = vector<int>(n + 1, INF);
    visited.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf_s("%d %d %d", &u, &v, &w);
        
        adj[u].push_back({ v,w });
    }

    int start, end;
    cin >> start >> end;

    cost[start] = 0;
    q.push({ cost[start], start});
    BFS(end);


    cout << cost[end] << endl;

    return 0;
}

