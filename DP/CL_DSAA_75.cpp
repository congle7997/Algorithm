#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define ll long long
#define e8 100000009
#define e4 10009
using namespace std;

int a[e8], f[e8];

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int x;
    cin >> x;

    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j] == i) {
                f[i] = 1;
                break;
            } else if (a[j] < i) {
                int v = f[i - a[j]];
                if (f[i] == 0 && v > 0) {
                    f[i] = v + 1;
                } else if (f[i] != 0 && v + 1 < f[i]) {
                    f[i] = v + 1;
                }
            }
        }
    }

    cout << f[x];
}