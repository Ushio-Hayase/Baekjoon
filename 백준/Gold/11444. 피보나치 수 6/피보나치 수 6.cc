#include <cmath>
#include <iostream>
#include <map>

using namespace std;

unsigned long long N;

map<unsigned long long, unsigned long long> m;

unsigned long long fibo(unsigned long long n)
{
    if (m[n]) return m[n];

    unsigned long long result;

    if (n % 2 == 1)
        result = (fibo((n + 1) / 2) * fibo((n + 1) / 2) % 1'000'000'007 +
                  fibo((n - 1) / 2) * fibo((n - 1) / 2) % 1'000'000'007) %
                 1'000'000'007;

    else
    {
        result =
            fibo(n / 2) * (fibo(n / 2 + 1) + fibo(n / 2 - 1)) % 1'000'000'007;
    }

    return m[n] = result % 1'000'000'007;
}

int main()
{
    cin >> N;
    m[0] = 0;
    m[1] = 1;
    m[2] = 1;

    cout << fibo(N);
}