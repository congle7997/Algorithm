#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <stdio.h>
using namespace std;

int n;
int a[10009];

int findMax(int pos, bool isRight) {
	int max = 0;
	if (isRight) {
		for (int i = pos + 1; i < n; i++) {
			if (a[i] > max) {
				max = a[i];
			}
		}
	}
	else {
		for (int i = 0; i < pos; i++) {
			if (a[i] > max) {
				max = a[i];
			}
		}
	}

	return max;
}

int main() {
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++) {
			cin >> a[i];  
		}

		int res = 0;
		int maxLeft = findMax(1, false);
		int maxRight = findMax(1, true);
		for (int i = 1; i < n - 1; i++) {
			if (maxLeft > a[i] && maxRight > a[i]) {
				res += min(maxLeft, maxRight) - a[i];
			}
			else {
				maxLeft = a[i];
				maxRight = findMax(i + 1, true);
			}
		}

		cout << res << endl;
	}
}