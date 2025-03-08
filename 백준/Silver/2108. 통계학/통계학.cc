#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
vector<int> freq(8e+3 + 1);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    double aver = 0;
    int minValue = 4000;
    int maxValue = -4000;

    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        aver += x;
        freq[x + 4000]++;
        arr.push_back(x);
        if (x > maxValue) maxValue = x;
        if (x < minValue) minValue = x;
    }

    int averageResult = round(aver / N);

    cout << (averageResult == -0 ? 0 : averageResult) << "\n";

    sort(arr.begin(), arr.end());

    cout << arr[N / 2] << "\n";
    vector<int> freqMaxList;
    int freqMax = 0;

    for (int i = 0; i <= 8e+3; ++i)
    {
        int x = freq[i];
        if (x > freqMax)
        {
            freqMax = x;
            freqMaxList.clear();
            freqMaxList.push_back(i - 4000);
        }
        else if (x == freqMax)
            freqMaxList.push_back(i - 4000);
    }

    if (freqMaxList.size() > 1)
    {
        sort(freqMaxList.begin(), freqMaxList.end());
        cout << freqMaxList[1] << "\n";
    }
    else
        cout << freqMaxList[0] << "\n";

    cout << maxValue - minValue;
}