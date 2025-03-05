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

    long long result = 0;

    for (int i = 0; i < N; ++i)
    {
        result += (static_cast<int>(arr[i] - 'a' + 1) *
                   static_cast<long long>(pow(31, i))) %
                  1234567891;
    }

    cout << result;
}