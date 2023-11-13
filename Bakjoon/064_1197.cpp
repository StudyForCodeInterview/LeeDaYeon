#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> myUnionArray;

struct edge
{
    int v1;
    int v2;
    int cost;

    bool operator > (const edge& a) const
    {
        return cost > a.cost;
    }
};

int find(int a)
{
    if (a == myUnionArray[a]) 
        return a;
    else
        return myUnionArray[a] = find(myUnionArray[a]);
}

void myUnion(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
        myUnionArray[b] = a;
}

int main()
{
    int v, e;
    cin >> v >> e;

    priority_queue<edge, vector<edge>, greater<edge>> q;

    myUnionArray.resize(v + 1);

    for (int i = 1; i < v + 1; i++)
        myUnionArray[i] = i;
    
    for (int i = 0; i < e; i++)
    {
        edge ed;
        scanf_s("%d %d %d", &ed.v1, &ed.v2, &ed.cost);
        q.push(ed);
    }

    int result = 0;

    while (!q.empty())
    {
        edge e = q.top();
        int findA = e.v1;
        int findB = e.v2;

        // 같은 집합(cycle)이 아닐 경우, 간선 등록
        if (find(findA) != find(findB))
        {
            myUnion(findA, findB);
            result += e.cost;
        }

        q.pop();
    }

    cout << result << endl;

    return 0;
}

