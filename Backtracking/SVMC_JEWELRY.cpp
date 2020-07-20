#include <iostream>
using namespace std;

int a[100][100], v[100][100], n, res = 0, c = 0;

void move(int x, int y) {
    v[x][y] = true;
    if (a[x][y] == 2) {
        c++;
    }
    bool flag = false;
    if (x == n - 1 && y == n - 1) {
        if (c > res) {
            res = c; 
        }
        flag = true;
    }

    if (!flag) {
        // up
        if (x - 1 >= 0 && a[x - 1][y] != 1 && v[x - 1][y] == false) {
            move(x - 1, y);
        // v[x - 1][y] = false;
        }
        // right
        if (y + 1 < n && a[x][y + 1] != 1 && v[x][y + 1] == false) {
            move(x, y + 1);
        // v[x][y + 1] = false;
        }
        // down
        if (x + 1 < n && a[x + 1][y] != 1 && v[x + 1][y] == false) {
            move(x + 1, y);
        // v[x + 1][y] = false;
        }
        // left
        if (y - 1 >= 0 && a[x][y - 1] != 1 && v[x][y - 1] == false) {
            move(x, y - 1);
        // v[x][y - 1] = false;
        }
    }
    
    v[x][y] = false;
    if (a[x][y] == 2) {
        c--;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    move(0, 0);
    cout << res;

/* 3
    0 2 1
    1 2 0
    2 2 0*/
}
