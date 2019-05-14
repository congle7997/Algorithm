#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

struct Point {
	int row;
	int col;
};
queue<Point> q;
bool visited[1000][1000];
int r[4] = { -1, 0, 1, 0 };
int c[4] = { 0, 1, 0, -1};
float count1 = 0;
float count2 = 0;

void resetCheckAndCount(int m, int n) {
	count1 = 0;
	count2 = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
}

void BFS(char a[1000][1000], int i, int j) {
	if (a[i][j] == '*') {
		count1++;
	}
	visited[i][j] = true;
	Point p;
	p.row = i;
	p.col = j;
	q.push(p);
	count2++;

	while (!q.empty()) {
		Point p = q.front();
		a[p.row][p.col] = 'x';
		q.pop();
		for (int k = 0; k < 4; k++) {
			int x = p.row + r[k];
			int y = p.col + c[k];
			if ((a[x][y] == '*' || a[x][y] == '-') && visited[x][y] == false) { // x >= 0 && x < m && y >= 0 && y < n &&
				visited[x][y] = true;
				Point p;
				p.row = x;
				p.col = y;
				q.push(p);
				if (a[x][y] == '*') {
					count1++;
				}
			}
		}
	}
}

void getAverage(char a[1000][1000], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == '*' || a[i][j] == '-') {
				BFS(a, i, j);
			}
		}
	}
	// co the in truc tiep ket qua luon nhung phai co dau cach vi no chi lay ket qua tu lenh in ra
	printf("%.2f ", count1 / count2);
	resetCheckAndCount(m, n);
}

int main() {
	int u;
	cin >> u;
	for (int k = 0; k < u; k++) {
		char a[1000][1000];
		int m;
		int n;
		cin >> m;
		cin >> n;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		getAverage(a, m, n);
	}
}
