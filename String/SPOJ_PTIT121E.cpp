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

struct Range {
	int start;
	int end;
};

string s;
vector<Range> v;

int calculate(int i, int value) {
	int sum = value;
	if (s[i + 1] >= 48 && s[i + 1] <= 57) {
		sum *= s[i + 1] - 48;
	}

	for (int j = 0; j < v.size(); j++) {
		if (v[j].start < i && v[j].end > i) {
			if (s[v[j].end + 1] >= 48 && s[v[j].end + 1] <= 57) {
				sum *= (s[v[j].end + 1] - 48);
			}
		}
		
	}

	return sum;
}

int main() {
	freopen("input.txt", "r", stdin);
	
	cin >> s;
	
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			int balance = 1;
			bool flag = false;;
			for (int j = i + 1; j < s.length(); j++) {
				if (s[j] == '(') {
					balance++;
				}
				else if (s[j] == ')') {
					balance--;
				}

				if (balance == 0) {
					v.push_back({ i, j });
					flag = true;
					break;
				}

				if (flag == true) {
					break;
				}
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < s.length(); i++) {	
		if (s[i] == 'C') {
			sum += calculate(i, 12);
		}
		else if (s[i] == 'H') {
			sum += calculate(i, 1);
		}
		else if (s[i] == 'O') {
			sum += calculate(i, 16);
		}
	}

	cout << sum;
}