#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int v[109], w[109];
int table[109][109];

void genTable() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                table[i][j] = 0;
            } else if (w[i] > j) {
                table[i][j] = table[i - 1][j];
            } else {
                table[i][j] = max(table[i - 1][j], v[i] + table[i - 1][j - w[i]]);
            }
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << table[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
}

void Trace() {
    int i = n;
    int j = m;
    while (i > 0) {
        if (table[i][j] != table[i - 1][j]) {
            cout << i << " ";
            j -= w[i];
        }
        i--;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    genTable();
    cout << table[n][m] << endl;
    Trace();  
}