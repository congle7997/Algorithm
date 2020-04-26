#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <stack>
#include <cmath>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    while (true) {
        stack<int> s;

        int n, a[1009], b[1009];
        cin >> n;
        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }

        sort(b, b + n);

        int i = 0, j = 0;
        while (true) {
            if (a[i] == b[j]) {
                i++;
                j++;
            }
            else if (!s.empty() && s.top() == b[j]) {
                j++;
                s.pop();
            }
            else {
                if (s.empty()) {
                    s.push(a[i]);
                }
                else {
                    if (s.top() > a[i]) {
                        s.push(a[i]);
                    }
                    else {
                        cout << "no\n";
                        break;
                    }
                }
                i++;
            }

            if (i == n + 1) {
                cout << "yes\n";
                break;
            }
        }
    }
}