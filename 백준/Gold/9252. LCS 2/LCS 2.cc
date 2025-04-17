#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;

int main()
{
    string str1;
    string str2;

    cin >> str1;
    cin >> str2;

    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    for (int i = 1; i <= str1.size(); ++i)
    {
        for (int j = 1; j <= str2.size(); ++j)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string lcs = "";
    int i = str1.size(), j = str2.size();
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs = str1[i - 1] + lcs;
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            --i;
        }
        else
        {
            --j;
        }
    }

    cout << dp[str1.size()][str2.size()] << "\n";
    cout << lcs;
}