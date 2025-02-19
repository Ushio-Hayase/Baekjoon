#include <array>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
char** arr;
bool** visited;

int move_x[4]{1, -1, 0, 0};
int move_y[4]{0, 0, 1, -1};

int func(int start_x, int start_y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(start_x, start_y));

    int cnt = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int new_x = x + move_x[i];
            int new_y = y + move_y[i];

            if (new_x >= M || new_x < 0 || new_y >= N || new_y < 0) continue;
            if (arr[new_y][new_x] == 'X') continue;
            if (visited[new_y][new_x]) continue;
            if (arr[new_y][new_x] == 'P') cnt++;

            q.push(make_pair(new_x, new_y));
            visited[new_y][new_x] = true;
        }
    }

    return cnt;
}

int main()
{
    cin >> N >> M;

    arr = new char*[N];
    visited = new bool*[N];

    int y, x;

    for (int i = 0; i < N; ++i)
    {
        arr[i] = new char[M];
        visited[i] = new bool[M];
        for (int j = 0; j < M; ++j)
        {
            visited[i][j] = false;
            cin >> arr[i][j];
            if (arr[i][j] == 'I')
            {
                y = i;
                x = j;
            }
        }
    }

    int result = func(x, y);

    if (result == 0)
        cout << "TT";
    else
        cout << result;
}