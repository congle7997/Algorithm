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

struct Pair{
	int v1;
	int v2;
};

bool order(Pair p1, Pair p2) {
	if (p1.v1 != p2.v1) {
		return p1.v1 > p2.v1;
	}
	else {
		return p1.v2 > p2.v2;
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
        // accept QUE2;
		int a[10009], b[10009];
		vector<int> v;
		vector<Pair> p;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			p.push_back({ a[i], b[i] });
		}

		sort(p.begin(), p.end(), order);

		for (int i = 0; i < p.size(); i++) {
			v.insert(v.begin() + p[i].v2, p[i].v1);
		}

		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
}