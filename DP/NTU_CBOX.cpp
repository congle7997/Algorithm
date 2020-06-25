#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stdio.h>
#include <stack>
#include <math.h>
#include <vector>
#define ll long long
using namespace std;

const int N = 1e8 + 9;
int a[N], b[N], res[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        a[start]++;
        a[end + 1]--;
    }

    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        res[b[i]]++;
    }

    for (int i = n; i >= 1; i--) {
        res[i] = res[i + 1] + res[i];
    }

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        cout << res[k] << endl;
    }
}
