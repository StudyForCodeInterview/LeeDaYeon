#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
    int v1;
    int v2;
    int cost;

    bool operator >(const Edge& a) const
    {
        return cost > a.cost;
    }
};

vector<vector<int>> map;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> sumList;
vector<pair<int, int>> mList;
vector<int> unionArr;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

int direction[4][2] = { {-1,0}, {1,0}, {0, -1}, {0, 1} };
int n, m;
int totalIsland;

int find(int a)
{
    if (a == unionArr[a])
        return a;
    else
        return unionArr[a] = find(unionArr[a]);
}

void myUnion(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
        unionArr[b] = a;
}

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    mList.clear();

    q.push({ i,j });
    map[i][j] = totalIsland;
    visited[i][j] = true;
    mList.push_back({ i,j });

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 상하좌우 탐색
        for (int k = 0; k < 4; k++)
        {
            int tmpX = direction[k][0];
            int tmpY = direction[k][1];

            // 맵 범위 내에서는 계속 탐색
            while (x + tmpX >= 0 && x + tmpX < n && y + tmpY >= 0 && y + tmpY < m)
            {
                // 방문한 적이 없고 바다가 아니면 같은 섬
                if (visited[x + tmpX][y + tmpY] != true && map[x + tmpX][y + tmpY] != 0)
                {
                    visited[x + tmpX][y + tmpY] = true;
                    map[x + tmpX][y + tmpY] = totalIsland;
                    q.push({ x + tmpX, y + tmpY });
                    mList.push_back({ x + tmpX, y + tmpY });
                }
                else
                    break;

                if (tmpX < 0)
                    tmpX--;
                else if (tmpX > 0)
                    tmpX++;
                else if (tmpY < 0)
                    tmpY--;
                else if (tmpY > 0)
                    tmpY++;
            }
        }
    }

}

int main()
{
    cin >> n >> m;

    map.resize(n);
    visited.resize(n, vector<bool>(m));
    
    totalIsland = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int num;
            scanf_s("%d", &num);
            map[i].push_back(num);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1 && visited[i][j] != true)
            {
                bfs(i, j);
                totalIsland++;
                sumList.push_back(mList);
            }
        }
    }

    unionArr.resize(totalIsland);

    for (int i = 1; i < totalIsland; i++)
        unionArr[i] = i;
    
    int pathCost;

    for (int i = 0; i < sumList.size(); i++)
    {
        vector<pair<int, int>> cur = sumList[i];

        for (int j = 0; j < cur.size(); j++)
        {
            pathCost = 0;
            int x = cur[j].first;
            int y = cur[j].second;

            // 상하좌우 탐색
            for (int j = 0; j < 4; j++)
            {
                pathCost = 0;
                int tmpX = direction[j][0];
                int tmpY = direction[j][1];

                // 맵 범위 내에서는 계속 탐색
                while (x + tmpX >= 0 && x + tmpX < n && y + tmpY >= 0 && y + tmpY < m)
                {
                    // 새로운 섬을 발견할 경우 (거리도 2 이상)
                    if (map[x + tmpX][y + tmpY] != 0 && map[x + tmpX][y + tmpY] != i + 1 && pathCost >= 2)
                    {
                        // 엣지 큐에 추가
                        Edge edge;
                        edge.v1 = i + 1;
                        edge.v2 = map[x + tmpX][y + tmpY];
                        edge.cost = pathCost;

                        pq.push(edge);
                        break;
                    }
                    else if (map[x + tmpX][y + tmpY] != 0)
                        break;

                    if (tmpX < 0)
                        tmpX--;
                    else if (tmpX > 0)
                        tmpX++;
                    else if (tmpY < 0)
                        tmpY--;
                    else if (tmpY > 0)
                        tmpY++;

                    pathCost++;
                }
            }
        }
    }

    int result = 0;
    while (!pq.empty())
    {
        Edge e = pq.top();
        int start = e.v1;
        int end = e.v2;
        int cost = e.cost;
        pq.pop();

        // 같은 집합이 아닐 경우
        if (find(start) != find(end))
        {
            myUnion(start, end);
            result += cost;
        }
    }
    
    bool flag = true;

    for (int i = 1; i < unionArr.size() - 1; i++)
    {
        if (find(unionArr[i]) != find(unionArr[i + 1]))
        {
            flag = false;
        }
    }

    if (flag)
        cout << result << endl;
    else
        cout << "-1" << endl;

    return 0;
}

