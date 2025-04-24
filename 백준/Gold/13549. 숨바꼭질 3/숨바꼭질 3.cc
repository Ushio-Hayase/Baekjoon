#include <iostream>
#include <queue>

using namespace std;

int N, K;
int dist[100'001];

int ZeroOneBfs()
{
    deque<int> dq;
    dq.push_back(N);
    dist[N] = 0;

    while (!dq.empty())
    {
        const int loc = dq.front();
        dq.pop_front();

        if (loc == K) return dist[K];

        int warp = loc * 2;
        if (warp <= 100'000 && dist[warp] > dist[loc])
        {
            dist[warp] = dist[loc];
            dq.push_front(warp);
        }
        int h = loc - 1, t = loc + 1;

        if (h >= 0 && dist[h] > dist[loc] + 1)
        {
            dq.push_back(h);
            dist[h] = dist[loc] + 1;
        }
        if (t <= 100'000 && dist[t] > dist[loc] + 1)
        {
            dq.push_back(t);
            dist[t] = dist[loc] + 1;
        }
    }
}

int main()
{
    cin >> N >> K;
    fill(dist, dist + 100'001, 1e7);
    cout << ZeroOneBfs();
}