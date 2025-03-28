#include <iostream>
#include <vector>

using namespace std;

int N;
int* arrData;
int** arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    arrData = new int[N * N];
    arr = new int*[N];

    arr[0] = arrData;

    cin >> arr[0][0];

    for (int i = 1; i < N; ++i)
    {
        arr[i] = arrData + i * N;
        for (int j = 0; j < i + 1; ++j)
        {
            int x;
            cin >> x;
            if (j != 0)
                arr[i][j] = max(arr[i - 1][j - 1], arr[i - 1][j]) + x;
            else
                arr[i][j] = arr[i - 1][j] + x;
        };
    }

    int result = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result = arr[i][j] > result ? arr[i][j] : result;

    cout << result;
}