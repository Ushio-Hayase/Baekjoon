#include <iostream>
#include <map>
#include <string>

using namespace std;

int N, M;
map<int, int> container;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        if (container.find(x) == container.end())
            container[x] = 1;
        else
            container[x]++;
    }

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int x;
        cin >> x;
        cout << container[x] << " ";
    }
}