#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

struct Node
{
    int num;
    vector<Node *> connectedNode;
    int parent;
};

Node nodes[100000];
bool visit[100000];

void bfs()
{
    queue<Node *> q;
    q.push(nodes);

    while (!q.empty())
    {
        const Node *idx = q.front();
        q.pop();

        for (const auto &iter : idx->connectedNode)
        {
            if (!visit[iter->num])
            {
                q.push(iter);
                iter->parent = idx->num;
            }
            visit[iter->num] = true;
        }
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        nodes[i] = Node{i, {}};
    }

    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;

        nodes[a - 1].connectedNode.push_back(&nodes[b - 1]);
        nodes[b - 1].connectedNode.push_back(&nodes[a - 1]);
    }

    bfs();

    for (int i = 1; i < N; ++i)
    {

        cout << nodes[i].parent + 1 << "\n";
    }
}
