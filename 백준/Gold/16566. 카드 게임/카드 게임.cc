#include <bits/stdc++.h>

#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

int N, M, K;

int find_(vector<int>& parent, int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find_(parent, parent[x]);
}

int main()
{
    FAST_IO;

    cin >> N >> M >> K;

    vector<int> arr(M);
    vector<int> remain(N + 1, 0);
    vector<int> parent(N + 1);

    for (int i = 0; i < M; ++i)
    {
        cin >> arr[i];
        parent[i + 1] = i + 1;
        ++remain[arr[i]];
    }

    for (int i = M; i < N; ++i)
    {
        parent[i + 1] = i + 1;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < K; ++i)
    {
        int ques;
        cin >> ques;

        auto iter = upper_bound(arr.begin(), arr.end(), ques);

        cout << find_(parent, *iter) << ' ';
        --remain[parent[*iter]];

        if (remain[parent[*iter]] == 0)
        {
            parent[*iter] = *upper_bound(arr.begin(), arr.end(), parent[*iter]);
        }
    }
}