#include <cmath>
#include <iostream>
#include <numeric>

int N;



int func(int now, int target, int repeatCnt, int currentValue)
{
    if (now == target)
        return repeatCnt;
    else if (repeatCnt >= 4)
        return std::numeric_limits<int>::max();
    int result = std::numeric_limits<int>::max();
    int leftValue = sqrt(target - now);

    for (int i = currentValue; i <= leftValue; ++i)
    {
        int tmp = func(now + i * i, target, repeatCnt + 1, i);
        result = tmp < result ? tmp : result;
    }

    return result;
}

int main()
{
    std::cin >> N;
    std::cout << func(0, N, 0, 1);
}
