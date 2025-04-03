#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> homes;
int finalResult = numeric_limits<int>::max();
vector<pair<int, int>> chickenHouse;
int cnt = 0;

int chickenDist(const vector<bool> &screenList, int row, int col)
{
    int result = 0;

    const int len = screenList.size();

    for (int i = 0; i < len; ++i)
    {
        if (screenList[i])
            continue;
        const int dist = abs(chickenHouse[i].first - row) + abs(chickenHouse[i].second - col);
        result = (dist < result || result == 0) ? dist : result;
    }

    return result;
}

void generateCombination(vector<bool> currentCombo, int startIdx, int size)
{
    if (cnt - M == size)
    {
        int result = 0;

        for (const auto &homeIter : homes)
        {

             result += chickenDist(currentCombo, homeIter.first, homeIter.second);
        }

        finalResult = result < finalResult ? result : finalResult;

        return;
    }

    for (int i = startIdx; i < cnt; ++i)
    {

        currentCombo[i] = true;
        generateCombination(currentCombo, i + 1, size + 1);
        currentCombo[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            int x;
            cin >> x;

            if (x == 1)
                homes.emplace_back(i, j);
            else if (x == 2)
            {
                chickenHouse.emplace_back(i, j);
                cnt++;
            }
        }

    vector<bool> removeChickenHouse(cnt);

    generateCombination(removeChickenHouse, 0, 0);

    cout << finalResult;
}