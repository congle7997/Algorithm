#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define ll long long
#define e8 100000009
using namespace std;

int a[e8], b[e8], MAX = 0;

int main() {
    freopen("input.txt", "r", stdin);
    //memset(a, -1, sizeof(a));
   // memset(b, -1, sizeof(b));
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int prev, next;
        cin >> prev >> next;
        a[prev] = next;
        b[next] = prev;

        if (prev > MAX) {
            MAX = prev;
        }
        if (next > MAX) {
            MAX = next;
        }
    }

    
    vector<int> v1, v2;
    if (n == 2) {
        cout << a[0];
    } else if (n % 2 == 0) {
        int x = 0, y = 0;
        while (a[x] != 0) {
            v1.push_back(a[x]);
            x = a[x];
        }
        while (b[y] != 0) {
            v2.push_back(b[y]);
            y = b[y];
        }

        int i = 0, j = (n / 2) - 1;
        while (true) {
            cout << v2[j] << " " << v1[i] << " ";
            i++;
            j--;

            if (j == -1) {
                break;
            }
        }
    }
    else {
        int k = 0;
        for (int i = 0; i <= MAX; i++) {
            if (b[i] != 0 && a[i] == -1) {
                k = i;
                break;
            }
        }

        int x = 0, y = k;
        while (a[x] != 0) {
            v1.push_back(a[x]);
            x = a[x];
        }
        while (y != -1) {
            v2.push_back(y);
            y = b[y];
        }

        int i = 0, j = (n / 2);
        while (true) {
            if (j >= 0) {
                cout << v2[j--] << " ";
            }
            if (i < n / 2) {
                cout << v1[i++] << " ";
            }
            
            if (j == -1 && i == n/ 2) {
                break;
            }
        }
    }
    
}