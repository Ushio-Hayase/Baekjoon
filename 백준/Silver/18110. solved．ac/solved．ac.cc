#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

double N;
int* arr;

int main()
{
    cin >> N;

    if (N == 0)
    {
        cout << 0;
        return 0;
    }

    arr = new int[static_cast<int>(N)];
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    int exclude = round(0.15 * N);
    int result = 0;

    sort(arr, arr + static_cast<int>(N));

    for (int i = exclude; i < N - exclude; ++i)
    {
        result += arr[i];
    }
    cout << round(result / (N - 2 * exclude));

    delete[] arr;
}