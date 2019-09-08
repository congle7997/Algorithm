#include <iostream>
#include <vector>
using namespace std;

struct CharacterCount {
	char character;
	int count;
};

int main() {
	string m;
	cin >> m;

	vector<CharacterCount> v;
	v.push_back({ m[0], 1 });

	for (int i = 1; i < m.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (m[i] == v[j].character) {
				v[j].count += 1;
				break;
			}
			else if (m[i] != v[j].character && j == v.size() - 1) {
				v.push_back({ m[i], 1 });
				break;
			}
		}
	}

	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].character << " " << v[i].count << endl;
	}
}
