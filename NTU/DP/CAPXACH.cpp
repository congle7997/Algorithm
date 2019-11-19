#include <iostream>
using namespace std;

int n, m;
int a[1009];
long long table[1009][1009];

void genTable() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) {
                table[i][j] = 0;
            } else if (j == 0) {
                table[i][j] = 1;
            } else if (a[i] > j) {
                table[i][j] = table[i - 1][j];
            } else {
                table[i][j] = table[i - 1][j] + table[i][j - a[i]];
            }
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << table[i][j] << "\t\t \t";
    //     }
    //     cout << endl;
    // }
}

int main() {
    //freopen("input.txt", "r", stdin);

    cin >> m >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    genTable();

    cout << table[n][m];
}