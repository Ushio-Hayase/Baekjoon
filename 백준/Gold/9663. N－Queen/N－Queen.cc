#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> visit(16);

int dfs(int currentFloor)
{
    if (currentFloor >= N) return 1;
    int visitCnt = 0;
    for (int i = 0; i < N; ++i)
    {
        visit[currentFloor] = i;

        bool canDeploy = true;

        for (int j = 0; j < currentFloor; j++)
        {
            if (visit[currentFloor] == visit[j] ||
                currentFloor - j == abs(visit[currentFloor] - visit[j]))
            {
                canDeploy = false;
                break;
            }
        }

        if (canDeploy) visitCnt += dfs(currentFloor + 1);
    }

    return visitCnt;
}

int main()
{
    int result = 0;

    cin >> N;

    result = dfs(0);

    cout << result;
}
