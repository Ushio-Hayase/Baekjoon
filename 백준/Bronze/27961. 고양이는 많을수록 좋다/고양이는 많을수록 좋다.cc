#include <cmath>
#include <iostream>

using namespace std;

unsigned long long N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    if (N == 1 || N == 0)
    {
        cout << N;
        return 0;
    }

    int i = 64;

    N--;

    while (
        (N &
         0b10000000'00000000'00000000'00000000'00000000'00000000'00000000'00000000) !=
        0x80'00'00'00'00'00'00'00)
    {
        N <<= 1;
        i--;
    }

    cout << i + 1;
}