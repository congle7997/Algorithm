#include<iostream>
using namespace std;

int n;
int a[100];
bool check[100];

int calculateFactorial(int n) {
	if (n == 0) {
		return 1;
	}
	return n * calculateFactorial(n - 1);
}

void printResult() {
	for (int i = 1; i <= n; i++) {
		cout << a[i];
	}
	cout << endl;
}

void createPermutationString(int k) {
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			a[k] = i;
			check[i] = true;
			if (k == n) {
				printResult();
			} else {
				createPermutationString(k + 1);
			}
			check[i] = false;
		}
	}
}

int main() {
	cin >> n;
	cout << calculateFactorial(n) << endl;
	createPermutationString(1);
}
