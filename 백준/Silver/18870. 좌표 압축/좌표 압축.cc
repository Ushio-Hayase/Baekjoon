#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N;
vector<int> arr;
vector<int> sortedArr;
set<int> exist;

int binarySearch(int left, int right, int target)
{
    if (sortedArr[left] == target) return left;
    if (sortedArr[right] == target) return right;

    int mid = (left + right) / 2;

    if (sortedArr[mid] >= target) return binarySearch(left, mid, target);

    return binarySearch(mid + 1, right, target);
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        if (!exist.contains(x))
        {
            sortedArr.push_back(x);

            exist.insert(x);
        }
        arr.push_back(x);
    }

    sort(sortedArr.begin(), sortedArr.end());

    for (int i = 0; i < arr.size(); ++i) cout << binarySearch(0, sortedArr.size() - 1, arr[i]) << " ";
}
