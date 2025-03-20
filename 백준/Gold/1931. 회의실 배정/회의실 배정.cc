#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> arr;

int main()
{
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int first, second;
        cin >> first >> second;
        arr.emplace_back(second, first);
    }

    std::sort(arr.begin(), arr.end());

    int cnt = 1;
    int ptr = 0;

    int endTime = arr[0].first;
    int tmp = endTime;

    while (++ptr < N)
    {
        if (tmp <= arr[ptr].second)
        {
            endTime = arr[ptr].first;
            cnt++;
            tmp = endTime;
        }
    }

    cout << cnt;
}
