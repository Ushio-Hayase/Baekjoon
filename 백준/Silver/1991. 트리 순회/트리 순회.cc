#include <iostream>
#include <list>
#include <vector>

using namespace std;

int N, M;

struct Node
{
    char root;
    Node *left;
    Node *right;
};

Node tree[26];
vector<char> preorderList;
vector<char> inorderList;
vector<char> postorderList;

void preOrder(Node *idx)
{
    preorderList.push_back(idx->root);
    if (idx->left != nullptr)
        preOrder(idx->left);
    if (idx->right != nullptr)
        preOrder(idx->right);
}
void inOrder(Node *idx)
{
    if (idx->left != nullptr)
        inOrder(idx->left);
    inorderList.push_back(idx->root);
    if (idx->right != nullptr)
        inOrder(idx->right);
}
void postOrder(Node *idx)
{
    if (idx->left != nullptr)
        postOrder(idx->left);
    if (idx->right != nullptr)
        postOrder(idx->right);
    postorderList.push_back(idx->root);
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        char a, b, c;
        cin >> a >> b >> c;

        Node *left = b == '.' ? nullptr : (tree + (b - 'A'));
        Node *right = c == '.' ? nullptr : (tree + (c - 'A'));

        tree[a - 'A'] = Node{a, left, right};
    }

    preOrder(&tree[0]);
    inOrder(&tree[0]);
    postOrder(&tree[0]);

    for (const auto &iter : preorderList)
        cout << iter;
    cout << "\n";
    for (const auto &iter : inorderList)
        cout << iter;
    cout << "\n";
    for (const auto &iter : postorderList)
        cout << iter;
}
