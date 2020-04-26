#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stdio.h>
#include <stack>
#include <math.h>
using namespace std;

const int N = 1e5 + 9;

struct Node {
    int left;
    int right;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int n, x;
    cin >> n >> x;

    Node list[N];
    list[1].left = n;
    list[1].right = 2;
    list[n].left = n - 1;
    list[n].right = 1;
    for (int i = 2; i <= n - 1; i++) {
        list[i].left = i - 1;
        list[i].right = i + 1;
    }

    for (int i = 0; i < x; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        list[list[n1].left].right = list[n1].right;
        list[list[n1].right].left = list[n1].left;

        list[n1].left = n2;
        list[n1].right = list[n2].right;

        list[list[n1].left].right = n1;
        list[list[n1].right].left = n1;
    }

    int pos = 1;
    while (true) {
        cout << pos << " ";
        if (list[pos].right == 1) {
            break;
        }
        pos = list[pos].right;
    }
}