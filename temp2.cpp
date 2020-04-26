#include <iostream>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int a[3];
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;

    for (int i = 0; i < 3; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    swap(a[1], a[2]);
    for (int i = 0; i < 3; i++) {
        cout << a[i] << " ";
    }
}