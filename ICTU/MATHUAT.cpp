#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkExist(string str) {
	bool findE = false;
	bool findI = false;
	bool findO = false;

	for (int i = 0; i < str.length(); i++) {
		if (findE == false) {
			if (str[i] == 'e') {
				findE = true;
			}
		}
		else if (findE == true && findI == false) {
			if (str[i] == 'i') {
				findI = true;
			}
		}
		else if (findE == true && findI == true && findO == false) {
			if (str[i] == 'o') {
				findO = true;
				return true;
			}
		}
	}

	return false;
}

void pushVectorAU(string s) {
	vector<int> vectorA;
	vector<int> vectorU;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a') {
			vectorA.push_back(i);
		}
		else if (s[i] == 'u') {
			vectorU.push_back(i);
		}
	}

	string str = "";
	vector<int> vectorIndexFirst;
	vector<int> vectorIndexLast;
	for (int i = 0; i < vectorA.size(); i++) {
		for (int j = 0; j < vectorU.size(); j++) {
			str = s.substr(vectorA[i], (vectorU[j]-vectorA[i])+1);
			if (checkExist(str)) {
				if (vectorU[j] - vectorA[i] > 0) {
					vectorIndexFirst.push_back(vectorA[i]);
					vectorIndexLast.push_back(vectorU[j]);
					break;
				}
			}
		}
	}

	vector<int> size;
	for (int i = 0; i < vectorIndexFirst.size(); i++) {
		size.push_back(vectorIndexLast[i] - vectorIndexFirst[i]);
	}



	if (size.size() == 0) {
		cout << "-1 -1" << endl;
	}
	else {
		int min = 1000;
		int index;
		for (int i = 0; i < size.size(); i++) {
			if (size[i] < min) {
				min = size[i];
				index = i;
			}
		}
		cout << vectorIndexFirst[index] + 1  << " " << vectorIndexLast[index] + 1 << endl;
	}

}

int main() {
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		pushVectorAU(s);
	}
}
