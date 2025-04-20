#include <iostream>
#include <vector>

using namespace std;

int N, M;

bool dp[2000][2000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; ++i)
    {
        for (int start = 0; start < N - i; ++start)
        {
            int end = start + i;
            if (start == end)
                dp[start][end] = true;
            else if (arr[start] == arr[end])
            {
                if (start == end - 1)
                    dp[start][end] = true;
                else if (dp[start + 1][end - 1])
                    dp[start][end] = true;
            }
        }
    }
    cin >> M;

    while (M--)
    {
        int S, E;
        cin >> S >> E;

        cout << (int)(dp[S - 1][E - 1]) << "\n";
    }
}