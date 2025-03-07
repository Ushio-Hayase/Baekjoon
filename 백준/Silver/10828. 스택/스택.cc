#include <iostream>
#include <stack>
#include <string>

using namespace std;

int N;
stack<int> q;

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
            cout << q.top() << "\n";
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
        else if (str == "top")
        {
            if (q.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            cout << q.top() << "\n";
        }
    }
}