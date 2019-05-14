#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int a[n][n];
  int count = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < n-k+1; i++) {
    for (int j = 0; j < n-k+1; j++) {
      int check = 0;
      for (int x = i; x < i + k; x++) {
        for (int y = j; y < j + k; y++) {
          if (a[x][y] == 0) {
            break;
          }
          else {
            check++;
          }
        }
        if (check == k*k) {
          count++;
        }
      }
    }
  }
  
  cout << count;
}
