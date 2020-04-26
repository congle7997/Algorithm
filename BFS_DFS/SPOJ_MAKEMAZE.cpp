#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

struct Point {
	int row;
	int col;
};
int r[4] = { -1, 0, 1, 0 };
int c[4] = { 0, 1, 0, -1 };
char a[21][21];
int n, m;
Point pIn, pOut;

bool check() {
	if (n == 1 && m == 1) {
		return false;
	}
	int count = 0;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '.') {
				count++;
				if (flag) {
					pIn.row = i;
					pIn.col = j;
					flag = false;
				}
				else {
					pOut.row = i;
					pOut.col = j;
				}
			}
		}
		i += n - 2;
		if (i < 0) {
			break;
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 1; i < n - 1; i++) {
			if (a[i][j] == '.') {
				count++;
				if (flag) {
					pIn.row = i;
					pIn.col = j;
					flag = false;
				}
				else {
					pOut.row = i;
					pOut.col = j;
				}
			}
		}
		j += m - 2;
		if (j < 0) {
			break;
		}
	}

	if (count == 2) {
		return true;
	}
	else {
		return false;
	}
}

bool browse() {
	stack<Point> s;
	s.push(pIn);

	while (!s.empty()) {
		Point p = s.top();
		s.pop();

		a[p.row][p.col] = '-';

		for (int i = 0; i < 4; i++) {
			if (a[p.row + r[i]][p.col + c[i]] == '.') {
				s.push({ p.row + r[i] , p.col + c[i] });

				if (p.row + r[i] == pOut.row && p.col + c[i] == pOut.col) {
					return true;
				}
			}
		}
	}

	return false;
}

int main() {
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		memset(a, '\0', sizeof(a));
		n = 0, m = 0;
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}

		if (check()) {
			if (browse()) {
				cout << "valid" << endl;
			}
			else {
				cout << "invalid" << endl;
			}
		}
		else {
			cout << "invalid" << endl;
		}
	}
}