#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[1001], l[1001];
vector<int> v;

void genTable() {
	l[0] = 1;

	for (int i = 1; i < n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && l[j] > max) {
				max = l[j];
			}
		}
		l[i] = max + 1;
	}
}

void showTable() {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << l[i] << " ";
	}
	cout << endl;
}

void Trace() {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (l[i] > max) {
			max = l[i];
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (l[i] == max) {
			v.push_back(a[i]);
			max--;
		}
	}
	reverse(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}


int main() {
	//freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	genTable();
	//showTable();
	Trace();
}