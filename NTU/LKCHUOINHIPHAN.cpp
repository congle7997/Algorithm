#include <iostream>
using namespace std;

int a[20];
int n;

void printResult() {
	for (int i = 1; i <= n; i++) {
		cout << a[i];
	}
	cout << endl;
}

void createBinaryString(int k) {
	for (int i = 0; i <= 1; i++) {
		a[k] = i;
		if (k == n) {
			printResult();
		} else {
			createBinaryString(k + 1);
		}
	}
}

int main() {
	cin >> n;
	createBinaryString(1);
}
