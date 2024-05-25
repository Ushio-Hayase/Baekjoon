#include <iostream>
#include <math.h>

using namespace std;


int set(int floor, int row, int column, double stand_row, double stand_col, int sum, int end) {
    if (floor == end) {
        return sum;
    }

    int aver;

    if (row <= stand_row && column <= stand_col) {
        aver = 0;
        stand_row -= pow(2, (end-floor-2));
        stand_col -= pow(2, (end-floor-2));
    }
    else if (row <= stand_row && column > stand_col) {
        aver = 1;
        stand_row -= pow(2, (end-floor-2));
        stand_col += pow(2, (end-floor-2));
    }
    else if (row > stand_row && column <= stand_col) {
        aver = 2;
        stand_row += pow(2, (end-floor-2));
        stand_col -= pow(2, (end-floor-2));
    }
    else if (row > stand_row && column > stand_col) {
        aver = 3;
        stand_row += pow(2, (end-floor-2));
        stand_col += pow(2, (end-floor-2));
    }

    sum += pow(2, 2*(end-floor-1 < 0 ? 0 : end-floor-1))*aver;

    int res = set(floor+1, row, column, stand_row, stand_col, sum,end);

    return res;
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;

    double row = pow(2, N);

    cout << set(0, r, c, row/2 - 0.5, row/2 - 0.5, 0, N);

    return 0;
}

