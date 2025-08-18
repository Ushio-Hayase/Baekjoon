#include <bits/stdc++.h>

#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

int N, M;
vector<vector<int>> arr;

int main()
{
    FAST_IO;

    cin >> N >> M;

    arr.resize(N);

    for (int i = 0; i < N; ++i)
    {
        arr[i].resize(M);
        for (int j = 0; j < M; ++j) cin >> arr[i][j];
    }

    for (int i = 0; i < N; ++i) sort(arr[i].begin(), arr[i].end());

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    vector<int> pointer(N);
    pair<int, int> max_num = {-1, 0};
    int result = INT_MAX;

    for (int i = 0; i < N; ++i)
    {
        pq.emplace(arr[i][0], i);
        max_num = {max(arr[i][0], max_num.first), i};
    }

    while (!pq.empty())
    {
        auto min_num = pq.top();
        if (pointer[min_num.second] == M - 1)
        {
            result = min(abs(min_num.first - max_num.first), result);
            break;
        }
        pq.pop();
        if (min_num.second != max_num.second)
            result = min(abs(min_num.first - max_num.first), result);

        int new_num = arr[min_num.second][pointer[min_num.second] < M
                                              ? ++pointer[min_num.second]
                                              : M - 1];

        if (new_num > max_num.first) max_num = {new_num, min_num.second};

        if (pointer[min_num.second] < M) pq.emplace(new_num, min_num.second);
    }

    cout << result;
}