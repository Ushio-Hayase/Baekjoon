#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>

using namespace std;

int N, M;

 

int main() {
	scanf("%d %d", &N, &M);
	int* arr = new int[N];
	for (int i =0; i < N; ++i){
		int x;
		scanf("%d", &x);
		if (i == 0)
			arr[i] = x;
		else
			arr[i] = arr[i - 1] + x;
	}


	while (M--) {
		int left, right;
		scanf("%d %d", &left, &right);
		if (left - 2 < 0)
			printf("%d\n", arr[right-1]);
		else
			printf("%d\n", arr[right-1]-arr[left-2]);
	}
}