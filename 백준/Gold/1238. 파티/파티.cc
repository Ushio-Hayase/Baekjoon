#include <iostream>
#include <memory.h>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

constexpr int INF = numeric_limits<int>::max();

int N, M, X;

vector<pair<int, int>> arr[1001][2];
int dist[1001][2];
priority_queue<pair<int, int>> pq;

void dijkstra(int k)
{
    dist[X][k] = 0;
    pq.push({0, X});

    while (!pq.empty())
    {

        auto nowNode = pq.top();
        pq.pop();

        int toNode = nowNode.second;
        int weightSum = nowNode.first;

        if (dist[toNode][k] < weightSum)
            continue;

        int nodeSize = arr[toNode][k].size();

        for (int i = 0; i < nodeSize; ++i)
        {
            int nextNode = arr[toNode][k][i].first;
            int weight = arr[toNode][k][i].second;

            if (dist[nextNode][k] > weight + weightSum)
            {
                dist[nextNode][k] = weight + weightSum;

                pq.push({weight + weightSum, nextNode});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> X;

    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        arr[a][0].emplace_back(b, c);
        arr[b][1].emplace_back(a, c);
    }

    for (int i = 0; i < 1001; ++i)
    {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    int f = 0;

    dijkstra(0);
    dijkstra(1);
    for (int i = 1; i <= N; ++i)
    {
        f = (i != X && dist[i][0] + dist[i][1] > f) ? dist[i][0] + dist[i][1] : f;
    }

    cout << f;
}
