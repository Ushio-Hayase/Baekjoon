#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
#include <iostream>

using namespace std;

bool visited[101];

int DFS(const vector<int> arr[], int current = 1) {
	visited[current] = true;
	int count = 1;

	for (int next : arr[current]) {
		if (!visited[next]) {
			count += DFS(arr, next);
		}
	}

	return count;
}

int main()
{
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);

	vector<int> arr[101];

	
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	printf("%d", DFS(arr) - 1);
}
