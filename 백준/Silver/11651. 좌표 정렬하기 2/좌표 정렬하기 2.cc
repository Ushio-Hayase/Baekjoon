#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
std::vector<pair<int, int>> arr;

bool func(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
        arr.emplace_back(make_pair(x, y));
    }
    sort(arr.begin(), arr.end(), func);

    for (const auto& iter : arr)
    {
        cout << iter.first << " " << iter.second << "\n";
    }
}