#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int LCS[1001][1001];

int main()
{
    string a, b;
    cin >> a;
    cin >> b;

    const int lenA = a.size();
    const int lenB = b.size();

    int maxLen = 0;

    for (int i = 0; i <= lenA; ++i)
        for (int j = 0; j <= lenB; ++j)
        {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }

    cout << LCS[lenA][lenB];
}
