#include <iostream>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	int a[n][n];

	int max = 0;
	int count = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n - k + 1; i++) {
		for (int j = 0; j < n - k + 1; j++) {
			for (int y = 0; y < k; y++) {
				for (int z = 0; z < k; z++) {
					count += a[y+i][z+j];
				}
			}
			if (count > max) {
        max = count;
      }
			count = 0;
		}
	}

  cout << max;
}
