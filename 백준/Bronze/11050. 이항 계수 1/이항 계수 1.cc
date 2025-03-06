#include <iostream>

using namespace std;

int N, K, S;
int main()
{
    cin >> N >> K;
    S = N - K;
    double result = 1;
    for (int i = 1; i <= N; ++i) result *= i;
    for (int i = 1; i <= K; ++i) result /= i;
    for (int i = 1; i <= S; ++i) result /= i;
    cout << result;
}