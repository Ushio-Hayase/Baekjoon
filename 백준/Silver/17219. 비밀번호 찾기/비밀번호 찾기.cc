#include <iostream>
#include <map>
#include <string>

int N, M;

std::map<std::string, std::string> m;

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        std::string id, pw;
        std::cin >> id >> pw;
        m[id] = pw;
    }

    for (int j = 0; j < M; ++j)
    {
        std::string query;
        std::cin >> query;
        std::cout << m.at(query) << "\n";
    }
}
