#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <stack>
#include <cmath>
using namespace std;

int n, m, X1, Y1, X2, Y2;
int a[109][109];
int b[19000];

bool isPreP() {
    if (X1 == X2) {
        if (X1 < X2) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (X1 < X2) {
        return true;
    }
    else if (X1 > X2) {
        return false;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> X1 >> Y1 >> X2 >> Y2;

    int valueP, valueQ;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];

            if (i == X1 && j == Y1) {
                valueP = a[i][j];
                a[i][j] = -1;
            }
            else if (i == X2 && j == Y2) {
                valueQ = a[i][j];
                a[i][j] = -2;
            }
        }
    }

    if (isPreP()) {
        int k = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] == -1) {
                    b[k++] = valueQ;
                    b[k++] = valueP;
                    continue;
                } else if (a[i][j] == -2) {
                    continue;
                }

                b[k++] = a[i][j];
            }
        }
    }
    else {
        int k = n * m;
        for (int i = n; i >= 1; i--) {
            for (int j = m; j >= 1; j--) {
                if (a[i][j] == -1) {
                    b[k--] = valueQ;
                    b[k--] = valueP;
                    continue;
                } else if (a[i][j] == -2) {
                    continue;
                }

                b[k--] = a[i][j];
            }
        }
    }

    int k = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << b[k++] << " ";
        }
        cout << endl;
    }
}