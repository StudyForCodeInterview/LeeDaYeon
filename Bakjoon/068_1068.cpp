#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int leaf = 0;

void DFS(int node, int remove)
{
    visited[node] = true;
    int cnt = 0;

    for (int i = 0; i < adj[node].size(); i++)
    {
        int index = adj[node][i];
       
        if (!visited[index] && index != remove)
        {
            cnt++;
            DFS(index, remove);
        }
    }
    if (cnt == 0)
    {
        leaf++;
    }
}

int main()
{
    int n;
    cin >> n;
    adj.resize(n);
    visited.resize(n);

    int root;

    for (int i = 0; i < n; i++)
    {
        int node;
        scanf_s("%d", &node);

        if (node == -1) 
            root = i;
        else
        {
            adj[i].push_back(node);
            adj[node].push_back(i);
        }
    }

    int remove;
    cin >> remove;

    if (root == remove)
        printf("0\n");
    else
    {
        DFS(root, remove);
        cout << leaf << endl;
    }



    return 0;
}

