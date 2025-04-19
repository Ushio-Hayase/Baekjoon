#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int N;

int main()
{
    cin >> N;

    vector<int> isPrime(N + 1, true);
    vector<int> primeNumbers(1);
    vector<int> partialSum(2);
    primeNumbers[0] = 2;
    partialSum[0] = 0;
    partialSum[1] = 2;

    if (N == 1)
    {
        cout << 0;
        return 0;
    }
    else if (N == 2)
    {
        cout << 1;
        return 0;
    }

    for (int i = 2; i <= sqrt(N) + 1; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 3; i <= N; ++i)
    {
        if (isPrime[i]) partialSum.emplace_back(partialSum.back() + i);
    }

    const int len = partialSum.size();
    int left = 0, right = 1;

    int result = 0;

    while (right < len)
    {
        const int sum = partialSum[right] - partialSum[left];
        if (sum == N)
        {
            result++;
            left++;
        }
        else if (sum > N)
            left++;
        else if (sum < N)
            right++;
    }

    cout << result;
}