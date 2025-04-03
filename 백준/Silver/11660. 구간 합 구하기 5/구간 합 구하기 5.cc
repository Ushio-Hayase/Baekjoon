#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int N, M;
int *arrData;
int **arr;

int *sumData;
int **sum;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    arrData = new int[N * N];
    arr = new int *[N];

    sumData = new int[(N + 1) * (N + 1)];
    sum = new int *[N + 1];

    for (int i = 0; i <= N; ++i)
    {
        arr[i] = arrData + i * N;
        sum[i] = sumData + i * (N + 1);
        for (int j = 0; j <= N; ++j)
        {
            if (i != N && j != N)
                cin >> arr[i][j];
            if (i != 0 && j != 0)
                sum[i][j] = arr[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            else
                sum[i][j] = 0;
        }
    }
    sum[N] = sumData + N * (N + 1);

    for (int i = 0; i < M; ++i)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << "\n";
    }
}