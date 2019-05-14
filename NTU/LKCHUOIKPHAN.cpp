#include<iostream>
#include<math.h>
using namespace std;

int k, n;
int a[10];

void show() {
	for (int i = 1; i <= n; i++) {
		cout << a[i];
	}
	cout << endl;
}

void createKString(int t) {
	for (int i = 1; i <= k; i++) {
		a[t] = i;
		if (t == n) {
			show();
		}
		else {
			createKString(t + 1);
		}
	}
}

int main() {
	string s = "dadas";
	cin >> k >> n;
	cout << pow(k, n) << endl;
	createKString(1);
}
