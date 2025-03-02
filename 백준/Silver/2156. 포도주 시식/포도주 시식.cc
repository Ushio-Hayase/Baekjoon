#include <iostream>
#include <stack>

using namespace std;

int N;
int* dp;
int* arr;

void func(int i)
{
    dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
    dp[i] = max(dp[i], dp[i - 1]);
}

int main()
{
    cin >> N;

    dp = new int[N];

    arr = new int[N];

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    dp[1] = dp[0] + arr[1];

    for (int i = 2; i < N; ++i) func(i);

    cout << dp[N - 1];
}