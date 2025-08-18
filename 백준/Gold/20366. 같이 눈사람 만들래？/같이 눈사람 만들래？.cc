#include <bits/stdc++.h>

#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

int N;
vector<int> arr;

int main()
{
    FAST_IO;

    cin >> N;

    arr.resize(N);

    for (int i = 0; i < N; ++i) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int result = 2000000000 + 1;

    for (int i = 0; i < N - 3; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            int left, right;
            left = i + 1;
            right = j - 1;
            while (left < right)
            {
                int elza = arr[right] + arr[left];
                int anna = arr[i] + arr[j];
                int diff = elza - anna;
                result = min(abs(diff), result);
                if (diff == 0)
                {
                    cout << 0;
                    return 0;
                }
                if (anna < elza)
                    --right;
                else
                    ++left;
            }
        }
    }

    cout << result;
}