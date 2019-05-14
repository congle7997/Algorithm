#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int m;
	cin >> m;
	int b[m];

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	int arr[n][10000];
	int count = 1;

	for (int i = 0; i < n; i++) {
		int k = a[i] + count;
		int z = 0;
		for (int j = count; j < k; j++) {
			arr[i][z] = j;
			count++;
			z++;
		}
	}

	int x = 0;
	do {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 10000; j++) {
				if (arr[i][j] == b[x]) {
					cout << i + 1 << " ";
					x++;
					i = n;
					j = 10000;
				}
			}

		}
	} while (x < m);
}
