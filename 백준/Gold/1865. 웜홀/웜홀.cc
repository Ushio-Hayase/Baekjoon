#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

constexpr int INF = 1e+9;

int TC, N, M, W;

int dist[501];

bool func()
{
    vector<tuple<int, int, int>> edge;
    fill(dist, dist + 501, INF);
    dist[1] = 0;
    cin >> N >> M >> W;
    if (N == 1) return false;
    for (int i = 0; i < M; ++i)
    {
        int S, E, T;
        cin >> S >> E >> T;
        edge.emplace_back(S, E, T);
        edge.emplace_back(E, S, T);
    }
    for (int i = 0; i < W; ++i)
    {
        int S, E, T;
        cin >> S >> E >> T;
        edge.emplace_back(S, E, -T);
    }
    for (int i = 0; i < N; ++i)
        for (const auto& iter : edge)
        {
            const int curNode = get<0>(iter);
            const int nextNode = get<1>(iter);
            const int cost = get<2>(iter);
            if (dist[curNode] + cost < dist[nextNode])
            {
                dist[nextNode] = dist[curNode] + cost;
                if (i == N - 1) return true;
            }
        }
    return false;
}

int main()
{
    cin >> TC;
    for (int i = 0; i < TC; ++i)
    {
        if (func())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
