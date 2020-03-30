#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <cmath>
#include <stdio.h>
using namespace std;

int row[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int col[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int main() {
	//freopen("input.txt", "r", stdin);
	int t = 0;
	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		int q, k, p, arrQ[209], arrK[209], arrP[209];
		cin >> q;
		for (int i = 0; i < q * 2; i++) {
			cin >> arrQ[i];
		}
		cin >> k;
		for (int i = 0; i < k * 2; i++) {
			cin >> arrK[i];
		}
		cin >> p;
		for (int i = 0; i < p * 2; i++) {
			cin >> arrP[i];
		}

		vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));

		for (int i = 0; i < p * 2; i += 2) {
			a[arrP[i]][arrP[i + 1]] = 1;
		}
		for (int i = 0; i < k * 2; i += 2) {
			a[arrK[i]][arrK[i + 1]] = 1;
			for (int j = 0; j < 8; j++) {
				if ((arrK[i] + row[j] >= 1 && arrK[i] + row[j] <= n)
					&& (arrK[i + 1] + col[j] >= 1 && arrK[i + 1] + col[j] <= m)
					&& a[arrK[i] + row[j]][arrK[i + 1] + col[j]] != 1) {
					a[arrK[i] + row[j]][arrK[i + 1] + col[j]] = 2;
				}
			}
		}
		for (int i = 0; i < q * 2; i += 2) {
			a[arrQ[i]][arrQ[i + 1]] = 1;
			int j = 1;

			while (arrQ[i] - j >= 1) {
				if (a[arrQ[i] - j][arrQ[i + 1]] != 1) {
					a[arrQ[i] - j][arrQ[i + 1]] = 2;
					j++;
				}
				else {
					break;
				}
			}

			j = 1;
			while (arrQ[i] + j <= n) {
				if (a[arrQ[i] + j][arrQ[i + 1]] != 1) {
					a[arrQ[i] + j][arrQ[i + 1]] = 2;
					j++;
				}
				else {
					break;
				}
			}

			j = 1;
			while (arrQ[i + 1] - j >= 0) {
				if (a[arrQ[i]][arrQ[i + 1] - j] != 1) {
					a[arrQ[i]][arrQ[i + 1] - j] = 2;
					j++;
				}
				else {
					break;
				}
			}

			j = 1;
			while (arrQ[i + 1] + j <= m) {
				if (a[arrQ[i]][arrQ[i + 1] + j] != 1) {
					a[arrQ[i]][arrQ[i + 1] + j] = 2;
					j++;
				}
				else {
					break;
				}
			}

			//cheo
			int r = 1, c = 1;
			while (arrQ[i] - r >= 1 && arrQ[i + 1] - c >= 1) {
				if (a[arrQ[i] - r][arrQ[i + 1] - c] != 1) {
					a[arrQ[i] - r][arrQ[i + 1] - c] = 2;
					r++;
					c++;
				}
				else {
					break;
				}
			}
			r = 1, c = 1;
			while (arrQ[i] - r >= 1 && arrQ[i + 1] + c <= m) {
				if (a[arrQ[i] - r][arrQ[i + 1] + c] != 1) {
					a[arrQ[i] - r][arrQ[i + 1] + c] = 2;
					r++;
					c++;
				}
				else {
					break;
				}
			}
			r = 1, c = 1;
			while (arrQ[i] + r <= n && arrQ[i + 1] + c <= m) {
				if (a[arrQ[i] + r][arrQ[i + 1] + c] != 1) {
					a[arrQ[i] + r][arrQ[i + 1] + c] = 2;
					r++;
					c++;
				}
				else {
					break;
				}
			}
			r = 1, c = 1;
			while (arrQ[i] + r <= n && arrQ[i + 1] - c >= 1) {
				if (a[arrQ[i] + r][arrQ[i + 1] - c] != 1) {
					a[arrQ[i] + r][arrQ[i + 1] - c] = 2;
					r++;
					c++;
				}
				else {
					break;
				}
			}
		}

		int res = 0;
		for (int i = 1; i < a.size(); i++) {
			for (int j = 1; j < a[0].size(); j++) {
				if (a[i][j] == 0) {
					res++;
				}
			}
		}
		
		// string s = "";
		// s += "Board " + to_string(++t) + " has " + to_string(res) + " safe squares.";
		// cout << s << endl;
		cout << "Board " << to_string(++t) << " has " << to_string(res) << " safe squares." << endl;
	}
}