#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }

        string s;
        cin >> s;

        char a[101][21];
        int k = 0;
        for (int i = 0; i < s.length() / 2; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = s[k];
                    k++;
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    a[i][j] = s[k];
                    k++;
                }
            }
        }

        string res = "";
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < s.length() / n; i++) {
                res += a[i][j];
            }
        }
        cout << res << endl;
    }
}