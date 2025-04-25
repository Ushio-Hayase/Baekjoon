#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N, M;

int arr[8];
set<vector<int>> sets;

void dfs(vector<int> v, vector<int> canUsingNum)
{
    if (v.size() == M)
    {
        if (sets.find(v) == sets.end()) sets.insert(v);
        return;
    }

    for (auto num : canUsingNum)
    {
        vector<int> tmp1(v);
        vector<int> tmp2(canUsingNum);
        tmp1.push_back(num);
        tmp2.erase(find(tmp2.begin(), tmp2.end(), num));
        dfs(tmp1, tmp2);
    }
}

int main()
{
    cin >> N >> M;

    vector<int> usingNum;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        usingNum.push_back(arr[i]);
    }

    vector<int> v;
    dfs(v, usingNum);

    for (auto iter = sets.begin(); iter != sets.end(); iter++)
    {
        for (int j = 0; j < M; ++j)
        {
            cout << (*iter)[j] << " ";
        }
        cout << "\n";
    }
}