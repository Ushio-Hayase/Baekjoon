#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int** color_paper = nullptr;
int blue_cnt = 0;
int white_cnt = 0;
int N;

void split(int x_min,int x_max, int y_min, int y_max) {
	int color = color_paper[y_min][x_min];
	bool all_accord = true;
	size_t size = x_max - x_min + 1;
	for (int i = y_min; i <= y_max; ++i) {
		for (int j = x_min; j <= x_max; ++j) {
			if (color != color_paper[i][j]) {
				all_accord = false;
				break;
			}
		}
	}

	if (all_accord) {
		if (color == 1)
			blue_cnt++;
		else
			white_cnt++;
	}
	else {
		if (size / 2 == 1) {
			for (int i = y_min; i <= y_max; ++i) {
				for (int j = x_min; j <= x_max; ++j) {
					if (color_paper[i][j] == 1)
						blue_cnt++;
					else
						white_cnt++;
				}
			}
		}
		else {
			split(x_min, x_max - size / 2, y_min, y_max - size / 2);
			split(x_min + size / 2, x_max, y_min, y_max - size / 2);
			split(x_min, x_max - size / 2, y_min + size / 2, y_max);
			split(x_min + size / 2, x_max, y_min + size / 2, y_max);
		}
	}
}


int main() {
	scanf("%d", &N);

	color_paper = new int* [N];

	for (int i = 0; i < N; ++i) {
		color_paper[i] = new int[N];
		for (int j = 0; j < N; ++j)
			cin >> color_paper[i][j];
	}

	split(0, N- 1, 0, N- 1);

	printf("%d\n%d\n", white_cnt, blue_cnt);
}