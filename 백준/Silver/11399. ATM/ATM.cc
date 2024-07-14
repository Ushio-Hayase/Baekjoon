#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>

using namespace std;

int N;
vector<int> arr;


int main() {
	scanf("%d", &N);

	int i = N;
	while (i--) {
		int x;
		scanf("%d", &x);
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());
	int res = 0;
	for (i = 0; i < N; ++i) {
		res += (N - i) * arr[i];
	}
	printf("%d", res);
}