#include <iostream>
#include <queue>
#include <memory.h>
#include <vector>

#define q q123

using namespace std;

int N, M;

int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};

int *_data;
int **arr;

bool *_visitData;
bool **visitArr;

int leftSaveZone(int startSafeZoneCnt, queue<pair<int, int>> q)
{
    while (!q.empty())
    {
        const int row = q.front().first;
        const int col = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            const int newRow = row + dy[i];
            const int newCol = col + dx[i];

            if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M && !visitArr[newRow][newCol] &&
                arr[newRow][newCol] == 0)
            {
                visitArr[newRow][newCol] = true;
                q.emplace(newRow, newCol);
                startSafeZoneCnt--;
            }
        }
    }
    return startSafeZoneCnt;
}

int main()
{
    cin >> N >> M;

    queue<pair<int, int>> virusCoors;
    int safeZone = 0;

    _data = new int[N * M];
    _visitData = new bool[N * M];
    arr = new int *[N];
    visitArr = new bool *[N];

    for (int i = 0; i < N; ++i)
    {
        arr[i] = _data + i * M;
        visitArr[i] = _visitData + i * M;
        for (int j = 0; j < M; ++j)
        {
            int x;
            cin >> x;

            arr[i][j] = x;

            if (x == 0)
                safeZone++;
            else if (x == 2)
                virusCoors.emplace(i, j);
        }
    }

    int result = 0;

    for (int i = 0; i < N; ++i)

        for (int j = 0; j < M; ++j)
        {
            if (arr[i][j] != 0)
                continue;
            for (int k = 0; k < N; ++k)
                for (int l = 0; l < M; ++l)
                {
                    if (arr[k][l] != 0 || (k == i && l == j))
                        continue;
                    for (int m = 0; m < N; ++m)
                        for (int n = 0; n < M; ++n)
                        {
                            if (arr[m][n] != 0 || (m == i && n == j) || (m == k && n == l))
                                continue;
                            memset(_visitData, 0, M * N * sizeof(bool));
                            arr[i][j] = 1;
                            arr[k][l] = 1;
                            arr[m][n] = 1;
                            const int tmp = leftSaveZone(safeZone, virusCoors) - 3;
                            result = tmp > result ? tmp : result;
                            arr[i][j] = 0;
                            arr[k][l] = 0;
                            arr[m][n] = 0;
                        }
                }
        }

    cout << result;
}
