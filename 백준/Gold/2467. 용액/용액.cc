#include <cmath>
#include <iostream>
#include <vector>

constexpr int INF = 1e+9 * 2;

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    vector<int> arr;

    arr.resize(N);

    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    int left = 0;
    int right = N - 1;
    int result = INF;

    pair<int, int> answer;

    while (right - left >= 1)
    {
        int tmp = arr[left] + arr[right];
        if (abs(tmp) < abs(result))
        {
            answer.first = arr[left];
            answer.second = arr[right];
            result = tmp;
        }

        if (tmp > 0)
            right--;
        else
            left++;
    }

    cout << answer.first << " " << answer.second;
}
