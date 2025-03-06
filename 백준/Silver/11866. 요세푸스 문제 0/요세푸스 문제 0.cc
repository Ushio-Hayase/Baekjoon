#include <cmath>
#include <iostream>
#include <list>

using namespace std;

int N, K;
std::list<int> arr;

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        arr.emplace_back(i + 1);
    }

    cout << "<";

    int i = 1;
    auto pr = arr.begin();

    while (!arr.empty())
    {
        if (i % K == 0)
        {
            cout << (arr.size() == N ? "" : ", ") << *pr;
            pr = arr.erase(pr);
        }
        else
            pr++;
        i++;

        if (pr == arr.end())
        {
            pr = arr.begin();
        }
    }
    cout << ">";
}