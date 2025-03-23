#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int dp[100001];

int main()
{
    cin >> N >> M;

    queue<pair<int, int>> q;

    q.emplace(N, 0);

    while (!q.empty())
    {
        const int position = q.front().first;
        const int level = q.front().second;
        q.pop();

        if (position == M)
        {
            cout << level;
            return 0;
        }

        if (level < dp[position] || dp[position] == 0)
        {
            dp[position] = level;
            if (position < 100000) q.emplace(position + 1, level + 1);
            if (position > 0) q.emplace(position - 1, level + 1);
            if (position * 2 <= 100000) q.emplace(position * 2, level + 1);
        }
    }
}
