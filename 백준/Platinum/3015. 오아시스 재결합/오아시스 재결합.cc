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

    long long result = 0;

    stack<pair<int, int>> st;

    for (int i = 0; i < N; ++i)
    {
        int height;
        cin >> height;

        int count = 1;

        while (!st.empty() && st.top().first <= height)
        {
            result += st.top().second;
            if (st.top().first == height)
            {
                count += st.top().second;
            }
            st.pop();
        }
        if (!st.empty())
        {
            result++;
        }
        st.push({height, count});
    }

    cout << result;
}
