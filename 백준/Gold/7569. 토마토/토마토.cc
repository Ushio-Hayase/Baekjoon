#include <stdio.h>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

int M, N, H;
int tomato[100][100][100];
bool visited[100][100][100] = {false, };
vector<tuple<int ,int, int>> start_point;
int dist[100][100][100] = { 0, };

int x_dir[6] = { 1, -1, 0, 0, 0,0 };
int y_dir[6] = { 0,0,1,-1,0,0 };
int z_dir[6] = { 0,0,0,0,1,-1 };

void bfs() {
    queue<tuple<int, int, int>> q;
    for (auto start : start_point) {
        q.push(make_tuple(get<0>(start), get<1>(start), get<2>(start)));
    }

    while (!q.empty()) {
        int width = get<2>(q.front());
        int length = get<1>(q.front());
        int height = get<0>(q.front());

        q.pop();

        for (int i = 0; i < 6; ++i) {
            int x_new = width + x_dir[i];
            int y_new = height + y_dir[i];
            int z_new = length + z_dir[i];

            if ((0 <= x_new && x_new < M)
                && (0 <= y_new && y_new < H)
                && (0 <= z_new && z_new < N)
                && !visited[y_new][z_new][x_new] 
                && tomato[y_new][z_new][x_new] == 0) {
                visited[y_new][z_new][x_new] = true;
                q.push(make_tuple(y_new, z_new, x_new));
                dist[y_new][z_new][x_new] = dist[height][length][width] + 1;
            }
        }
    }
}


int main()
{
    scanf("%d %d %d", &M, &N, &H);
    bool all_ripe = true;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < M; ++k) {
                int x;
                scanf("%d", &x);
                tomato[i][j][k] = x;
                if (x == 1) {
                    visited[i][j][k] = true;
                    start_point.push_back(make_tuple(i,j,k));
                    dist[i][j][k] = 0;
                }
                else if (x == 0) {
                    all_ripe = false;
                }
                else {
                    visited[i][j][k] = true;
                }
            }
    if (all_ripe) {
        printf("0");
        return 0;
    }

    bfs();

    int count = 0;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < M; ++k) {
                if (!visited[i][j][k]) {
                    printf("-1");
                    return 0;
                }
                else if (dist[i][j][k] > count)
                    count = dist[i][j][k];
            }
    printf("%d", count);
}
