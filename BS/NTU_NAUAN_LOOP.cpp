#include <iostream>
#include <algorithm>
using namespace std;

struct MyStruct {
	int index;
	int value;
};

bool compare(MyStruct st1, MyStruct st2) {
	return (st1.value < st2.value);
}
bool compare2(MyStruct st1, MyStruct st2) {
	return (st1.index < st2.index);
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
	MyStruct st[m];
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		st[i].index = i;
		st[i].value = b[i];
	}

	sort(st, st+m, compare);

	int c[n];
  int x = 0;
	for (int i = 0; i < n; i++) {
    x += a[i];
		c[i] = x;
	}

	int k = 0;
	for (int i=0; i<n; i++) {
		if (st[k].value <= c[i]) {
				st[k].value = i;
				// bắt trường hợp 2 số cạnh nhau bằng nhau
				if (st[k+1].value <= c[i] && (k+1 < m)) {
					i--;
				}
				k++;
		}
	}

	sort(st, st+m, compare2);
	for (int i=0; i<m; i++) {
		cout<<(st[i].value)+1<<" ";
	}
}
