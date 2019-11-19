#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int count = 0;
stack<int> s;
vector<int> v[100001];
bool visited[100001];

void DFS(int k) {
	visited[k] = true;
	s.push(k);
	count++;

	while (!s.empty()) {
		int top = s.top();
		s.pop();
		for (int i = 0; i < v[top].size(); i++) {
			int value = v[top][i];
			if (!visited[value]) {
				visited[value] = true;
				count++;
				s.push(value);
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
