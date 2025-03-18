#include <algorithm>
#include <iostream>
#include <memory.h>
#include <queue>
#include <vector>

int N, M, V;

std::vector<std::vector<int>> nodes(1001);

bool visit[1001];
std::vector<int> dfsVisitList;
std::vector<int> bfsVisitList;

void dfs(int num)
{
    dfsVisitList.push_back(num);
    visit[num] = true;
    std::sort(nodes[num].begin(), nodes[num].end());

    int length = nodes[num].size();

    for (int i = 0; i < length; ++i)
    {
        int nextNode = nodes[num][i];
        if (!visit[nextNode]) dfs(nextNode);
    }
}

void bfs(int num)
{
    std::queue<int> q;
    q.push(num);
    visit[num] = true;

    bfsVisitList.push_back(num);

    while (!q.empty())
    {
        int currentNode = q.front();
        std::sort(nodes[currentNode].begin(), nodes[currentNode].end());
        for (int nextNode : nodes[currentNode])
        {
            if (!visit[nextNode])
            {
                bfsVisitList.push_back(nextNode);
                q.push(nextNode);
                visit[nextNode] = true;
            }
        }
        q.pop();
    }
}

int main()
{
    std::cin >> N >> M >> V;

    for (int i = 0; i < M; ++i)
    {
        int node1, node2;
        std::cin >> node1 >> node2;
        nodes[node1].push_back(node2);
        nodes[node2].push_back(node1);
    }

    dfs(V);

    for (const auto& i : dfsVisitList) std::cout << i << " ";

    std::cout << "\n";

    memset(visit, 0, sizeof(visit));
    bfs(V);

    for (const auto& i : bfsVisitList) std::cout << i << " ";
}
