#include <iostream>
#include <algorithm>
using namespace std;

string x, y, temp;
int xLen, yLen, resultLen;
string maxNumber = "11", minNumber = "9999999999999999";

void Try(int xPos, int yPos, string temp) {
	if (xPos <= xLen) {
		Try(xPos + 1, yPos, temp + x[xPos]);
	}
	if (yPos <= yLen) {
		Try(xPos, yPos + 1, temp + y[yPos]);
	}

	if (temp.length() == resultLen) {
		minNumber = min(minNumber, temp);
        maxNumber = max(maxNumber, temp);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);

	cin >> x >> y;

	xLen = x.size();
	yLen = y.size();
	resultLen = xLen + yLen;

	// " 13" & " 26"
	x.insert(0, 1, ' ');
	y.insert(0, 1, ' ');

	Try(1, 1, "");

    cout << minNumber << "\n" << maxNumber;  
}
