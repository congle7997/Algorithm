#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int x, n, m;
    cin >> x >> n >> m;

    if (x % m == 0) {
        cout << x / m;
    }
    else if (x < n && x < m) {
        cout << -1;
    }
    else {
        int div = x / m;
        int mod = x % m;
        bool flag = false;
        for (int i = 0; i <= div; i++) {
            if ((mod + (m * i)) % n == 0) {
                int res = (div - i) + (mod + (m * i)) / n;
                cout << res;
                flag = true;
                break;
            }
        }

        if (flag == false) {
            if (x % n == 0) {
                cout << x / n;
            }
            else {
                cout << -1;
            }
        }
    }
}
