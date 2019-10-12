#include <iostream>
using namespace std;

int n;

char check(char a[20][20]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int row[] = { -1, -2, 1, 2 };
			int col[] = { 0, 0, 0, 0 };
			int colDiagonal[] = { 1, 2, -1, -2 };

			if (a[i][j] == 'x' || a[i][j] == 'o') {
				char c = a[i][j];

				int checkVertical = 1;
				int checkHorizontal = 1;
				int checkDiagonal1 = 1;
				int checkDiagonal2 = 1;

				for (int k = 0; k < 4; k++) {
					if (a[i + row[k]][j + col[k]] == c) {
						checkVertical++;
					}
          // đảo ngược row thành col và ngược lại
					if (a[i + col[k]][j + row[k]] == c) {
						checkHorizontal++;
					}
          // chỉ cần tạo thêm mảng chỉ số cột
					if (a[i + row[k]][j + colDiagonal[k]] == c) {
						checkDiagonal1++;
					}
          // chỉ số cột chính là đảo ngược giá trị của thằng bên trên
					if (a[i + row[k]][j + colDiagonal[k] * -1] == c) {
						checkDiagonal2++;
					}

					if (checkVertical == 5 || checkHorizontal == 5
						|| checkDiagonal1 == 5 || checkDiagonal2 == 5) {
						return c;
					}
				}
			}
		}
	}

	return 'e';
}

int main() {
	cin >> n;

	char a[20][20];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	if (check(a) == 'x') {
		cout << "Ti wins";
	} else if (check(a) == 'o') {
		cout << "Teo wins";
	} else {
		cout << "Not yet";
	}
}
