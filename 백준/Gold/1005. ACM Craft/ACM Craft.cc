#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		int N, K, W, top, next;
		vector<int> D(1001, 0);
		vector<int> node[1001];
		vector<int> degree(1001, 0);
		vector<int> sum(1001, 0);
		queue<int> q;

		cin >> N >> K;
		for (int j = 1; j <= N; ++j) {
			cin >> D[j];
			sum[j] = D[j];
		}
		for (int j = 0; j < K; ++j) {
			int x, y;
			cin >> x >> y;
			node[x].push_back(y);
			degree[y]++;
		}

		cin >> W;
		for (int j = 1; j <= N; ++j) {
			if (degree[j]==0) 
				q.push(j);
			
		}
		while (!q.empty()) {
			top = q.front();
			q.pop();
			for (int j = 0; j < node[top].size(); j++) {
				next = node[top][j];
				if (sum[top] + D[next] > sum[next]) sum[next] = sum[top] + D[next];
				degree[next]--;
				if (!degree[next]) q.push(next);
			}
		}

		cout << sum[W]<<"\n";

	}
	return 0;
}