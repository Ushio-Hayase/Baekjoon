#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
#include <iostream>

using namespace std;

int memo[301]{};
int stair[301]{};

int main()
{
	int N;
	scanf("%d", &N);


	for (int i = 1; i <= N; ++i) {
		int x;
		scanf("%d", &x);
		stair[i] = x;
	}

	memo[1] = stair[1];
	memo[2] = stair[1] + stair[2];
	memo[3] = stair[3] + max(stair[1], stair[2]);

	for (int i = 4; i <= N; ++i) {
		memo[i] = stair[i] + max(stair[i - 1] + memo[i - 3], memo[i - 2]);
	}

	printf("%d", memo[N]);
}
