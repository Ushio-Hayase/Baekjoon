#include <memory.h>

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int K, N;
int arr[10];

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    int cnt = N - 1;
    int result = 0;
    while (K > 0)
    {
        if (arr[cnt] <= K)
        {
            K -= arr[cnt];
            result++;
        }
        else
        {
            cnt--;
        }
    }
    cout << result;
}