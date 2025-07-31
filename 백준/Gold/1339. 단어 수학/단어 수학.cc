#include <bits/stdc++.h>

#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

int N;

int main()
{
    FAST_IO;

    cin >> N;

    unordered_map<char, int> value;
    unordered_map<char, int> mapping;
    vector<string> arr(N);

    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;

        int v = 0;

        for (int j = str.length() - 1; j >= 0; --j)
        {
            char c = str[j];
            value[c] += pow(10, str.length() - j - 1);
        }

        arr[i] = str;
    }

    vector<pair<char, int>> sort_char(value.begin(), value.end());

    sort(sort_char.begin(), sort_char.end(),
         [](const pair<char, int>& a, const pair<char, int>& b)
         { return a.second > b.second; });

    int num = 9;

    for (auto ch : sort_char)
    {
        mapping[ch.first] = num;
        num--;
    }

    int result = 0;

    for (auto item : arr)
    {
        int len = item.length();
        for (int i = 0; i < len; ++i)
        {
            result += pow(10, item.length() - i - 1) * mapping[item[i]];
        }
    }

    cout << result;
}
