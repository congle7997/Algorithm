#include <iostream>
#include <vector>
using namespace std;

int count = 0;
vector <int> v[100001];
bool visited[100001];

void DFS(int k) {
	visited[k] = true;
	count++;

	for (int i = 0; i < v[k].size(); i++) {
		int value = v[k][i];
		if (!visited[value]) {
			DFS(value);
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			v[i].push_back(x);
		}
	}

	DFS(k);

	cout << count << endl;
	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			cout << i << " ";
		}
	}
}
