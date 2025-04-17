#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int binarySearch(vector<int>& vec, int val, int start, int end)
{
    int mid = (start + end) / 2;
    if (end - start <= 1) return start;

    if (val > vec[mid])
        return binarySearch(vec, val, mid, end);
    else if (val <= vec[mid])
        return binarySearch(vec, val, start, mid);
}

int main()
{
    cin >> N;

    int* arr = new int[N];
    vector<int> lcs;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; ++i)
    {
        auto idx = lower_bound(lcs.begin(), lcs.end(), arr[i]);

        if (idx == lcs.end())
            lcs.push_back(arr[i]);
        else

            *idx = arr[i];
    }

    cout << lcs.size();
}