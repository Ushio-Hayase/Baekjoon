#include <iostream>

using namespace std;

int N, T;

int upper[100'000];
int downer[100'000];

int dp[100'000][3];

int main()
{
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> upper[i];
        for (int i = 0; i < N; ++i) cin >> downer[i];

        if (N == 1)
        {
            cout << max(upper[0], downer[0]) << "\n";
            continue;
        }
        dp[0][1] = upper[0];
        dp[0][2] = downer[0];
        for (int i = 1; i < N; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
            dp[i][1] = upper[i] + max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = downer[i] + max(dp[i - 1][0], dp[i - 1][1]);
        }
        cout << max(max(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]) << "\n";
    }
}