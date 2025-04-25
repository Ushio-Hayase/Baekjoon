#include <memory.h>

#include <iostream>
#include <vector>

using namespace std;

int V;
int NODE, DIST;
vector<pair<int, int>> graph[100'001];
bool visit[100'001];

void dfs(int x, int dist)
{
    visit[x] = true;

    if (dist > DIST)
    {
        DIST = dist;
        NODE = x;
    }

    int len = graph[x].size();

    for (int i = 0; i < len; ++i)
    {
        int nextNode = graph[x][i].first;
        int nextDist = graph[x][i].second + dist;

        if (!visit[nextNode])
        {
            visit[nextNode] = true;
            dfs(nextNode, nextDist);
            visit[nextNode] = false;
        }
    }
}

int main()
{
    cin >> V;

    for (int i = 0; i < V; ++i)
    {
        int node, edge, dist;
        cin >> node;
        cin >> edge;
        while (edge != -1)
        {
            cin >> dist;
            graph[node].push_back({edge, dist});
            // graph[edge].push_back({node, dist});
            cin >> edge;
        }
    }

    dfs(1, 0);
    memset(visit, 0, 100'001);
    DIST = 0;

    dfs(NODE, 0);

    cout << DIST;
}