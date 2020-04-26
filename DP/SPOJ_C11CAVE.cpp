#include<iostream>
using namespace std;

int a[1000009], freqBot[1000009], freqTop[1000009], dpBot[1000009], dpTop[1000009];

int main() {
	freopen("input.txt", "r", stdin);

	int n, h;
	cin >> n >> h;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			freqBot[a[i]]++;
		}
		else {
			freqTop[a[i]]++;
		}
	}


	dpBot[h] = freqBot[h];
	dpTop[h] = freqTop[h];
	for (int i = h - 1; i >= 1; i--) {
		dpBot[i] = dpBot[i + 1] + freqBot[i];
		dpTop[i] = dpTop[i + 1] + freqTop[i];
	}

	int min = n, count = 0;
	for (int i = 1; i <= h; i++) {
		int x = dpBot[i] + dpTop[h - i + 1];
		if (x == min) {
			count++;
		} else if (x < min) {
			min = x;
			count = 1;
		}
	}

	cout << min << " " << count;
}