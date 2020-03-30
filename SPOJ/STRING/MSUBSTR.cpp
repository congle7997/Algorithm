#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <stdio.h>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string s;
		cin >> s;

		bool flag = false;
		int limit = s.length();
		int i = 0;
		int count = 0;
		while (limit > 0) {
			int j = 0;
			while (j <= s.length() - limit) {
				if (s[j] == s[j + limit - 1]) {
					bool isReverse = true;
					for (int k = 0; k <= (limit - 1) / 2; k++) {
						if (s[j + k] != s[j + limit - 1 - k]) {
							isReverse = false;
							break;
						}
					}
					if (isReverse) {
						flag = true;
						count++;
					}
				}
				j++;	
			}

			if (flag) {
				break;
			}

			limit--;
		}

		cout << limit << " " << count << endl;
	}
}