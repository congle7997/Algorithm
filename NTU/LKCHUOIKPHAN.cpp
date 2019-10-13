#include<iostream>
#include<math.h>
using namespace std;

int x, n;
int a[10];

void printResult() {
	for (int i = 1; i <= n; i++) {
		cout << a[i];
	}
	cout << endl;
}

void createKString(int k) {
	for (int i = 1; i <= x; i++) {
		a[k] = i;
		if (k == n) {
			printResult();
		} else {
			createKString(k + 1);
		}
	}
}

int main() {
	cin >> x >> n;
	cout << pow(x, n) << endl;
	createKString(1);
}
