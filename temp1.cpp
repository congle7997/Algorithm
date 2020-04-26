#include <bits/stdc++.h>
#include <vector>
using namespace std;

int n,a[100005];


int main()
{ ios::sync_with_stdio(false); cin.tie(0);
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	v.insert(v.begin(), 3);
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
}
    