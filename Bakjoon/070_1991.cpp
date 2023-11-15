#include <iostream>
#include <vector>

using namespace std;

int tree[26][2];
void preorder(int value);
void inorder(int value);
void postorder(int value);


int main()
{
    int n;
    cin >> n;
    

    for (int i = 0; i < n; i++)
    {
        char parent, left, right;
        cin >> parent >> left >> right;

        int node = parent - 'A';

        if (left == '.')
            tree[node][0] = -1;
        else
            tree[node][0] = left - 'A';
        

        if (right == '.')
            tree[node][1] = -1;
        else
            tree[node][1] = right - 'A';
    }

    preorder(0);
    printf("\n");

    inorder(0);
    printf("\n");
    
    postorder(0);
    printf("\n");

    return 0;
}

void preorder(int value)
{
    if (value == -1)
        return;

    cout << (char)(value + 'A');
    preorder(tree[value][0]);
    preorder(tree[value][1]);
}

void inorder(int value)
{
    if (value == -1)
        return;

    inorder(tree[value][0]);
    cout << (char)(value + 'A');
    inorder(tree[value][1]);
}

void postorder(int value)
{
    if (value == -1)
        return;

    postorder(tree[value][0]);
    postorder(tree[value][1]);
    cout << (char)(value + 'A');

}