#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
#include <iostream>

using namespace std;


int main()
{
	int N;
	scanf("%d", &N);

	priority_queue<int> arr;

	for (int i = 0; i < N; ++i) {
		int x;
		scanf("%d", &x);

		if (x == 0 && arr.empty()) {
			printf("0\n");
		}
		else if (x == 0 && !arr.empty()) {
			printf("%d\n", -arr.top());
			arr.pop();
		}
		else {
			arr.push(-x);	
		}
	}
}
