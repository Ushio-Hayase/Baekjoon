#include <bits/stdc++.h>

#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

long long s(long long n) {
    long long c = 0;
    for (int i = 0; i < 55; i++) {
        long long p = 1LL << i;
        long long cyc = p << 1;
        long long n_c = (n + 1) / cyc;
        c += n_c * p;
        long long r = (n + 1) % cyc;
        if (r > p) {
            c += r - p;
        }
    }
    return c;
}

int main() {
    FAST_IO;
    long long a, b;
    std::cin >> a >> b;
    std::cout << s(b) - s(a - 1);
    return 0;
}