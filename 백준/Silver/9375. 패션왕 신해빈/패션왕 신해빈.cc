#include <memory.h>

#include <iostream>
#include <map>
#include <string>

using namespace std;

int T, N;

int main()
{
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        map<string, int> hash;
        cin >> N;
        for (int j = 0; j < N; ++j)
        {
            string a, b;
            cin >> a >> b;
            if (hash.find(b) == hash.end())
                hash[b] = 1;
            else
                hash[b] += 1;
        }
        int result = 1;
        for (const auto& k : hash) result *= k.second + 1;
        cout << result - 1 << "\n";
    }
}