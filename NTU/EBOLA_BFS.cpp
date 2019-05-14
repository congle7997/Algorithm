#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int count = 0;
queue<int> q;
vector<int> v[100001];
bool visited[100001];

void BFS(int k) {
	visited[k] = true;
	q.push(k);
	count++;

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 0; i < v[front].size(); i++) {
			int value = v[front][i];
			if (!visited[value]) {
				visited[value] = true;
				count++;
				q.push(value);
			}
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		for (int j = 1; j <= m; j++) {
			int x;
			cin >> x;
			v[i].push_back(x);
		}
	}

	BFS(k);

	cout << count << endl;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == true) {
			cout << i << " ";
		}
	}
}
