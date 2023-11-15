#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node
{
public:
    Node* next[26];
    bool finished;

    Node() : finished(false)
    {
        fill(next, next + 26, nullptr);
    }

    // 트라이에 문자열 삽입
    void insert(const char* key)
    {
        if (*key == '\0')
            finished = true;
        else
        {
            int index = *key - 'a';
            
            if (next[index] == NULL)
                next[index] = new Node();
            

            next[index]->insert(key + 1);
        }
    }

    Node* find(const char* key)
    {
        if (*key == '\0') return this;

        int index = *key - 'a';

        if (next[index] == NULL) return NULL;

        return next[index]->find(key + 1);
    }

    ~Node()
    {
        for (int i = 0; i < 26; i++)
            if (next[i])
                delete next[i];
    }
};


int main()
{
    int n, m;
    cin >> n >> m;
    
    Node* root = new Node();

    for (int i = 0; i < n; i++)
    {
        char text[501];
        cin >> text;

        root->insert(text);
    }

    int cnt = 0;

    for (int i = 0; i < m; i++)
    {
        char text[501];
        cin >> text;

        Node* findNode = root->find(text);

        if (findNode && findNode->finished)
            cnt++;
    }

    cout << cnt << endl;


    return 0;
}

