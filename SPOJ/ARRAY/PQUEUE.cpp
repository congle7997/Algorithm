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

struct Num {
	int value;
	bool flag;
};

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n, m;
		cin >> n >> m;
		int a[109];
		queue<Num> q;
		for (int i = 0; i < n; i++) {
			cin >> a[i];

			if (i == m) {
				q.push({ a[i], true });
			}
			else {
				q.push({ a[i], false });
			}
		}
		sort(a + 0, a + n, greater<int>());

		vector<Num> v;
		int i = 0;
		while (true) {
			Num x = q.front();

			if (x.value < a[i]) {
				q.push({ x.value, x.flag });
				q.pop();
			}
			else {
				i++;
				v.push_back({x.value, x.flag});
				q.pop();
			}

			if (i == n) {
				break;
			}
		}

		for (int i = 0; i < v.size(); i++) {
			if (v[i].flag == 1) {
				cout << i + 1 << endl;
			}
		}
	}
}