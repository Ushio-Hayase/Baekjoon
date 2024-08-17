#include <iostream>
#include <vector>
using namespace std;

int* person;
int** party;
int* party_len;

int find(int x) {
    if(x == person[x]) return person[x];
    return person[x] = find(person[x]);
}

void set_union(int a, int b) {
    a = find(a);
    b = find(b);

    if (a!=b) {
        if(a < b) person[b] = person[a];
        else person[a] = person[b];
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, M;

    cin >> N >> M;

    person = new int[N+1];
    party = new int*[M];
    party_len = new int[M];

    int know_truth;
    cin >> know_truth;

    for (int i = 0; i <= N; ++i) {
        person[i] = i;
    }

    
    for(int i = 0; i < know_truth; ++i) {
        int tmp;
        cin >> tmp;
        person[tmp] = 0;
    }

    for(int i =0; i < M; ++i) {
        int x;
        cin >> x;
        party[i] = new int[x];
        party_len[i] = x;

        int tmp;
        cin >> tmp;
        party[i][0] = tmp;

        for(int j = 1; j < x; ++j) {
            int tmp2;
            cin >> tmp2;
            party[i][j] = tmp2;
            set_union(tmp, tmp2);
        }        
    }
    int result = M;

    for(int i=0; i<M; ++i) {
        for(int j=0; j<party_len[i]; ++j) {
            if(find(person[party[i][j]]) == 0) {
                result--;
                break;
            }
        }
    }
    cout << result;
    return 0;
}