#include <iostream>

using namespace std;

int arr[11];
int main() {
	int n, k;
	cin >> n >> k;
    
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
    
	int sum = 0;
	for (int i = n - 1; i >= 0; --i) {
		sum += k / arr[i];
		k = k % arr[i];
	}

	cout << sum << "\n";
}