#include <iostream>
#include <numeric>

using namespace std;

unsigned long long N, K;
unsigned long long* lan;

unsigned long long func(unsigned long long left, unsigned long long right)
{
    unsigned long long mid = (left + right) / 2;

    unsigned long long numCuttingLan = 0;
    for (int i = 0; i < K; ++i) numCuttingLan += lan[i] / mid;

    if (right - left <= 1)
    {
        unsigned long long numCuttingLan = 0;
        for (int i = 0; i < K; ++i) numCuttingLan += lan[i] / (mid + 1);

        return numCuttingLan >= N ? right : left;
    }

    if (numCuttingLan >= N)
        return func(mid, right);
    else
        return func(left, mid - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> K >> N;
    lan = new unsigned long long[K];
    unsigned long long sum = 0;

    for (int i = 0; i < K; ++i)
    {
        cin >> lan[i];
        sum += lan[i];
    }

    cout << func(1,sum);
}