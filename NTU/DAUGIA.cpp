#include <iostream>
using namespace std;

bool isPrime(int x) {
	if (x < 2) {
		return false;
	}
	else {
		for (int i = 2; i < x; i++) {
			if (x % i == 0) {
				return false;
			}
		}
	}

	return true;
}

int a[9];
bool check(int x) {
	for (int i = 0; i < 5; i++) {
		a[i] = x % 10;
		x = x / 10;
	}

	int start = 0;
	int end = 4;
	for (int i = 0; i < 5/2; i++) {
		if (a[start] != a[end]) {
			return false;
		}
		else {
			start++;
			end--;
		}
	}

	return true;

}

int main() {
	int a, b;
	cin >> a >> b;

	int count = 0;
	for (int i = a; i <= b; i++) {
		/* chay dieu kien kiem tra doi xung truoc se loai bo duoc nhieu truong hop hon so voi
		chay dieu kien kiem tra so nguyen to qua do se giam duoc thoi gian chay */
		if (check(i) && isPrime(i)) {
			count++;
		}
	}

	cout << count;
}
