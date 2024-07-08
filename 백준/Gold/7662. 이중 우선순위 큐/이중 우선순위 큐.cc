#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int main() {
	int T, K, N;
	char operation;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		priority_queue<int> lower;
		priority_queue<int, vector<int>, greater<int>> upper;
		map<int, int> cnt;

		scanf("%d", &K);
		for (int j = 0; j < K; ++j) {
			cin >> operation >> N;

			if (operation == 'I') {
				lower.push(N);
				upper.push(N);
				cnt[N]++;
			}
			else {
				if (N == 1) {
					if (!lower.empty()) {
						cnt[lower.top()]--;
						lower.pop();
					}
				}
				else {
					if (!upper.empty()) {
						cnt[upper.top()]--;
						upper.pop();
					}
				}

				while (!upper.empty() && cnt[upper.top()] == 0) upper.pop();
				while (!lower.empty() && cnt[lower.top()] == 0) lower.pop();
			}
		}

		while (!upper.empty() && cnt[upper.top()] == 0) upper.pop();
		while (!lower.empty() && cnt[lower.top()] == 0) lower.pop();

		if (upper.empty() || lower.empty()) printf("EMPTY\n");
		else printf("%d %d\n",lower.top(), upper.top());
	}
}