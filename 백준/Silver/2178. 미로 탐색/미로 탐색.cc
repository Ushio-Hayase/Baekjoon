#include <iostream>
#include <queue>
#include <string>

int N, M;

int road[101][101];
bool visit[101][101];
int moveX[4]{1, -1, 0, 0};
int moveY[4]{0, 0, 1, -1};

int bfs()
{
    std::queue<std::pair<int, int>> q;
    std::queue<int> distance;
    q.emplace(1, 1);
    distance.push(1);
    visit[1][1] = true;

    int nowDistance;

    while (!q.empty())
    {
        const int x = q.front().first;
        const int y = q.front().second;
        nowDistance = distance.front();
        q.pop();
        distance.pop();
        if (x == M && y == N) return nowDistance;
        for (int i = 0; i < 4; ++i)
        {
            int newX = x + moveX[i];
            int newY = y + moveY[i];

            if (newX > 0 && newX <= M && newY > 0 && newY <= N && !visit[newY][newX] && road[newY][newX] == 1)
            {
                q.emplace(newX, newY);
                visit[newY][newX] = true;
                distance.push(nowDistance + 1);
            }
        }
    }

    return nowDistance;
}

int main()
{
    std::cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        std::string str;
        std::cin >> str;
        for (int j = 1; j <= M; ++j) road[i][j] = str[j - 1] - '0';
    }

    std::cout << bfs();
}
