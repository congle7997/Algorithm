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

int partition(int start, int end) {
    int pivot = a[end];
    int k = start;

    for (int i = start; i <= end - 1; i++) {
        if (a[i] < pivot) {
            swap(a[i], a[k]);
            if (i != k) {
                cout << k + 1 << " " << i + 1 << "\n";
            }
            k++;
        }
    }
    swap(a[k], a[end]);
    if (k != end) {
        cout << k + 1 << " " << end + 1 << "\n";
    }
    return k;
}

void quickSort(int start, int end) {
    if (start < end) {
        int pivot = partition(start, end);
        quickSort(start, pivot - 1);
        quickSort(pivot + 1, end);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quickSort(0, n - 1);
}
