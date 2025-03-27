#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> ans;

void func(vector<int> prevNumbers, int len)
{
    if (len >= M)
    {
        ans.push_back(prevNumbers);
        return;
    }

    if (len == 0)
    {
        for (int i = 1; i <= N; ++i)
        {
            vector<int> tmp;
            tmp.push_back(i);
            func(tmp, len + 1);
        }
    }
    else

        for (int i = prevNumbers.back() + 1; i <= N; ++i)
        {
            vector<int> tmp{prevNumbers};
            tmp.push_back(i);
            func(tmp, len + 1);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    vector<int> x;
    func(x, 0);

    for (const auto& iter1 : ans)
    {
        for (const auto& iter2 : iter1) cout << iter2 << " ";
        cout << "\n";
    }
}