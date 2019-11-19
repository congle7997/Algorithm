#include <iostream>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    int distance[109];
    for (int i = 0; i < n; i++) {
        cin >> distance[i];
    }

    int price[109];
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    int min = price[0];
    int totalFuel = 0;
    for (int i = 0; i < n; i++) {
        if (price[i] < min) {
            min = price[i];
        }

        totalFuel += min * distance[i];
    }

    cout << totalFuel;
}