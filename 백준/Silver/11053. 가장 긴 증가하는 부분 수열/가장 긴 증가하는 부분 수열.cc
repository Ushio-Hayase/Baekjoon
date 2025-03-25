#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int N, len;
int A[1001]{};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        int x;
        cin >> x;

        auto pos = lower_bound(A + 1, A + len + 1, x);
        *pos = x;
        if (pos == A + len + 1) len++;
    }

    cout << len;
}
