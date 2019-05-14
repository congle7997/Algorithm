#include <iostream>
using namespace std;

int binarySearch(int a[], int left, int right, int x) {
	if (right >= left) {

		//int mid = left + (right - left) / 2;
		int mid = (left+right)/2;

		if (a[mid] < x) {
			return binarySearch(a, mid+1, right, x);
		}
		else if (a[mid] > x) {
			return binarySearch(a, left, mid - 1, x);
		}
		else {
			return mid;
		}
	}
}

int main() {
	int a[10] = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
	int left = 0;
	int right = 10;
	int x = 23;
	int result = binarySearch(a, left, right - 1, x);
	cout << "x = "<<x<<" in position "<<result;
}
