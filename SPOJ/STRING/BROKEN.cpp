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
	freopen("input.txt", "r", stdin);
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}

		string s;
		cin.ignore();
		getline(cin, s);

		int sum = 0;
		int res = 0;
		int k = 0;
		int i = 0;
		map<char, int> m;

		while (i < s.length()) {	
			m[s[i]]++;
			sum++;

			if (m[s[i]] == 1) {
				while (m.size() > n) {
					if (m[s[k]] >= 2) {
						m[s[k]]--;
					}
					else {
						m.erase(s[k]);
					}
					sum--;
					k++;
				}
			}

			if (sum > res) {
				res = sum;
			}
		
			i++;
		}

		cout << res << endl;
	}
}