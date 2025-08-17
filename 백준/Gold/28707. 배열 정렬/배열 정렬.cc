#include <bits/stdc++.h>

#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

struct State
{
    int cost;
    vector<int> arr;

    bool operator>(const State& other) const { return cost > other.cost; }
};

int main()
{
    FAST_IO;

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];

    vector<int> target = arr;
    sort(target.begin(), target.end());

    if (arr == target)
    {
        cout << 0 << '\n';
        return 0;
    }

    int M;
    cin >> M;
    vector<pair<int, int>> ops(M);
    vector<int> costs(M);

    for (int i = 0; i < M; ++i)
    {
        int l, r, c;
        cin >> l >> r >> c;
        ops[i] = {l - 1, r - 1};
        costs[i] = c;
    }

    auto hash_func = [](const vector<int>& v)
    {
        size_t seed = v.size();
        for (auto& i : v)
        {
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    };

    unordered_map<vector<int>, int, decltype(hash_func)> dist(0, hash_func);
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[arr] = 0;
    pq.push({0, move(arr)});

    while (!pq.empty())
    {
        State current = pq.top();
        pq.pop();

        if (current.arr == target)
        {
            cout << current.cost << '\n';
            return 0;
        }

        auto it = dist.find(current.arr);
        if (it != dist.end() && current.cost > it->second)
        {
            continue;
        }

        for (int i = 0; i < M; ++i)
        {
            vector<int> next = current.arr;
            swap(next[ops[i].first], next[ops[i].second]);

            int new_cost = current.cost + costs[i];

            auto next_it = dist.find(next);
            if (next_it == dist.end() || new_cost < next_it->second)
            {
                dist[next] = new_cost;
                pq.push({new_cost, move(next)});
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}