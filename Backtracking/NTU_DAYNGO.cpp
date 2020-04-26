#include <iostream>
using namespace std;

int n;
char a[21];
int balance = 0, sum = 0;

void printResult() {
	for (int i = 1; i <= n; i++) {
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

		if (balance >= 0 && balance <= n / 2) {
			if (k == n) {
				if (balance == 0){
					printResult();
					sum++;
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
	cout << sum;
}
    