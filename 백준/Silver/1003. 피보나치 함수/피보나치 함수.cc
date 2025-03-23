#include <iostream>
using namespace std;
unsigned long long fiboArr[50] = {0,1,};
unsigned long long fibo(unsigned long long N)
{
    if(N == 0 || N == 1)
        return fiboArr[N];
    else if(fiboArr[N] == 0)
        fiboArr[N] = fibo(N-1) + fibo(N-2);
    return fiboArr[N];
}
int main() {
    int T;
    cin >> T;
    int tmp;
    for(int i = 0; i < T; i++)
    {
        cin >> tmp;
        if(tmp == 0)
            cout << "1 0" << '\n';
        else
            cout << fibo(tmp-1) << ' ' << fibo(tmp) << '\n';
    }
}