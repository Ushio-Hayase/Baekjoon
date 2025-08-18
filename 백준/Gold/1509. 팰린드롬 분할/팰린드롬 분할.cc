#include <bits/stdc++.h>

#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

int N;
string str;
vector<vector<bool>> dp;
vector<int> result;

bool is_palin(int l, int r)
{
    if (r >= N) return false;

    if (str[l] == str[r])
        if (dp[l + 1][r - 1] || r - l == 1) return true;
    return false;
}

int main()
{
    FAST_IO;

    cin >> str;
    N = str.size();

    dp.resize(N);
    for (int i = 0; i < N; ++i) dp[i].resize(N);

    result.resize(N);

    for (int d = 0; d < N; ++d)
    {
        for (int i = 0; i + d < N; ++i)
        {
            if (d == 0)
            {
                dp[i][i] = true;
                continue;
            }
            if (is_palin(i, i + d)) dp[i][i + d] = true;
        }
    }

    result[0] = 0;
    for (int i = 0; i < N; ++i)
    {
        result[i] = INT_MAX;
        for (int j = 0; j <= i; ++j)
            if (dp[j][i])
                if (result[i] > result[j - 1] + 1)
                    result[i] = result[j - 1] + 1;
    }
    cout << result[N - 1];
}