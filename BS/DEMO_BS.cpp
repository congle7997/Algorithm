#include <iostream>
#include <algorithm>
#define ll long long
#define e8 100000009
using namespace std;
 
int a[e8]; 
int n, x;

int binarySearch(int left, int right) {
    if (left <= right) {
        int mid = left + ((right - left) / 2);

        if (a[mid] == x) {
            return mid;
        } else if (a[mid] > x) {
            return binarySearch(left, mid - 1);
        } else if (a[mid] < x) {
            return binarySearch(mid + 1, right);
        }
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;
    cout << binarySearch(0, n - 1);
}  