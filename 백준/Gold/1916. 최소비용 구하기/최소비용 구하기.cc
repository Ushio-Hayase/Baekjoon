#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

constexpr int INF = std::numeric_limits<int>::max();

int dijkstra(int start, int end, int N, vector<pair<int, int>> graph[])
{
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (cur_dist > dist[cur_node])
            continue;

        for (size_t i = 0; i < graph[cur_node].size(); ++i)
        {
            int next_node = graph[cur_node][i].first;
            int next_dist = cur_dist + graph[cur_node][i].second;

            if (next_dist < dist[next_node])
            {
                dist[next_node] = next_dist;
                pq.push({-next_dist, next_node});
            }
        }
    }

    return dist[end];
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, M;

    cin >> N >> M;

    vector<pair<int, int>> graph[N + 1];

    for (int i = 0; i < M; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
    }

    int start, end;

    cin >> start >> end;

    cout << dijkstra(start, end, N, graph);
}