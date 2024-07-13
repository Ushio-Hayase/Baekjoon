#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int cache[12];

int recur(int num)
{
    if (num == 1)
        return 1;
    if (num == 2)
        return 2;
    if (num == 3)
        return 4;
    if (cache[num] != -1)
        return cache[num];
    return cache[num] = recur(num - 1) + recur(num - 2) + recur(num - 3);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        memset(cache, -1, sizeof(cache));
        cout << recur(n) << '\n';
    }

    return 0;
}