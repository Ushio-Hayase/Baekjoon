#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first <= b.first;
	else return a.second < b.second;
}

int main()
{
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> arr;

	for (int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);

		arr.push_back(make_pair(a, b));
	}

	sort(arr.begin(), arr.end(), cmp);

	vector<pair<int, int>> res;

	int end_time = 0;

	for (auto i : arr) {
		if (i.first >= end_time) {
			res.push_back(i);
			end_time = i.second;
		}
	}

	printf("%d", res.size());
}
