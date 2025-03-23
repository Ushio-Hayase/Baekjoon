#include <array>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

int N, M, H;
int levels[100][100][100];
vector<array<int, 3>> startPoints;

int moveX[6]{1, -1, 0, 0, 0, 0};
int moveY[6]{0, 0, 1, -1, 0, 0};
int moveZ[6]{0, 0, 0, 0, 1, -1};

void bfs()
{
    queue<pair<int, array<int, 3>>> q;

    for (const auto& [startZ, startX, startY] : startPoints)
    {
        q.push({0, {startZ, startX, startY}});
    }

    while (!q.empty())
    {
        const int x = q.front().second[2];
        const int y = q.front().second[1];
        const int z = q.front().second[0];
        const int currentFloor = q.front().first;
        q.pop();

        for (int i = 0; i < 6; ++i)
        {
            const int newX = x + moveX[i];
            const int newY = y + moveY[i];
            const int newZ = z + moveZ[i];

            if (newX >= 0 && newX < M && newY >= 0 && newY < N && newZ >= 0 && newZ < H &&
                levels[newZ][newY][newX] > 0 && currentFloor + 1 < levels[newZ][newY][newX])
            {
                q.push({currentFloor + 1, {newZ, newY, newX}});

                levels[newZ][newY][newX] = currentFloor + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> H;
    for (int f = 0; f < H; ++f)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                int x;
                cin >> x;

                if (x == 1)
                {
                    startPoints.push_back({f, i, j});
                    levels[f][i][j] = 0;
                }
                else if (x == 0)
                    levels[f][i][j] = numeric_limits<int>::max();
                else
                {
                    levels[f][i][j] = -1;
                }
            }
        }
    }

    int result = 0;

    bfs();

    for (int f = 0; f < H; ++f)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
                int tmp = levels[f][i][j];
                result = tmp > result ? tmp : result;
                if (tmp == numeric_limits<int>::max())
                {
                    cout << -1;
                    return 0;
                }
            }

    cout << result;
}
