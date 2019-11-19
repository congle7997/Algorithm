#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int a[109], b[109], f[109];
void genTable() {
    for (int i = 1; i <= n; i++) {
        int x = b[i];
        for (int j = 1; j < i; j++) {
            if (a[i] - a[j] >= k && b[i] + f[j] > x) {
                x = b[i] + f[j];
            }
        }

        f[i] = max(x, f[i - 1]);
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << f[i] << " ";
    // }
}

int main() {
    //freopen("input.txt", "r", stdin);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    genTable();

    cout << f[n];
}