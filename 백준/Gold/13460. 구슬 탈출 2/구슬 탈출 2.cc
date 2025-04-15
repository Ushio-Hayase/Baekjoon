#include <cmath>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

constexpr int INF = 1e+9;

int N, M;

int arr[16][16];
pair<int, int> red, blue;

int dr[4]{1, -1, 0, 0};
int dc[4]{0, 0, 1, -1};

set<pair<pair<int, int>, pair<int, int>>> visit;

int bfs()
{
    queue<pair<pair<pair<int, int>, pair<int, int>>, int>> q;
    q.push({{red, blue}, 0});

    int cnt = 0;

    int result = INF;

    while (!q.empty())
    {
        const int redRow = q.front().first.first.first;
        const int redCol = q.front().first.first.second;
        const int blueRow = q.front().first.second.first;
        const int blueCol = q.front().first.second.second;
        const int level = q.front().second;

        if (level >= 10) return -1;

        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int redNewRow = redRow;
            int redNewCol = redCol;
            int blueNewRow = blueRow;
            int blueNewCol = blueCol;

            bool redIn = false;
            bool blueIn = false;

            if (dr[i] != 0)
            {
                if ((redRow <= blueRow && dr[i] > 0) ||
                    (redRow >= blueRow && dr[i] < 0))
                {
                    if (arr[blueNewRow + dr[i]][blueNewCol] == 1) blueIn = true;
                    while ((arr[blueNewRow + dr[i]][blueNewCol] == 0 ||
                            arr[blueNewRow + dr[i]][blueNewCol] == 1) &&
                           (blueNewRow + dr[i] != redNewRow ||
                            blueNewCol != redNewCol))
                    {
                        blueNewRow += dr[i];
                        if (arr[blueNewRow + dr[i]][blueNewCol] == 1)
                            blueIn = true;
                    }
                    if (arr[redNewRow + dr[i]][redNewCol] == 1) redIn = true;

                    while ((arr[redNewRow + dr[i]][redNewCol] == 0 ||
                            arr[redNewRow + dr[i]][redNewCol] == 1) &&
                           (blueNewRow != redNewRow + dr[i] ||
                            blueNewCol != redNewCol))
                    {
                        redNewRow += dr[i];
                        if (arr[redNewRow + dr[i]][redNewCol] == 1)
                            redIn = true;
                    }
                }
                else
                {
                    if (arr[redNewRow + dr[i]][redNewCol] == 1) redIn = true;

                    while ((arr[redNewRow + dr[i]][redNewCol] == 0 ||
                            arr[redNewRow + dr[i]][redNewCol] == 1) &&
                           (blueNewRow != redNewRow + dr[i] ||
                            blueNewCol != redNewCol))
                    {
                        redNewRow += dr[i];
                        if (arr[redNewRow + dr[i]][redNewCol] == 1)
                            redIn = true;
                    }
                    if (arr[blueNewRow + dr[i]][blueNewCol] == 1) blueIn = true;
                    while ((arr[blueNewRow + dr[i]][blueNewCol] == 0 ||
                            arr[blueNewRow + dr[i]][blueNewCol] == 1) &&
                           (blueNewRow + dr[i] != redNewRow ||
                            blueNewCol != redNewCol))
                    {
                        blueNewRow += dr[i];
                        if (arr[blueNewRow + dr[i]][blueNewCol] == 1)
                            blueIn = true;
                    }
                }
            }
            if (dc[i] != 0)
            {
                if ((redCol <= blueCol && dc[i] > 0) ||
                    (redCol >= blueCol && dc[i] < 0))
                {
                    if (arr[blueNewRow][blueNewCol + dc[i]] == 1) blueIn = true;
                    while ((arr[blueNewRow][blueNewCol + dc[i]] == 0 ||
                            arr[blueNewRow][blueNewCol + dc[i]] == 1) &&
                           (blueNewRow != redNewRow ||
                            blueNewCol + dc[i] != redNewCol))
                    {
                        blueNewCol += dc[i];
                        if (arr[blueNewRow][blueNewCol + dc[i]] == 1)
                            blueIn = true;
                    }
                    if (arr[redNewRow][redNewCol + dc[i]] == 1) redIn = true;
                    while ((arr[redNewRow][redNewCol + dc[i]] == 0 ||
                            arr[redNewRow][redNewCol + dc[i]] == 1) &&
                           (blueNewRow != redNewRow ||
                            blueNewCol != redNewCol + dc[i]))
                    {
                        redNewCol += dc[i];
                        if (arr[redNewRow][redNewCol + dc[i]] == 1)
                            redIn = true;
                    }
                }
                else
                {
                    if (arr[redNewRow][redNewCol + dc[i]] == 1) redIn = true;
                    while ((arr[redNewRow][redNewCol + dc[i]] == 0 ||
                            arr[redNewRow][redNewCol + dc[i]] == 1) &&
                           (blueNewRow != redNewRow ||
                            blueNewCol != redNewCol + dc[i]))
                    {
                        redNewCol += dc[i];
                        if (arr[redNewRow][redNewCol + dc[i]] == 1)
                            redIn = true;
                    }
                    if (arr[blueNewRow][blueNewCol + dc[i]] == 1) blueIn = true;
                    while ((arr[blueNewRow][blueNewCol + dc[i]] == 0 ||
                            arr[blueNewRow][blueNewCol + dc[i]] == 1) &&
                           (blueNewRow != redNewRow ||
                            blueNewCol + dc[i] != redNewCol))
                    {
                        blueNewCol += dc[i];
                        if (arr[blueNewRow][blueNewCol + dc[i]] == 1)
                            blueIn = true;
                    }
                }
            }

            if (!redIn && !blueIn &&
                visit.find({{redNewRow, redNewCol},
                            {blueNewRow, blueNewCol}}) == visit.end())
            {
                visit.insert(
                    {{redNewRow, redNewCol}, {blueNewRow, blueNewCol}});
                q.push({{{redNewRow, redNewCol}, {blueNewRow, blueNewCol}},
                        level + 1});
            }
            else if (redIn && !blueIn)
                return level + 1;
        }
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            char x;
            cin >> x;
            if (x == '#')
                arr[i][j] = -1;
            else if (x == '.')
                arr[i][j] = 0;
            else if (x == 'R')
            {
                red = {i, j};
                arr[i][j] = 0;
            }
            else if (x == 'B')
            {
                blue = {i, j};
                arr[i][j] = 0;
            }
            else if (x == 'O')
                arr[i][j] = 1;
        }

    int result = bfs();

    cout << (result == INF ? -1 : result);
}
