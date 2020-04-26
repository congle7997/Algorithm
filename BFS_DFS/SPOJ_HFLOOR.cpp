#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <stack>
#include <cmath>
#include <stdio.h>
using namespace std;

struct Point {
	int row;
	int col;
};
int r[4] = { -1, 0, 1, 0 };
int c[4] = { 0, 1, 0, -1};
char a[109][109];
int sum = 0, area = 0;

void browse(Point p) {
	stack<Point> s;
	s.push(p);
	area++;

	while (!s.empty()) {
		Point p = s.top();
		s.pop();

		for (int i = 0; i < 4; i++) {
			if (a[p.row + r[i]][p.col + c[i]] == '*' || a[p.row + r[i]][p.col + c[i]] == '-') {
				if (a[p.row + r[i]][p.col + c[i]] == '*') {
					sum++;
				}

				s.push({p.row + r[i], p.col + c[i]});
				a[p.row + r[i]][p.col + c[i]] = 'x';
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
    int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n, m;
		cin >> n >> m;
		memset(a, '\0', sizeof(a));
		sum = 0, area = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}

		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < 4; k++) {
					if (a[i][j] == '*' || a[i][j] == '-') {
						browse({i + r[k], j + c[k]});
					}
				}
			}
		}

		if (area > 0) {
			printf("%.2f\n", (float) sum / area);
		} else {
			cout << "0.00";
		}
	}
}