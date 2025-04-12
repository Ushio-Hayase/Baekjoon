#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T, N, K;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;

    for (int t = 0; t < T; ++t)
    {

        cin >> N >> K;

        vector<int> adj[1001];
        vector<int> constructTime(1001, 0);
        vector<int> dp(1001, 0);
        vector<int> inDegree(1001, 0);
        for (int i = 1; i <= N; ++i)
        {
            cin >> constructTime[i];
            dp[i] = constructTime[i];
        }

        for (int i = 1; i <= K; ++i)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            inDegree[y]++;
        }

        int W;
        cin >> W;

        queue<int> q;
        for (int i = 1; i <= N; ++i)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int i = 0; i < adj[node].size(); ++i)
            {
                int next = adj[node][i];

                dp[next] = dp[node] + constructTime[next] > dp[next] ? dp[node] + constructTime[next] : dp[next];
                inDegree[next]--;
                if (inDegree[next] == 0)

                    q.push(next);
            }
        }

        cout << dp[W] << "\n";
    }
}
