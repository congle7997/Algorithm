#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[5009];
int f[50009];

void genTable() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] <= j) {
                f[j] = max(f[j], a[i] + f[j - a[i]]);
            }
            //cout << f[j] << " ";
        }
        //cout << endl;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);

    cin >> m >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    genTable();

    cout << f[m];
}