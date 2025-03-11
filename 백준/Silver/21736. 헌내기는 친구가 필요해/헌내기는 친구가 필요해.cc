#include <iostream>

int N, M;

char* data;
char** arr;
bool visit[600][600];
int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};

int dfs(int x, int y)
{
    visit[y][x] = true;
    int visitPeople = arr[y][x] == 'P' ? 1 : 0;

    for (int i = 0; i < 4; ++i)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= M || newX < 0 || newY >= N || newY < 0) continue;
        if (visit[newY][newX]) continue;
        if (arr[newY][newX] == 'X') continue;
        visitPeople += dfs(newX, newY);
    }

    return visitPeople;
}

int main()
{
    std::cin >> N >> M;

    int startX, startY;

    data = new char[N * M];
    arr = new char*[N];

    for (int i = 0; i < N; ++i)
    {
        arr[i] = data + (i * M);
        for (int j = 0; j < M; ++j)
        {
            arr[i][j] = data[i * M + j];
            char x;
            std::cin >> x;
            arr[i][j] = x;
            if (x == 'I')
            {
                startX = j;
                startY = i;
            }
        }
    }

    int result = dfs(startX, startY);

    if (result == 0)
        std::cout << "TT";
    else
        std::cout << result;

    delete[] data;
    delete[] arr;
}