#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Point {
	int x;
	int y;
};

int moveRow[4] = { -1, 0, 1, 0 };
int moveCol[4] = { 0, 1, 0, -1 };
int a[1000][1000];

void BFS(int x, int y) {
	queue<Point> q;
	int count = 0;

	if (a[x][y] == 0) {
		Point p;
		p.x = x;
		p.y = y;
		q.push(p);

		a[x][y] = -1;

		count++;
	}

	while (!q.empty()) {
		Point p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = p.x + moveRow[i];
			int y = p.y + moveCol[i];

			// tranh out ma tran
			if (x >= 0 && y >= 0) {
				if (a[x][y] == 0) {
					Point p;
					p.x = x;
					p.y = y;
					q.push(p);

					a[x][y] = -1;

					count++;
				}
			}
		}
	}

	cout << count << endl;
}

int main() {
	int n, k;
	cin >> n >> k;

	// bat buoc phai khoi tao gia tri cho mang neu khong se bi RUN-ERROR
	memset(a, -1, sizeof(a));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int x, y;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		// vi tri click chay tu 1
		BFS(x - 1, y - 1);
	}
}
