#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, C;

int main()
{
    cin >> C >> N;
    vector<vector<short>> dp;
    vector<short> cost;
    vector<short> consumer;
    cost.resize(N + 1);
    consumer.resize(N + 1);
    dp.resize(N + 1);

    for (int i = 1; i <= N; ++i)
    {
        int a, b;
        cin >> a >> b;
        cost[i] = a;
        consumer[i] = b;
    }
    short min_consumer = *min_element(consumer.begin() + 1, consumer.end());
    short max_cost = *max_element(cost.begin() + 1, cost.end());

    int dp_size = (C / min_consumer + 1) * max_cost + 1;

    for (int i = 0; i <= N; ++i)
    {
        dp[i].resize(dp_size);
    }

    for (int i = 1; i <= N; ++i)
        for (int r = 0; r <= C / consumer[i] + 1; ++r)
            for (int w = 1; w <= dp_size - 1; ++w)

            {
                if (r == 0)
                {
                    if (cost[i] <= w)
                        dp[i][w] = max(static_cast<short>(consumer[i] + dp[i - 1][w - cost[i]]), dp[i - 1][w]);
                    else
                        dp[i][w] = dp[i - 1][w];
                }
                else
                {
                    if (cost[i] <= w)
                        dp[i][w] = max(static_cast<short>(consumer[i] + dp[i][w - cost[i]]), dp[i][w]);
                    else
                        dp[i][w] = dp[i][w];
                }
            }

    for (int i = 1; i <= dp_size - 1; ++i)
        if (dp[N][i] >= C)
        {
            cout << i;
            return 0;
        }
}