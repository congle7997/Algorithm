#include <iostream>
using namespace std;

int main() {
	int k, n, m;
	cin >> k >> n >> m;

	int div = k / m;
	int mod = k % m;
	int value1;
	int value2;
	int count = 0;
	int flag = 0;

  if (k < m) { // test 2 4 6
    if (k % n == 0) {
      cout << k / n;
      flag = 1;
    }
  } else if (k % m == 0) {
    cout << k / m;
    flag = 1;
  } else {
    for (int i = div; i > 0; i--) {
  		value1 = m * div;
  		for (int j = 1; j <= k - value1; j++) {
  			value2 = value1 + (j * n);
  			count++;
  			if (value2 == k) {
  				cout << count + div;
  				break;
  			}
  		}
  		if (value2 == k) {
  			flag = 1;
  			break;
  		}

      value2 = 0;
  	  count = 0;
      div--;
  	}
  }

	if (flag == 0) {
		cout << "-1";
	}
}
