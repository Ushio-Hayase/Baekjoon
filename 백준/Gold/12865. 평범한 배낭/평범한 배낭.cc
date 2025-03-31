#include <iostream>
#include <vector>

using namespace std;

int N, K;
int dp[101][100'001];
vector<int> W,V;


int main()
{
    int result = 0;

    cin >> N>>K;
    for (int i = 0; i < N; ++i)
    {
        int w, v;
        cin >> w >> v;
        W.push_back(w);
        V.push_back(v);
    }

    for (int i = 1; i<=N; ++i)
    for(int j = 1; j <= K; ++j)
    {
        const int currentW = W[i-1];
        const int currentV = V[i-1];

        if (currentW <= j) dp[i][j] = max(dp[i-1][j-currentW] + currentV, dp[i-1][j]);
        else dp[i][j] = dp[i-1][j];
    }
    cout << dp[N][K];
}
