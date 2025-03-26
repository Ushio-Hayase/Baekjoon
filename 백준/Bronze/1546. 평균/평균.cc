#include <iostream>

using namespace std;


int main() {

	double score[1001];
	int t, max = -1;
	double sum = 0;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> score[i];
		if (max < score[i]) max = score[i];
	}

	for (int i = 0; i < t; i++) {
		score[i] = score[i] / max * 100;
		sum += score[i];
	}

	cout << sum / t;
	
	

	return 0;
}