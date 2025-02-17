#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<int> arr[4];

int main()
{
    cin >> N;

    int cnt = 0;
    int i = 223;

    for (int i = 1; i <= 223; ++i)
    {
        if (i * i == N)
        {
            cout << 1;
            return 0;
        }
        arr[1].push_back(i * i);
    }

    for (const auto& tmp : arr[1])
    {
        for (int j = 1; j <= 158; ++j)
        {
            if (tmp + j * j == N)
            {
                cout << 2;
                return 0;
            }
            arr[2].push_back(tmp + j * j);
        }
    }

    for (const auto& tmp : arr[2])
    {
        for (int j = 1; j <= 129; ++j)
        {
            if (tmp + j * j == N)
            {
                cout << 3;
                return 0;
            }
            arr[3].push_back(tmp + j * j);
        }
    }

    for (const auto& tmp : arr[3])
    {
        for (int j = 1; j <= 111; ++j)
        {
            if (tmp + j * j == N)
            {
                cout << 4;
                return 0;
            }
        }
    }
}