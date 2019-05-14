#include <iostream>
#include "queue"
using namespace std;

bool checkMang1Chieu(int a[], int x) {
	for (int i = 0; i < 9; i++) {
		if (a[i] == x) {
			return 0;
		}
	}
	return 1;
}

bool checkMang(int a[9][9]) {

	// check hang
	int i = 0;
	do {
		int row[9] = {};
		int r = 0;

		for (int j = 0; j < 9; j++) {
			//cout << a[i][j] << " ";
			if (a[i][j] == 0) {
				continue;
			}
			else if (checkMang1Chieu(row, a[i][j])) {
				row[r] = a[i][j];
				r++;
			}
			else {
				return 0;
			}
		}
		//cout << "\n";
		i++;
	} while (i < 9);

	// check cot
	int k = 0;
	do {
		int col[9] = {};
		int c = 0;

		for (int t = 0; t < 9; t++) {

			if (a[t][k] == 0) {
				continue;
			}
			else if (checkMang1Chieu(col, a[t][k])) {
				col[c] = a[t][k];
				c++;
			}
			else {
				return 0;
			}
		}

		k++;
	} while (k < 9);


	// check 9 o vuong 3x3
	int x = 0;
	int y = 3;
	int z = 0;
	int w = 3;
	do {
		do {
			int b[9] = {};
			int k = 0;
			for (int i = z; i < w; i++) {
				for (int j = x; j < y; j++) {
					b[k] = a[i][j];
					k++;
				}
			}

			int tt[9] = {};
			int t = 0;

			for (int j = 0; j < 9; j++) {
				if (b[j] == 0) {
					continue;
				}
				else if (checkMang1Chieu(tt, b[j])) {
					tt[t] = b[j];
					t++;
				}
				else {
					return 0;
				}
			}

			// for (int i = 0; i < 9; i++) {
			// 	cout << b[i] << " ";
			// }
			// cout << "\n";

			x += 3;
			y += 3;
		} while (y <= 9);

		x = 0;
		y = 3;
		z += 3;
		w += 3;
	} while (z <= 6);

	return 1;
}

int main() {
	int n;
	cin >> n;

	queue <string> q;
	for (int i = 0; i < n; i++) {
		int a[9][9];
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				cin >> a[j][k];
			}
		}
		if (checkMang(a)) {
			q.push("true");
		}
		else {
			q.push("false");
		}
	}

	while (!q.empty()) {
      string s = q.front();
      q.pop();
      cout << s << endl;
  }
}
