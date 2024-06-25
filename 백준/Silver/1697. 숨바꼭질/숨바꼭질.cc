#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iostream>

using namespace std;

int N, K;
bool visit[100001] = { false, };
int sec[100001];

int BFS() {
	queue<int> q;
	q.push(N);

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		if (current == K) return sec[current];

		if (current + 1 <= 100000 && !visit[current + 1]) {
			q.push(current + 1);
			visit[current + 1] = true;
			sec[current + 1] = sec[current] + 1 < sec[current + 1] ? sec[current] + 1 : sec[current + 1];
		}
		if (current - 1 >= 0 && !visit[current - 1]) { 
			q.push(current - 1); 
			visit[current - 1] = true;
			sec[current - 1] = sec[current] + 1 < sec[current - 1] ? sec[current] + 1 : sec[current - 1];
		}
		if (current * 2 <= 100000 && !visit[2 * current]) { 
			q.push(current * 2);
			visit[current * 2] = true;
			sec[current * 2] = sec[current] + 1 < sec[current * 2] ? sec[current] + 1 : sec[current * 2];
		}
	}
}

int main()
{
	scanf("%d %d", &N, &K);

	memset(sec, 'z', sizeof(sec));
	sec[N] = 0;

	cout << BFS();
}
