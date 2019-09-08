#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int y = 0; y < t; y++) {
    int n, k;
    cin >> n >> k;

    int a[n][n];

    int min = 10000;
    int max = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >>a[i][j];

        if (a[i][j] < min) {
          min = a[i][j];
        }
        if (a[i][j] > max) {
          max = a[i][j];
        }
      }
    }

    int floor;
    int minCost = 1000000000;

    for (int l = min; l <= max; l++) {
      int totalCost = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          int cost;
          if (a[i][j] < l) {
            cost = (l - a[i][j]) * (2 * k);
          } else if (a[i][j] > l) {
            cost = (a[i][j] - l) * k;
          } else {
            cost = 0;
          }

          totalCost += cost;
        }
      }

      if (totalCost < minCost) {
        minCost = totalCost;
        floor = l;
      }
    }

    cout << floor << " " << minCost << endl;
  }
}
