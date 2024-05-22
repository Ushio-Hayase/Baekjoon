#include <iostream>
#include <map>

using namespace std;

map<char, bool> breaken;

int main() {
    for(int i = 0; i< 10; i++) breaken.insert(make_pair(i + '0', true));

    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    for(int i = 0; i < M; i++) {
        int tmp;
        scanf("%d", &tmp);
        breaken[tmp + '0'] = false;
    }
}