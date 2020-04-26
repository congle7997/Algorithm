#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int c[], int left, int right, int x) {
	if (left <= right) {

		//int mid = left + (right - left) / 2;
		int mid = (left+right)/2;

    if (c[mid-1] < x && c[mid] >= x) {
      return mid;
    }
		else if (c[mid] < x) {
			return binarySearch(c, mid+1, right, x);
		}
		else if (c[mid] > x) {
			return binarySearch(c, left, mid - 1, x);
		} else {
      return 0;
    }
	}
}

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


	int c[n];
  int x = 0;
	for (int i = 0; i < n; i++) {
    x += a[i];
		c[i] = x;
	}

  int left = 0;
  int right = n-1;
  for (int i=0; i<m; i++) {
    cout<<binarySearch(c, left, right, b[i])+1<<" ";
  }

}
