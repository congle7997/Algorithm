#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;

	int come[n], eat[n];

	for (int i = 0; i < n; i++) {
		cin >> come[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> eat[i];
	}

	int leave[n];
	for (int i = 0; i < n; i++) {
		leave[i] = come[i] + eat[i];
	}

	sort(come, come + n);
	sort(leave, leave + n);

	int count = 1;
	queue<int> q;
	for (int i = 0; i < n - 1; i++) {
		if (leave[i] > come[i + 1]) {
			q.push(leave[i]);

			int x = q.front();

			if (x > come[i + 1]) {
				count++;
			} else {
				q.pop();
			}
		}
	}

	cout << count;
}
