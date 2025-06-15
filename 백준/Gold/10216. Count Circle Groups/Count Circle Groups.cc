#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Circle
{
    int x, y, r;
};

int T, N;

bool is_inside(Circle c1, Circle c2)
{
    return pow((c1.x - c2.x), 2) + pow((c1.y - c2.y), 2) <= pow(c1.r, 2) + 2 * c1.r * c2.r + pow(c2.r, 2);
}

int get_parent(vector<int>& parent, int x)
{
    if (parent[x] != x) return get_parent(parent, parent[x]);
    return parent[x];
}

void union_parent(vector<int>& parent, int x, int y)
{
    int root_x = get_parent(parent, x);
    int root_y = get_parent(parent, y);

    if (root_x == root_y) return;

    if (root_x < root_y)
        parent[y] = x;
    else
        parent[x] = y;
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        vector<Circle> arr(N);
        vector<int> parent(N);
        set<int> result;
        for (int i = 0; i < N; ++i)
        {
            cin >> arr[i].x >> arr[i].y >> arr[i].r;
            parent[i] = i;
        }

        for (int i = 0; i < N; ++i)
            for (int j = i; j < N; ++j)
                if (is_inside(arr[i], arr[j])) union_parent(parent, parent[i], parent[j]);

        for (int i = 0; i < N; ++i)
        {
            result.insert(get_parent(parent, parent[i]));
        }

        cout << result.size() << '\n';
    }
}