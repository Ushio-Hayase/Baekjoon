#include <stdio.h>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <map>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
vector<pair<int, int>> start_point;
map<int, int> cnt;
int number[25][25];
bool visited[25][25] = { false, };

int x_dir[4] = { 1, -1, 0, 0 };
int y_dir[4] = { 0,0,1,-1};

void DFS(int i, int j) {
    for (int k = 0; k < 4; ++k) {
        int new_i = i + x_dir[k];
        int new_y = j + y_dir[k];
        if ((new_i >= 0 && new_i < N) && (new_y >=0 && new_y <N) && number[new_i][new_y] != 0 && !visited[new_i][new_y]) {
            number[new_i][new_y] = number[new_i][new_y] > number[i][j] ? number[i][j] :  number[new_i][new_y];
            visited[new_i][new_y] = true;
            DFS(new_i, new_y);
        }
    }
}

bool cmp(pair<int, int> a, pair<int,int> b) {
    return a.second < b.second;
}

int main()
{
    scanf("%d", &N);
    int home_number = 1;

    for (int i = 0; i < N; ++i) {
        string x;
        cin >> x;
        for (int j = 0; j < N; ++j) {
            int z = x[j] - '0';
            if (z == 1) {
                number[i][j] = home_number;
                home_number++;

            }
        }

    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (visited[i][j]) continue;
            if (number[i][j] != 0) DFS(i, j);
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (number[i][j] == 0) continue;
            cnt[number[i][j]]++;
        }
    }

    
    vector<int> res;

    for (auto i : cnt) {
        if (i.second == 0) continue;
        res.push_back(i.second);
    }

    printf("%d\n", res.size());
    sort(res.begin(), res.end());

    for (auto i : res) {
        printf("%d\n", i);
    }
}
