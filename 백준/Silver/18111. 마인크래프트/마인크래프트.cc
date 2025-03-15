#include <iostream>
#include <numeric>

int N, B, M;
int* data;
int** arr;

int main()
{
    std::cin >> N >> M >> B;

    data = new int[N * M];
    arr = new int*[N];

    for (int i = 0; i < N; ++i)
    {
        arr[i] = data + (i * M);
        for (int j = 0; j < M; ++j)
        {
            std::cin >> data[i * M + j];
            arr[i][j] = data[i * M + j];
        }
    }

    int finalTime = std::numeric_limits<int>::max();
    int finalHeight = 0;

    for (int height = 0; height <= 256; ++height)
    {
        int time = 0;
        int needBlocks = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
                const int deltaBlock = arr[i][j] - height;
                if (deltaBlock > 0)
                    time += 2 * deltaBlock;
                else if (deltaBlock < 0)
                    time -= deltaBlock;
                needBlocks -= deltaBlock;
            }
        if (time <= finalTime && needBlocks <= B)
        {
            finalTime = time;
            finalHeight = height;
        }
    }

    std::cout << finalTime << " " << finalHeight;

    delete[] arr;
    delete[] data;
}
