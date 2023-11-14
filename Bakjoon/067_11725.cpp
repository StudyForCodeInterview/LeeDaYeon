#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> nodeParent;

void DFS(int node)
{
    visited[node] = true;

    for (int i = 0; i < adj[node].size(); i++)
    {
        int index = adj[node][i];

        if (!visited[index])
        {
            nodeParent[index] = node;
            DFS(index);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    adj.resize(n + 1);
    visited.resize(n + 1);
    nodeParent.resize(n + 1);

    int node1, node2;

    for (int i = 1; i < n; i++)
    {
        scanf_s("%d %d", &node1, &node2);
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    nodeParent[1] = 0;
   
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            DFS(i);
    }

    for (int i = 2; i <= n; i++)
        printf("%d\n", nodeParent[i]);
  

    return 0;
}

