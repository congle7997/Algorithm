#include <iostream>
using namespace std;

string str1, str2;
int table[10001][10001];

void genTable() {
	for (int i = 0; i <= str1.length(); i++) {
		for (int j = 0; j <= str2.length(); j++) {
			if (i == 0 || j == 0) {
				table[i][j] = 0;
				continue;
			}

			if (str1[i - 1] == str2[j - 1]) {
				table[i][j] = table[i - 1][j - 1] + 1;
			} else {
				if (table[i - 1][j] > table[i][j - 1]) {
					table[i][j] = table[i - 1][j];
				} else {
					table[i][j] = table[i][j - 1];
				}
			}
		}
	}
}

void showTable() {
	for (int i = 0; i <= str1.length(); i++) {
		for (int j = 0; j <= str2.length(); j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	cin >> str1 >> str2;

	genTable();
	//showTable();

	cout << table[str1.length()][str2.length()];
}