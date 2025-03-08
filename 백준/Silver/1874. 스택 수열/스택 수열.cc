#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int N;
queue<int> waitQueue;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    stack<int> mainStack;
    queue<int> targetQueue;
    queue<char> mainQueue;

    for (int i = 1; i <= N; ++i)
    {
        waitQueue.push(i);
        int x;
        cin >> x;
        targetQueue.push(x);
    }

    int x = waitQueue.front();
    waitQueue.pop();
    mainStack.push(x);
    mainQueue.push('+');

    while (!targetQueue.empty())
    {
        if (!mainStack.empty() && mainStack.top() == targetQueue.front())
        {
            waitQueue.push(mainStack.top());
            mainStack.pop();
            mainQueue.push('-');
            targetQueue.pop();
        }
        else if (waitQueue.front() <= targetQueue.front())
        {
            mainStack.push(waitQueue.front());
            waitQueue.pop();
            mainQueue.push('+');
        }
        else if (waitQueue.front() == targetQueue.front())
        {
            waitQueue.push(mainStack.top());
            mainStack.pop();
            mainQueue.push('-');
            targetQueue.pop();
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    int sz = mainQueue.size();

    for (int i = 0; i < sz; ++i)
    {
        char x = mainQueue.front();
        mainQueue.pop();
        cout << x << "\n";
    }
}