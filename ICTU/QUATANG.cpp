#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int n, sum = 0;
int a[17], s[17];
bool check[17];

bool isPrime(int x) {
	if (x < 2) {
		return false;
	}

	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;
}

void Try(int k) {
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			if (i == 1) {
				a[1] = s[1];
				check[1] = true;
				Try(k + 1);
			} else {
				if (isPrime(a[k - 1] + s[i])) {
					a[k] = s[i];
					check[i] = true;
					if (k == n) {
						if (isPrime(a[1] + a[k])) {
							sum++;
						}
					} else {
						Try(k + 1);
					}
					check[i] = false;
				}
			}

		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> s[i];
		}

		Try(1);

		cout << sum << endl;

		sum = 0;	
		memset(a, 0, sizeof(a));
		memset(check, false, sizeof(check));
	}
}
