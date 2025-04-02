#include <algorithm>
#include <iostream>

using namespace std;

int N, M;

int arr[9];
int num[9];
bool check[9];

void func(int len)
{
    if (len == M)
    {
        for (int i = 0; i < M; ++i)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if (!check[i])
        {
            arr[len] = num[i];
            check[i] = true;
            func(len + 1);
            check[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
        cin >> num[i];

    sort(num, num + N);

    func(0);
}