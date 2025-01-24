#include <memory.h>

#include <iostream>
#include <map>
#include <string>

using namespace std;

int N;
int arr[100][100];

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
            {
                if (arr[j][k] != 1)
                    arr[j][k] = arr[j][i] == 1 && arr[i][k] == 1 ? 1 : 0;
            }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j) cout << arr[i][j] << " ";
        cout << "\n";
    }
}