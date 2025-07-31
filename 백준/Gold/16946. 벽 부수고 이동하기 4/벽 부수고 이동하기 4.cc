#include <bits/stdc++.h>

using namespace std;

int N, M;
int drow[4] = {1, 0, -1, 0};
int dcol[4] = {0, 1, 0, -1};
int *visit_arr, *arr, *cluster, *result;
vector<int> elem_cnt;

int dfs(int* arr, int row, int col, int cluster_num)
{
    visit_arr[row * M + col] = true;
    cluster[row * M + col] = cluster_num;

    int cnt = 1;

    for (int i = 0; i < 4; ++i)
    {
        int new_row = row + drow[i];
        int new_col = col + dcol[i];

        if (0 <= new_row && new_row < N && 0 <= new_col && new_col < M)
        {
            if (!visit_arr[new_row * M + new_col] &&
                arr[new_row * M + new_col] == 0)
            {
                cnt += dfs(arr, new_row, new_col, cluster_num);
            }
        }
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int>> w_cnt;

    cin >> N >> M;

    arr = new int[N * M];
    visit_arr = new int[N * M];
    cluster = new int[N * M];
    result = new int[N * M];

    fill_n(visit_arr, N * M, false);
    fill_n(result, N * M, 0);

    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; ++j)
        {
            char c = str[j];

            int num = (c & 0x0F);
            arr[i * M + j] = num;
            if (num == 1) w_cnt.push_back({i, j});
        }
    }

    int cluster_num = 0;

    for (int i = 0; i < N * M; ++i)
    {
        if (!visit_arr[i] && arr[i] == 0)
        {
            int cnt = dfs(arr, i / M, i % M, cluster_num);
            elem_cnt.push_back(cnt);
            cluster_num++;
        }
    }

    for (auto& wall : w_cnt)
    {
        int cnt = 1;
        set<int> s;
        for (int i = 0; i < 4; ++i)
        {
            int row = wall.first + drow[i];
            int col = wall.second + dcol[i];
            if (0 <= row && row < N && 0 <= col && col < M &&
                arr[row * M + col] == 0)
                s.insert(cluster[row * M + col]);
        }
        for (auto elem : s) cnt += elem_cnt[elem];
        result[wall.first * M + wall.second] = cnt;
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j) cout << result[i * M + j] % 10;
        cout << '\n';
    }

    delete[] arr;
    delete[] visit_arr;
    delete[] cluster;
    delete[] result;
}