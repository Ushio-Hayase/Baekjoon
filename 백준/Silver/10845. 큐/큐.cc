#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N;
queue<int> q;

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        if (str == "push")
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (str == "pop")
        {
            if (q.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            cout << q.front() << "\n";
            q.pop();
        }
        else if (str == "size")
        {
            cout << q.size() << "\n";
        }
        else if (str == "empty")
        {
            cout << (q.empty() ? 1 : 0) << "\n";
        }
        else if (str == "front")
        {
            if (q.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            cout << q.front() << "\n";
        }
        else if (str == "back")
        {
            if (q.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            cout << q.back() << "\n";
        }
    }
}