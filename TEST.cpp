#include <iostream>
using namespace std;

int main() {
	string s = "26666";
	char result[] = null;

	if ((s[0] - 48) < 6) {
		result = new char[s.length()];
		for (int i = 0; i < s.length() - 1; i++) {
			result[i] = '8';
		}
	}

	cout << result;
}
