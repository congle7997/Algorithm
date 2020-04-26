#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <stdio.h>
#include <stack>
#include <math.h>
using namespace std;

struct Node {
    int left;
    int right;
};

int main() {
    freopen("input.txt", "r", stdin);

    int n, x;
    cin >> n >> x;

    Node list[100009];

    for (int i = 1; i <= n; i++) {
        list[i].left = i - 1;
        list[i].right = i + 1;
    }

    for (int i = 0; i < x; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        // remove
        list[list[n1].left].right = list[n1].right;
        list[list[n1].right].left = list[n1].left;

        // insert
        list[n1].left = list[n2].left;
        list[n1].right = n2;

        list[list[n1].left].right = n1;
        list[list[n1].right].left = n1;
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << list[i].left << " " << i << " " << list[i].right << endl;
    // }

    int pos = 0;
    for (int i = 1; i <= n; i++) {
        if (list[i].left == 0) {
            pos = i;
            break;
        }
    }

    while (pos <= n) {
        cout << pos << " ";
        pos = list[pos].right;
    }
}