#include <iostream>
using namespace std;

int n, m, row, col;
int a[101][101];
int counter = 0;

int backtracking(int row, int col) {
	if (a[row][col] == 0) {
		counter++;
		a[row][col] = 1;
	}

	if (a[row - 1][col] == 0 && row -1  >= 0) {
		backtracking(row - 1, col);
	}
	if (a[row][col + 1] == 0 && col + 1 < m) {
		backtracking(row, col + 1);
	}
	if (a[row + 1][col] == 0 && row + 1 < n) {
		backtracking(row + 1, col);
	}
	if (a[row][col - 1] == 0 && col - 1 >= 0) {
		backtracking(row, col - 1);
	}

	return counter;
}

int main() {
	//freopen("input.txt", "r", stdin);

	cin >> n >> m >> row >> col;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	cout << backtracking(row - 1, col - 1);
}
