#include <bits/stdc++.h>

#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

int N, M;
vector<int> parent;

int find_(int x) { return (parent[x] == x) ? x : parent[x] = find_(parent[x]); }

void union_(int a, int b)
{
    int root_a = find_(a);
    int root_b = find_(b);

    if (root_a > root_b)
        parent[root_a] = root_b;
    else if (root_b > root_a)
        parent[root_b] = root_a;
}

int main()
{
    FAST_IO;

    cin >> N >> M;

    parent.assign(N, 0);

    for (int i = 0; i < N; ++i) parent[i] = i;

    for (int i = 1; i <= M; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (find_(a) == find_(b))
        {
            cout << i;
            return 0;
        }
        union_(a, b);
    }

    cout << 0;
}
