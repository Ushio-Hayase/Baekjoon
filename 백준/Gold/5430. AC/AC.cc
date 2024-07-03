#include <stdio.h>
#include <vector>
#include <queue>
#include <deque>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		bool reverse = false;
		string p;
		cin >> p;

		int n;
		scanf("%d", &n);

		string arr;
		cin >> arr;
		arr.erase(arr.end()-1);
		arr.erase(arr.begin());

		deque<int> list;


		istringstream ss(arr);
		string tmp;
		vector<string> str;

		while (getline(ss, tmp, ',')) {
			str.push_back(tmp);
		}

		int k = 0;
		
		for (auto j : str) {
			list.push_back(stoi(j));
			++k;
		}

		bool error = false;

		for (auto j : p) {
			if (j == 'R') {
				reverse = !reverse;
			}
			else if (j=='D') {
				if (list.empty()) {
					error = true;
					break;
				}
				else {
					if (reverse) list.pop_back();
					else list.pop_front();
				}
			}
		}

		if (error) {
			printf("error\n");
			continue;
		}
		else {
			if (!reverse) {
				printf("[");
				if (!list.empty()) {
					printf("%d", list.front());
					list.pop_front();
					for (auto j : list) {
						printf(",");
						printf("%d", j);
					}
				}
				printf("]\n");
			}
			else if (reverse) {
				printf("[");
				if (!list.empty()) {
					printf("%d", list.back());
					list.pop_back();
					for (auto j = list.rbegin(); j != list.rend(); ++j) {
						printf(",%d", *j);
					}
				}
				printf("]\n");
			}
		}
	}
}
