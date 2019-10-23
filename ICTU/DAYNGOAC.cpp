#include <iostream>
using namespace std;

int n;
char a[21];
int balance = 0;

void showResult() {
	for (int i = 1; i <= n * 2; i++) {
		cout << a[i];
	}
	cout << endl;
}

void Try(int k) {
	for (int i = 0; i < 2; i++) {
		int support = balance;
		
		if (i == 0) {
			a[k] = '(';
			balance++;
		} else {
			a[k] = ')';
			balance--;
		}

		if (balance >= 0 && balance <= n) {
			if (k == n * 2) {
				if (balance == 0){
					showResult();
				}
			} else {
				Try(k + 1);
			}
		}

		balance = support;
	}
}

int main() {
	cin >> n;
	Try(1);
}