#include <iostream>
#include <vector>
using namespace std;

int DP[501][501] = {};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;

    cin >> N;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= i; ++j)
        {
            int x;
            cin >> x;
            DP[i][j] = x + max(DP[i - 1][j - 1], DP[i - 1][j]);
        }

    int res = 0;

    for (int i = 0; i <= N; ++i)
        if (DP[N][i] > res)
            res = DP[N][i];

    cout << res;
}