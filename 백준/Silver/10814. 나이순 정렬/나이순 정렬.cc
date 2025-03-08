#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M;
priority_queue<pair<int, pair<int, string>>,
               vector<pair<int, pair<int, string>>>,
               greater<pair<int, pair<int, string>>>>
    container;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int x;
        string y;
        cin >> x >> y;
        container.push(make_pair(x, make_pair(i, y)));
    }
    for (int i = 0; i < N; ++i)
    {
        cout << container.top().first << " " << container.top().second.second
             << "\n";
        container.pop();
    }
}