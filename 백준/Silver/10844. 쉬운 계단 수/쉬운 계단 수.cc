#include <iostream>

using namespace std;

int N;

unsigned long long dp[100][10];

int main()
{
    cin >> N;

    for (int i = 1; i < 10; ++i)
    {
        dp[0][i] = 1;
    }

    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (j != 0 && j != 9)
                dp[i][j] = (dp[i - 1][j - 1] % 1'000'000'000 +
                            dp[i - 1][j + 1] % 1'000'000'000) %
                           1'000'000'000;
            else if (j == 0)
                dp[i][j] = dp[i - 1][j + 1];
            else if (j == 9)
                dp[i][j] = dp[i - 1][j - 1];
        }
    }

    unsigned long long result = 0;

    for (int i = 0; i < 10; ++i)
    {
        result = (result + dp[N - 1][i] % 1'000'000'000) % 1'000'000'000;
    }

    cout << result;
}