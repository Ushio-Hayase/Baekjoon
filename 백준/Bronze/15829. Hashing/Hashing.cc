#include <cmath>
#include <iostream>
#include <string>

using namespace std;

double N;
string arr;

int main()
{
    cin >> N;

    cin >> arr;

    unsigned long long result = 0;
    unsigned long long tmp = 1;

    for (int i = 0; i < N; ++i)
    {
        result += static_cast<int>(arr[i] - 'a' + 1) * tmp % 1234567891;
        tmp *= 31;
        tmp %= 1234567891;
    }

    cout << result % 1234567891;
}