#include <iostream>
using namespace std;

int n, k;
int a[1009][1009], table[1009][1009];

void genPrefixSumTable() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            table[i][j] = table[i - 1][j] + table[i][j - 1] - table[i - 1][j - 1] + a[i][j];
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

void Trace() {
    int max = 0;
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= n; j++) {
            int x = table[i][j] - table[i - k][j] - table[i][j - k] + table[i - k][j - k];  
            if (x > max) {
                max = x;
            }
        }     
    }
    cout << max;
}

int main() {
    //freopen("input.txt", "r", stdin);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    genPrefixSumTable();
    Trace();
}