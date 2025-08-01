#include <bits/stdc++.h>

#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

int T;
vector<long long> A, B;
map<long long, long long> sum_a, sum_b;

int main()
{
    FAST_IO;

    cin >> T;

    int len_a, len_b;
    cin >> len_a;

    A.resize(len_a + 1);

    for (int i = 1; i <= len_a; ++i)
    {
        int x;
        cin >> x;
        A[i] = A[i - 1] + x;
    }

    cin >> len_b;
    B.resize(len_b + 1);

    for (int i = 1; i <= len_b; ++i)
    {
        int x;
        cin >> x;
        B[i] = B[i - 1] + x;
    }

    long long result = 0;

    for (int i = 1; i <= len_a; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            int sum = A[i] - A[j];
            sum_a[sum]++;
        }
    }

    for (int i = 1; i <= len_b; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            int sum = B[i] - B[j];
            sum_b[sum]++;
        }
    }

    for (auto& a : sum_a)
    {
        auto b = sum_b.lower_bound(T - a.first);
        if (b->first + a.first == T) result += a.second * b->second;
    }

    cout << result;
}
