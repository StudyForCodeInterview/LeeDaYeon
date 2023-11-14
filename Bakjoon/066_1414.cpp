#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> myUnionArr;

struct Edge
{
    int start;
    int end;
    int cost;

    bool operator >(const Edge& a) const
    {
        return cost > a.cost;
    }
};

int find(int a)
{
    if (a == myUnionArr[a]) 
        return a;
    else
    {
        return myUnionArr[a] = find(myUnionArr[a]);
    }
}

void myUnion(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
        myUnionArr[b] = a;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> arr(n);


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char a;
            int num;

            scanf_s(" %c", &a);

            if ('a' <= a && a <= 'z')
                num = a - 96;
            else if ('A' <= a && a <= 'Z')
                num = a - 38;
            else num = 0;

            arr[i].push_back(num);
        }
    }

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    
    int edgeCnt = 0;
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                result += arr[i][j];
            }
            else
            {
                if (arr[i][j] == 0)
                    continue;

                Edge e;
                e.start = i;
                e.end = j;
                e.cost = arr[i][j];

                pq.push(e);
            }
        }
    }

    myUnionArr.resize(n);

    for (int i = 0; i < n; i++)
        myUnionArr[i] = i;
    

    while (!pq.empty())
    {
        Edge e = pq.top();
        int start = e.start;
        int end = e.end;
        int cost = e.cost;
        pq.pop();

        if (find(start) != find(end))
        {
            if (start < end)
                myUnion(start, end);
            else
                myUnion(end, start);

            edgeCnt++;
        }
        else
        {
            result += cost;
        }
    }

    if (edgeCnt != n - 1)
        printf("-1\n");
    else
        printf("%d\n", result);

    return 0;
}

