#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int levels[1000][1000];
vector<pair<int, int>> startPoints;

int moveX[4]{1, -1, 0, 0};
int moveY[4]{0, 0, 1, -1};

void bfs()
{
    queue<pair<int, pair<int, int>>> q;

    for (const auto& [startX, startY] : startPoints)
    {
        q.push({0, {startX, startY}});
    }

    while (!q.empty())
    {
        const int x = q.front().second.first;
        const int y = q.front().second.second;
        const int currentFloor = q.front().first;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            const int newX = x + moveX[i];
            const int newY = y + moveY[i];

            if (newX >= 0 && newX < M && newY >= 0 && newY < N && levels[newY][newX] > 0 &&
                currentFloor + 1 < levels[newY][newX])
            {
                q.push({currentFloor + 1, {newX, newY}});

                levels[newY][newX] = currentFloor + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int x;
            cin >> x;

            if (x == 1)
            {
                startPoints.emplace_back(j, i);
                levels[i][j] = 0;
            }
            else if (x == 0)
                levels[i][j] = numeric_limits<int>::max();
            else
            {
                levels[i][j] = -1;
            }
        }
    }

    int result = 0;

    bfs();

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            int tmp = levels[i][j];
            result = tmp > result ? tmp : result;
            if (tmp == numeric_limits<int>::max())
            {
                cout << -1;
                return 0;
            }
        }

    cout << result;
}
