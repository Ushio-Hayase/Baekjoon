#include <stdio.h>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

int M, N;
int tomato[1000][1000];
bool visited[1000][1000] = {false, };
vector<pair<int, int>> start_point;
int dist[1000][1000];

int x_dir[4] = { 1, -1, 0, 0 };
int y_dir[4] = { 0,0,1,-1};

void bfs() {
    queue<pair<int, int>> q;
    for (auto& starting : start_point) {
        q.push(starting);
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int new_x = x + x_dir[i];
            int new_y = y + y_dir[i];
            

            if ((0 <= new_x && new_x < N)
                && (0 <= new_y && new_y < M)
                && !visited[new_x][new_y]
                && tomato[new_x][new_y] != -1) {
                q.push(make_pair(new_x, new_y));
                visited[new_x][new_y] = true;
                dist[new_x][new_y] = dist[x][y] + 1;
            }
        }
    }
}


int main()
{
    scanf("%d %d", &M, &N);
    bool all_ripe = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int x = 0;
            scanf("%d", &x);
            tomato[i][j] = x;
            if (x == 0) all_ripe = false;
            else if (x == 1) { 
                start_point.push_back(make_pair(i, j)); 
                visited[i][j] = true;
            }

        }
    }

    if (all_ripe) {
        printf("0");
        return 0;
    }

    bfs();

    int max = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (max < dist[i][j]) {
                max = dist[i][j];
            }
            else if (!visited[i][j] && tomato[i][j] != -1) {
                printf("-1");
                return 0;
            }
        }
    }

    printf("%d", max);
}
