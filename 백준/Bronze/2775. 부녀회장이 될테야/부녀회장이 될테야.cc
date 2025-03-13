#include <array>
#include <iostream>

int K, N, T;

template <int N, int F>
constexpr int FiboFunc();

constexpr int returnNumber(int i) { return i; }

template <int T, int F>
class Fibo
{
   public:
    static constexpr int value = Fibo<T - 1, F>::value + Fibo<T, F - 1>::value;
};

template <>
class Fibo<1, 0>
{
   public:
    static constexpr int value = 1;
};

template <int N>
class Fibo<N, 0>
{
   public:
    static constexpr int value = N;
};

template <int F>
class Fibo<1, F>
{
   public:
    static constexpr int value = 1;
};

template <int n, int f>
inline constexpr int FiboFunc()
{
    int result = 0;

    if (f == 0 && n == 1)
    {
        return Fibo<1, 0>::value;
    }
    else if (f == 0 && n == 2)
    {
        return Fibo<2, 0>::value;
    }
    else if (f == 0)
        result = n;
    else

        for (int i = n; i <= 1; --i)
        {
            result += Fibo<n - i, f - 1>::value;
        }

    Fibo<f, n>::value = result;

    return result;
}

int main()
{
    std::cin >> T;

    for (int i = 0; i < T; ++i)
    {
        std::cin >> K >> N;
        switch (N)
        {
            case 1:
                switch (K)
                {
                    case 1:
                        std::cout << Fibo<1, 1>::value << "\n";
                        break;
                    case 2:
                        std::cout << Fibo<1, 2>::value << "\n";
                        break;
                    case 3:
                        std::cout << Fibo<1, 3>::value << "\n";
                        break;
                    case 4:
                        std::cout << Fibo<1, 4>::value << "\n";
                        break;
                    case 5:
                        std::cout << Fibo<1, 5>::value << "\n";
                        break;
                    case 6:
                        std::cout << Fibo<1, 6>::value << "\n";
                        break;
                    case 7:
                        std::cout << Fibo<1, 7>::value << "\n";
                        break;
                    case 8:
                        std::cout << Fibo<1, 8>::value << "\n";
                        break;
                    case 9:
                        std::cout << Fibo<1, 9>::value << "\n";
                        break;
                    case 10:
                        std::cout << Fibo<1, 10>::value << "\n";
                        break;
                    case 11:
                        std::cout << Fibo<1, 11>::value << "\n";
                        break;
                    case 12:
                        std::cout << Fibo<1, 12>::value << "\n";
                        break;
                    case 13:
                        std::cout << Fibo<1, 13>::value << "\n";
                        break;
                    case 14:
                        std::cout << Fibo<1, 14>::value << "\n";
                        break;
                }
                break;
            case 2:
                switch (K)
                {
                    case 1:
                        std::cout << Fibo<2, 1>::value << "\n";
                        break;
                    case 2:
                        std::cout << Fibo<2, 2>::value << "\n";
                        break;
                    case 3:
                        std::cout << Fibo<2, 3>::value << "\n";
                        break;
                    case 4:
                        std::cout << Fibo<2, 4>::value << "\n";
                        break;
                    case 5:
                        std::cout << Fibo<2, 5>::value << "\n";
                        break;
                    case 6:
                        std::cout << Fibo<2, 6>::value << "\n";
                        break;
                    case 7:
                        std::cout << Fibo<2, 7>::value << "\n";
                        break;
                    case 8:
                        std::cout << Fibo<2, 8>::value << "\n";
                        break;
                    case 9:
                        std::cout << Fibo<2, 9>::value << "\n";
                        break;
                    case 10:
                        std::cout << Fibo<2, 10>::value << "\n";
                        break;
                    case 11:
                        std::cout << Fibo<2, 11>::value << "\n";
                        break;
                    case 12:
                        std::cout << Fibo<2, 12>::value << "\n";
                        break;
                    case 13:
                        std::cout << Fibo<2, 13>::value << "\n";
                        break;
                    case 14:
                        std::cout << Fibo<2, 14>::value << "\n";
                        break;
                }
                break;
            case 3:
                switch (K)
                {
                    case 1:
                        std::cout << Fibo<3, 1>::value << "\n";
                        break;
                    case 2:
                        std::cout << Fibo<3, 2>::value << "\n";
                        break;
                    case 3:
                        std::cout << Fibo<3, 3>::value << "\n";
                        break;
                    case 4:
                        std::cout << Fibo<3, 4>::value << "\n";
                        break;
                    case 5:
                        std::cout << Fibo<3, 5>::value << "\n";
                        break;
                    case 6:
                        std::cout << Fibo<3, 6>::value << "\n";
                        break;
                    case 7:
                        std::cout << Fibo<3, 7>::value << "\n";
                        break;
                    case 8:
                        std::cout << Fibo<3, 8>::value << "\n";
                        break;
                    case 9:
                        std::cout << Fibo<3, 9>::value << "\n";
                        break;
                    case 10:
                        std::cout << Fibo<3, 10>::value << "\n";
                        break;
                    case 11:
                        std::cout << Fibo<3, 11>::value << "\n";
                        break;
                    case 12:
                        std::cout << Fibo<3, 12>::value << "\n";
                        break;
                    case 13:
                        std::cout << Fibo<3, 13>::value << "\n";
                        break;
                    case 14:
                        std::cout << Fibo<3, 14>::value << "\n";
                        break;
                }
                break;
            case 4:
                switch (K)
                {
                    case 1:
                        std::cout << Fibo<4, 1>::value << "\n";
                        break;
                    case 2:
                        std::cout << Fibo<4, 2>::value << "\n";
                        break;
                    case 3:
                        std::cout << Fibo<4, 3>::value << "\n";
                        break;
                    case 4:
                        std::cout << Fibo<4, 4>::value << "\n";
                        break;
                    case 5:
                        std::cout << Fibo<4, 5>::value << "\n";
                        break;
                    case 6:
                        std::cout << Fibo<4, 6>::value << "\n";
                        break;
                    case 7:
                        std::cout << Fibo<4, 7>::value << "\n";
                        break;
                    case 8:
                        std::cout << Fibo<4, 8>::value << "\n";
                        break;
                    case 9:
                        std::cout << Fibo<4, 9>::value << "\n";
                        break;
                    case 10:
                        std::cout << Fibo<4, 10>::value << "\n";
                        break;
                    case 11:
                        std::cout << Fibo<4, 11>::value << "\n";
                        break;
                    case 12:
                        std::cout << Fibo<4, 12>::value << "\n";
                        break;
                    case 13:
                        std::cout << Fibo<4, 13>::value << "\n";
                        break;
                    case 14:
                        std::cout << Fibo<4, 14>::value << "\n";
                        break;
                }
                break;
            case 5:
                switch (K)
                {
                    case 1:
                        std::cout << Fibo<5, 1>::value << "\n";
                        break;
                    case 2:
                        std::cout << Fibo<5, 2>::value << "\n";
                        break;
                    case 3:
                        std::cout << Fibo<5, 3>::value << "\n";
                        break;
                    case 4:
                        std::cout << Fibo<5, 4>::value << "\n";
                        break;
                    case 5:
                        std::cout << Fibo<5, 5>::value << "\n";
                        break;
                    case 6:
                        std::cout << Fibo<5, 6>::value << "\n";
                        break;
                    case 7:
                        std::cout << Fibo<5, 7>::value << "\n";
                        break;
                    case 8:
                        std::cout << Fibo<5, 8>::value << "\n";
                        break;
                    case 9:
                        std::cout << Fibo<5, 9>::value << "\n";
                        break;
                    case 10:
                        std::cout << Fibo<5, 10>::value << "\n";
                        break;
                    case 11:
                        std::cout << Fibo<5, 11>::value << "\n";
                        break;
                    case 12:
                        std::cout << Fibo<5, 12>::value << "\n";
                        break;
                    case 13:
                        std::cout << Fibo<5, 13>::value << "\n";
                        break;
                    case 14:
                        std::cout << Fibo<5, 14>::value << "\n";
                        break;
                }
                break;
            case 6:
                switch (K)
                {
                    case 1:
                        std::cout << Fibo<6, 1>::value << "\n";
                        break;
                    case 2:
                        std::cout << Fibo<6, 2>::value << "\n";
                        break;
                    case 3:
                        std::cout << Fibo<6, 3>::value << "\n";
                        break;
                    case 4:
                        std::cout << Fibo<6, 4>::value << "\n";
                        break;
                    case 5:
                        std::cout << Fibo<6, 5>::value << "\n";
                        break;
                    case 6:
                        std::cout << Fibo<6, 6>::value << "\n";
                        break;
                    case 7:
                        std::cout << Fibo<6, 7>::value << "\n";
                        break;
                    case 8:
                        std::cout << Fibo<6, 8>::value << "\n";
                        break;
                    case 9:
                        std::cout << Fibo<6, 9>::value << "\n";
                        break;
                    case 10:
                        std::cout << Fibo<6, 10>::value << "\n";
                        break;
                    case 11:
                        std::cout << Fibo<6, 11>::value << "\n";
                        break;
                    case 12:
                        std::cout << Fibo<6, 12>::value << "\n";
                        break;
                    case 13:
                        std::cout << Fibo<6, 13>::value << "\n";
                        break;
                    case 14:
                        std::cout << Fibo<6, 14>::value << "\n";
                        break;
                }
                break;
            case 7:
                switch (K)
                {
                    case 1:
                        std::cout << Fibo<7, 1>::value << "\n";
                        break;
                    case 2:
                        std::cout << Fibo<7, 2>::value << "\n";
                        break;
                    case 3:
                        std::cout << Fibo<7, 3>::value << "\n";
                        break;
                    case 4:
                        std::cout << Fibo<7, 4>::value << "\n";
                        break;
                    case 5:
                        std::cout << Fibo<7, 5>::value << "\n";
                        break;
                    case 6:
                        std::cout << Fibo<7, 6>::value << "\n";
                        break;
                    case 7:
                        std::cout << Fibo<7, 7>::value << "\n";
                        break;
                    case 8:
                        std::cout << Fibo<7, 8>::value << "\n";
                        break;
                    case 9:
                        std::cout << Fibo<7, 9>::value << "\n";
                        break;
                    case 10:
                        std::cout << Fibo<7, 10>::value << "\n";
                        break;
                    case 11:
                        std::cout << Fibo<7, 11>::value << "\n";
                        break;
                    case 12:
                        std::cout << Fibo<7, 12>::value << "\n";
                        break;
                    case 13:
                        std::cout << Fibo<7, 13>::value << "\n";
                        break;
                    case 14:
                        std::cout << Fibo<7, 14>::value << "\n";
                        break;
                }
                break;
            case 8:
                switch (K)
                {
                    case 1:
                        std::cout << Fibo<8, 1>::value << "\n";
                        break;
                    case 2:
                        std::cout << Fibo<8, 2>::value << "\n";
                        break;
                    case 3:
                        std::cout << Fibo<8, 3>::value << "\n";
                        break;
                    case 4:
                        std::cout << Fibo<8, 4>::value << "\n";
                        break;
                    case 5:
                        std::cout << Fibo<8, 5>::value << "\n";
                        break;
                    case 6:
                        std::cout << Fibo<8, 6>::value << "\n";
                        break;
                    case 7:
                        std::cout << Fibo<8, 7>::value << "\n";
                        break;
                    case 8:
                        std::cout << Fibo<8, 8>::value << "\n";
                        break;
                    case 9:
                        std::cout << Fibo<8, 9>::value << "\n";
                        break;
                    case 10:
                        std::cout << Fibo<8, 10>::value << "\n";
                        break;
                    case 11:
                        std::cout << Fibo<8, 11>::value << "\n";
                        break;
                    case 12:
                        std::cout << Fibo<8, 12>::value << "\n";
                        break;
                    case 13:
                        std::cout << Fibo<8, 13>::value << "\n";
                        break;
                    case 14:
                        std::cout << Fibo<8, 14>::value << "\n";
                        break;
                }
                break;
            case 9:
                switch (K)
                {
                    case 1:
                        std::cout << Fibo<9, 1>::value << "\n";
                        break;
                    case 2:
                        std::cout << Fibo<9, 2>::value << "\n";
                        break;
                    case 3:
                        std::cout << Fibo<9, 3>::value << "\n";
                        break;
                    case 4:
                        std::cout << Fibo<9, 4>::value << "\n";
                        break;
                    case 5:
                        std::cout << Fibo<9, 5>::value << "\n";
                        break;
                    case 6:
                        std::cout << Fibo<9, 6>::value << "\n";
                        break;
                    case 7:
                        std::cout << Fibo<9, 7>::value << "\n";
                        break;
                    case 8:
                        std::cout << Fibo<9, 8>::value << "\n";
                        break;
                    case 9:
                        std::cout << Fibo<9, 9>::value << "\n";
                        break;
                    case 10:
                        std::cout << Fibo<9, 10>::value << "\n";
                        break;
                    case 11:
                        std::cout << Fibo<9, 11>::value << "\n";
                        break;
                    case 12:
                        std::cout << Fibo<9, 12>::value << "\n";
                        break;
                    case 13:
                        std::cout << Fibo<9, 13>::value << "\n";
                        break;
                    case 14:
                        std::cout << Fibo<9, 14>::value << "\n";
                        break;
                }
                break;
            case 10:
                switch (K)
                {
                    case 1:
                        std::cout << Fibo<10, 1>::value << "\n";
                        break;
                    case 2:
                        std::cout << Fibo<10, 2>::value << "\n";
                        break;
                    case 3:
                        std::cout << Fibo<10, 3>::value << "\n";
                        break;
                    case 4:
                        std::cout << Fibo<10, 4>::value << "\n";
                        break;
                    case 5:
                        std::cout << Fibo<10, 5>::value << "\n";
                        break;
                    case 6:
                        std::cout << Fibo<10, 6>::value << "\n";
                        break;
                    case 7:
                        std::cout << Fibo<10, 7>::value << "\n";
                        break;
                    case 8:
                        std::cout << Fibo<10, 8>::value << "\n";
                        break;
                    case 9:
                        std::cout << Fibo<10, 9>::value << "\n";
                        break;
                    case 10:
                        std::cout << Fibo<10, 10>::value << "\n";
                        break;
                    case 11:
                        std::cout << Fibo<10, 11>::value << "\n";
                        break;
                    case 12:
                        std::cout << Fibo<10, 12>::value << "\n";
                        break;
                    case 13:
                        std::cout << Fibo<10, 13>::value << "\n";
                        break;
                    case 14:
                        std::cout << Fibo<10, 14>::value << "\n";
                        break;
                }
                break;
            case 11:
                switch (K)
                {
                    case 1:
                        std::cout << Fibo<11, 1>::value << "\n";
                        break;
                    case 2:
                        std::cout << Fibo<11, 2>::value << "\n";
                        break;
                    case 3:
                        std::cout << Fibo<11, 3>::value << "\n";
                        break;
                    case 4:
                        std::cout << Fibo<11, 4>::value << "\n";
                        break;
                    case 5:
                        std::cout << Fibo<11, 5>::value << "\n";
                        break;
                    case 6:
                        std::cout << Fibo<11, 6>::value << "\n";
                        break;
                    case 7:
                        std::cout << Fibo<11, 7>::value << "\n";
                        break;
                    case 8:
                        std::cout << Fibo<11, 8>::value << "\n";
                        break;
                    case 9:
                        std::cout << Fibo<11, 9>::value << "\n";
                        break;
                    case 10:
                        std::cout << Fibo<11, 10>::value << "\n";
                        break;
                    case 11:
                        std::cout << Fibo<11, 11>::value << "\n";
                        break;
                    case 12:
                        std::cout << Fibo<11, 12>::value << "\n";
                        break;
                    case 13:
                        std::cout << Fibo<11, 13>::value << "\n";
                        break;
                    case 14:
                        std::cout << Fibo<11, 14>::value << "\n";
                        break;
                }
                break;
            case 12:
                switch (K)
                {
                    case 1:
                        std::cout << Fibo<12, 1>::value << "\n";
                        break;
                    case 2:
                        std::cout << Fibo<12, 2>::value << "\n";
                        break;
                    case 3:
                        std::cout << Fibo<12, 3>::value << "\n";
                        break;
                    case 4:
                        std::cout << Fibo<12, 4>::value << "\n";
                        break;
                    case 5:
                        std::cout << Fibo<12, 5>::value << "\n";
                        break;
                    case 6:
                        std::cout << Fibo<12, 6>::value << "\n";
                        break;
                    case 7:
                        std::cout << Fibo<12, 7>::value << "\n";
                        break;
                    case 8:
                        std::cout << Fibo<12, 8>::value << "\n";
                        break;
                    case 9:
                        std::cout << Fibo<12, 9>::value << "\n";
                        break;
                    case 10:
                        std::cout << Fibo<12, 10>::value << "\n";
                        break;
                    case 11:
                        std::cout << Fibo<12, 11>::value << "\n";
                        break;
                    case 12:
                        std::cout << Fibo<12, 12>::value << "\n";
                        break;
                    case 13:
                        std::cout << Fibo<12, 13>::value << "\n";
                        break;
                    case 14:
                        std::cout << Fibo<12, 14>::value << "\n";
                        break;
                }
                break;
            case 13:
                switch (K)
                {
                    case 1:
                        std::cout << Fibo<13, 1>::value << "\n";
                        break;
                    case 2:
                        std::cout << Fibo<13, 2>::value << "\n";
                        break;
                    case 3:
                        std::cout << Fibo<13, 3>::value << "\n";
                        break;
                    case 4:
                        std::cout << Fibo<13, 4>::value << "\n";
                        break;
                    case 5:
                        std::cout << Fibo<13, 5>::value << "\n";
                        break;
                    case 6:
                        std::cout << Fibo<13, 6>::value << "\n";
                        break;
                    case 7:
                        std::cout << Fibo<13, 7>::value << "\n";
                        break;
                    case 8:
                        std::cout << Fibo<13, 8>::value << "\n";
                        break;
                    case 9:
                        std::cout << Fibo<13, 9>::value << "\n";
                        break;
                    case 10:
                        std::cout << Fibo<13, 10>::value << "\n";
                        break;
                    case 11:
                        std::cout << Fibo<13, 11>::value << "\n";
                        break;
                    case 12:
                        std::cout << Fibo<13, 12>::value << "\n";
                        break;
                    case 13:
                        std::cout << Fibo<13, 13>::value << "\n";
                        break;
                    case 14:
                        std::cout << Fibo<13, 14>::value << "\n";
                        break;
                }
                break;
            case 14:
                switch (K)
                {
                    case 1:
                        std::cout << Fibo<14, 1>::value << "\n";
                        break;
                    case 2:
                        std::cout << Fibo<14, 2>::value << "\n";
                        break;
                    case 3:
                        std::cout << Fibo<14, 3>::value << "\n";
                        break;
                    case 4:
                        std::cout << Fibo<14, 4>::value << "\n";
                        break;
                    case 5:
                        std::cout << Fibo<14, 5>::value << "\n";
                        break;
                    case 6:
                        std::cout << Fibo<14, 6>::value << "\n";
                        break;
                    case 7:
                        std::cout << Fibo<14, 7>::value << "\n";
                        break;
                    case 8:
                        std::cout << Fibo<14, 8>::value << "\n";
                        break;
                    case 9:
                        std::cout << Fibo<14, 9>::value << "\n";
                        break;
                    case 10:
                        std::cout << Fibo<14, 10>::value << "\n";
                        break;
                    case 11:
                        std::cout << Fibo<14, 11>::value << "\n";
                        break;
                    case 12:
                        std::cout << Fibo<14, 12>::value << "\n";
                        break;
                    case 13:
                        std::cout << Fibo<14, 13>::value << "\n";
                        break;
                    case 14:
                        std::cout << Fibo<14, 14>::value << "\n";
                        break;
                }
        }
    }
}
