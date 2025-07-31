#include <bits/stdc++.h>

#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

int N;

int main()
{
    FAST_IO;

    unsigned long long result = 0;

    cin >> N;

    priority_queue<unsigned long long, deque<unsigned long long>,
                   greater<unsigned long long>>
        arr;

    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        arr.push(x);
    }

    for (int i = 1; i < N; ++i)
    {
        int a = arr.top();
        arr.pop();
        int b = arr.top();
        arr.pop();
        result += a + b;
        arr.push(a + b);
    }

    cout << result;
}
