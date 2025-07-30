#include <iostream>

using namespace std;

int find(int* arr, int x)
{
    if (arr[x] == x)
        return arr[x];
    else
        return arr[x] = find(arr, arr[x]);
}

void union_(int* arr, int a, int b)
{
    int pa = find(arr, a);
    int pb = find(arr, b);

    if (pa <= pb)
        arr[pb] = pa;
    else
        arr[pa] = pb;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int gate_cnt, plane_cnt;
    cin >> gate_cnt >> plane_cnt;

    int* gates = new int[gate_cnt + 1];

    for (int i = 0; i <= gate_cnt; ++i) gates[i] = i;

    for (int i = 1; i <= plane_cnt; ++i)
    {
        int x;
        cin >> x;

        int p = find(gates, x);
        if (p == 0)
        {
            cout << i - 1;
            return 0;
        }

        union_(gates, p, p - 1);
    }

    cout << plane_cnt;

    delete[] gates;
}