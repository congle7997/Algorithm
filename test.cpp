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

const int N = 1e5 + 9;
int a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 1; i < n; i ++) {
        bool flag = true;
        for (int j = 0; j < i; j++) {
            if (v[i] < v[j]) {
                cout << v[i] << " " << j << endl;
                v.insert(v.begin() + j, v[i]);
                v.erase(v.begin() + (i + 1));
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << v[i] << " " << i << endl;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}
    