#include <iostream>
#include <math.h>
using namespace std;

int c = 0;

void towerOfHanoi(int n, char source, char target, char auxiliary, int k, int a[]) {
	if (c == k) {
    return;
	}
	if (n == 1) {
		//cout << "Move disk 1 from " << source << " to " << target << endl;
		if (target == 'A') {
			a[0]++;
			c++;
			if (source == 'B') {
				a[1]--;
			}
			else if (source == 'C') {
				a[2]--;
			}
		}
		else if (target == 'B') {
			a[1]++;
			c++;
			if (source == 'A') {
				a[0]--;
			}
			else if (source == 'C') {
				a[2]--;
			}
		}
		else {
			a[2]++;
			c++;
			if (source == 'A') {
				a[0]--;
			}
			else if (source == 'B') {
				a[1]--;
			}
		}
	}
	else {
		towerOfHanoi(n - 1, source, auxiliary, target, k, a);
		//cout << "Move disk " << n << " from " << source << " to " << target << endl;
		if (c == k) {
      return;
		}
		if (target == 'A') {
			a[0]++;
			c++;
			if (source == 'B') {
				a[1]--;
			}
			else if (source == 'C') {
				a[2]--;
			}
		}
		else if (target == 'B') {
			a[1]++;
			c++;
			if (source == 'A') {
				a[0]--;
			}
			else if (source == 'C') {
				a[2]--;
			}
		}
		else {
			a[2]++;
			c++;
			if (source == 'A') {
				a[0]--;
			}
			else if (source == 'B') {
				a[1]--;
			}
		}
		towerOfHanoi(n - 1, auxiliary, target, source, k, a);
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	int a[3] = { n, 0, 0 };

  if (n == 0) {
    cout << 0 << " " << 0 << " " << 0;
  }
  else if (k == 0) {
    cout << n << " " << 0 << " " << 0;
  }
  else {
    towerOfHanoi(n, 'A', 'B', 'C', k, a);
    cout << a[0] << " " << a[1] << " " << a[2];
  }
}
