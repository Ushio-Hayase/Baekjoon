#include <iostream>
#include <queue>

using namespace std;

int N;

int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};

void moveArr(vector<vector<int>>& arr, int deltaX, int deltaY)
{
    if (deltaX > 0)
    {
        for (int j = 0; j < N; ++j)
        {
            int blockCol = N;  // 블록이 있는 칸 중 열이 가장 작은 수
            vector<bool> notMerge(N);
            for (int i = N - 1; i >= 0; --i)
            {
                if (arr[j][i] == 0) continue;

                // 현위치 블록과 블록이 도착할 칸 다음 칸 블록이 같은 수라면
                if (blockCol < N && arr[j][i] == arr[j][blockCol] &&
                    !notMerge[blockCol])
                {
                    arr[j][blockCol] *= 2;
                    arr[j][i] = 0;
                    notMerge[blockCol] = true;
                }
                else
                {
                    arr[j][blockCol - 1] = arr[j][i];
                    if (blockCol - 1 != i) arr[j][i] = 0;
                    blockCol -= 1;  // 블록이 있는 칸 갱신
                }
            }
        }
    }
    else if (deltaX < 0)
    {
        for (int j = 0; j < N; ++j)
        {
            int blockCol = -1;  // 블록이 있는 칸 중 열이 가장 큰 수
            vector<bool> notMerge(N);
            for (int i = 0; i < N; ++i)
            {
                if (arr[j][i] == 0) continue;

                // 현위치 블록과 블록이 도착할 칸 다음 칸 블록이 같은 수라면
                if (blockCol > -1 && arr[j][i] == arr[j][blockCol] &&
                    !notMerge[blockCol])
                {
                    arr[j][blockCol] *= 2;
                    arr[j][i] = 0;
                    notMerge[blockCol] = true;
                }
                else
                {
                    arr[j][blockCol + 1] = arr[j][i];
                    if (blockCol + 1 != i) arr[j][i] = 0;
                    blockCol += 1;  // 블록이 있는 칸 갱신
                }
            }
        }
    }
    else if (deltaY > 0)
    {
        for (int j = 0; j < N; ++j)
        {
            int blockRow = N;  // 블록이 있는 칸 중 행이 가장 작은 수
            vector<bool> notMerge(N);
            for (int i = N - 1; i >= 0; --i)
            {
                if (arr[i][j] == 0) continue;

                // 현위치 블록과 블록이 도착할 칸 다음 칸 블록이 같은 수라면
                if (blockRow < N && arr[i][j] == arr[blockRow][j] &&
                    !notMerge[blockRow])
                {
                    arr[blockRow][j] *= 2;
                    arr[i][j] = 0;
                    notMerge[blockRow] = true;
                }
                else
                {
                    arr[blockRow - 1][j] = arr[i][j];
                    if (blockRow - 1 != i) arr[i][j] = 0;
                    blockRow -= 1;  // 블록이 있는 칸 갱신
                }
            }
        }
    }
    else if (deltaY < 0)
    {
        for (int j = 0; j < N; ++j)
        {
            int blockRow = -1;
            vector<bool> notMerge(N);
            for (int i = 0; i < N; ++i)
            {
                if (arr[i][j] == 0) continue;
                if (blockRow > -1 && arr[i][j] == arr[blockRow][j] &&
                    !notMerge[blockRow])
                {
                    arr[blockRow][j] *= 2;
                    arr[i][j] = 0;
                    notMerge[blockRow] = true;
                }
                else
                {
                    arr[blockRow + 1][j] = arr[i][j];
                    if (blockRow + 1 != i) arr[i][j] = 0;
                    blockRow += 1;  // 블록이 있는 칸 갱신
                }
            }
        }
    }
}

int bfs(const vector<vector<int>>& init)
{
    queue<pair<int, vector<vector<int>>>> q;

    q.push({0, init});

    int result = 0;

    while (!q.empty())
    {
        const int level = q.front().first;

        for (int i = 0; i < 4; ++i)
        {
            vector<vector<int>> arr(q.front().second);
            moveArr(arr, dx[i], dy[i]);
            if (level == 4)
            {
                int tmp = 0;
                for (int j = 0; j < N; ++j)
                    for (int k = 0; k < N; ++k)
                        result = arr[j][k] > result ? arr[j][k] : result;
            }
            else
            {
                q.push({level + 1, arr});
            }
        }
        q.pop();
    }

    return result;
}

int main()
{
    vector<vector<int>> arr;
    cin >> N;

    arr.resize(N);

    for (int i = 0; i < N; ++i)
    {
        arr[i].resize(N);
        for (int j = 0; j < N; ++j)
        {
            cin >> arr[i][j];
        }
    }

    cout << bfs(arr);
}