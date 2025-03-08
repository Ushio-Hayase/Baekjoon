#include <algorithm>
#include <iostream>
#include <list>
#include <queue>

using namespace std;

int N, M;
vector<int> arr(10);
list<int> li;

int getImportance()
{
    for (int i = 9; i > 0; --i)
        if (arr[i] != 0)
        {
            arr[i]--;
            return i;
        }
}

void func()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        li.emplace_back(x);
        arr[x]++;
    }

    int cnt = 0;
    auto targetIter = li.begin();
    while (M > 0)
    {
        targetIter++;
        M--;
    }

    auto iter = li.begin();

    int idx = 0;

    while (true)
    {
        if (iter == li.end())
        {
            iter = li.begin();
            idx = 0;
        }
        int targetImportance = getImportance();
        while (*iter != targetImportance)
        {
            iter++;
            idx++;
            if (iter == li.end())
            {
                iter = li.begin();
                idx = 0;
            }
        }
        cnt++;
        if (iter == targetIter)
        {
            cout << cnt << "\n";
            return;
        };
        list<int>::iterator removeIter = li.begin();
        while (removeIter != iter) removeIter++;

        iter++;

        li.erase(removeIter);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCaseCount;
    cin >> testCaseCount;

    while (testCaseCount > 0)
    {
        func();
        li.clear();
        for (int i = 0; i < 10; ++i) arr[i] = 0;
        testCaseCount--;
    }
}