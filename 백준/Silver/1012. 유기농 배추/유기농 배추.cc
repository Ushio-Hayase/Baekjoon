#include <iostream>
#include <memory.h>

using namespace std;

int n , m, cabbage;
bool a[51][51];
bool check[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool dfs(int y, int x) {
    if (check[y][x]) return false;
    check[y][x] = true;
    
    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i]; 
        int next_y = y + dy[i];

        if (next_x >= 0 && next_y >= 0 && next_x < m && next_y < n && a[next_y][next_x]) 
        dfs(next_y, next_x);
    }
    return true;
}

int main(void) {
    int TC;
    cin >> TC;
    for (int i = 0; i < TC; i++) {
        cin >> m >> n >> cabbage;
        memset(a, 0, sizeof(a));
        memset(check, 0, sizeof(check));

        for (int j = 0; j < cabbage; j++) {
            int x = 0, y = 0;
            cin >> x >> y;
            a[y][x] = 1;
        }

        int bug_count = 0;

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (a[j][k] && !check[j][k]) {
                    if (dfs(j, k)) bug_count++;
                }
            }
        }
        cout << bug_count << "\n";
    }
}