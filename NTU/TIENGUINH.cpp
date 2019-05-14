#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int x = n;
	int count = 0;
	while (x < m) {
		float laiTatCa = (float) x / 10;
		float laiPhanLe = (float) laiTatCa - (int) laiTatCa;

		int laiThuc = x / 10;
		if (laiPhanLe >= 0.5) {
			laiThuc += 1;
		}

		x += laiThuc;

		count++;
	}

	cout << count;
}
