#include <iostream>
using namespace std;

int a[20];
int n;

void showResult() {
	for (int i = 1; i <= n; i++) {
		cout << a[i];
	}
	cout << endl;
}

void genBinaryString(int k) {
	for (int i = 0; i <= 1; i++) {
		a[k] = i;
		if (k == n) {
			showResult();
		} else {
			genBinaryString(k + 1);
		}
	}
}

int main() {
	cin >> n;
	genBinaryString(1);
}
