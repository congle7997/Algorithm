#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[1009], b[1009];
int table[1009][1009];

void genTable() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                table[i][j] = 0;
            } else if (a[i] == b[j]) {
                table[i][j] = table[i - 1][j - 1] + 1;
            } else {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

int main() {
    //freopen("input.txt", "r", stdin);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    genTable();

    cout << table[n][m];
}