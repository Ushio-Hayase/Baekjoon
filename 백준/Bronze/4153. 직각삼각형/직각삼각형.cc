#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    while (1) {
        cin >> a >> b >> c;
        if (a == 0 || b == 0 || c == 0) {
            break;
        }
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a * a + b * b == c * c) {
            cout << "right" << endl;
        } else {
            cout << "wrong" << endl;
        }
    }
}