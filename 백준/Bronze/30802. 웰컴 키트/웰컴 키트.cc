#include <iostream>
#include <cmath>

using namespace std;

int N, T, P;
int tsize[6];

int main()
{
    cin >> N;
    for (int i = 0; i < 6; ++i) cin >> tsize[i];
    cin >> T >> P;
    int maxTShirt = 0;
    int sum = 0;

    for (int i = 0; i < 6; ++i)
    {
        maxTShirt += ceil(tsize[i] / static_cast<double>(T));
        sum += tsize[i];
    }
    cout << maxTShirt << "\n";
    cout << sum / P << " " << sum % P;
}