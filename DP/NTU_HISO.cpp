#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	int a[100009];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int minValue = a[0];
	int maxResult = a[1] - a[0];

	for (int i = 1; i < n; i++) {
		if (a[i] - minValue > maxResult) {
			maxResult = a[i] - minValue;
		}
		if (a[i] < minValue) {
			minValue = a[i];
		}
	}

	cout << maxResult;
}