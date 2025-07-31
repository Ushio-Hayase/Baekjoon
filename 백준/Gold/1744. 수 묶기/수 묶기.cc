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

    vector<int> ne;
    vector<int> po;
    vector<int> zero;

    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        if (x > 0)
            po.push_back(x);
        else if (x < 0)
            ne.push_back(x);
        else
            zero.push_back(x);
    }

    sort(ne.begin(), ne.end(), greater<int>());
    sort(po.begin(), po.end());

    int result = 0;
    while (po.size() != 0 || ne.size() != 0)
    {
        if (po.size() > 1)
        {
            int a = po.back();
            int b = po[po.size() - 2];
            if (a == 1 || b == 1)
                result += a + b;
            else
                result += a * b;
            po.pop_back();
            po.pop_back();
        }
        else if (po.size() == 1)
        {
            result += po.back();
            po.pop_back();
        }

        if (ne.size() > 1)
        {
            int a = ne.back();
            int b = ne[ne.size() - 2];
            result += a * b;
            ne.pop_back();
            ne.pop_back();
        }
        else if (ne.size() == 1)
        {
            if (zero.size() == 0) result += ne.back();
            ne.pop_back();
        }
    }

    cout << result;
}
