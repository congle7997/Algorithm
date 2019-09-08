#include <iostream>
using namespace std;

string changeState(int data, string state) {
	if (data == 1) {
		if (state == "down") {
			state = "right";
		}
		else if (state == "right") {
			state = "top";
		}
		else if (state == "top") {
			state = "left";
		}
		else if (state == "left") {
			state = "down";
		}
	}
	else if (data == 2) {
		if (state == "down") {
			state = "left";
		}
		else if (state == "right") {
			state = "down";
		}
		else if (state == "top") {
			state = "right";
		}
		else if (state == "left") {
			state = "top";
		}
	}

	return state;
}

int main() {
	int t;
	cin >> t;

  for (int k = 0; k < t; k++) {
    int n, m;
    cin >> n >> m;

    int a[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }

  	int arrBlue[m];
  	int arrRed[m];
    for (int i = 0; i < m; i++) {
      cin >> arrBlue[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> arrRed[i];
    }

    int rowBlue = 0, colBlue = 0;
  	int rowRed = n - 1, colRed = n - 1;
  	int bluePoint = 0;
  	int redPoint = 0;
  	int data;
  	string stateBlue = "down";
  	string stateRed = "top";

  	for (int i = 0; i < m; i++) {
  		data = arrBlue[i];
  		if (data == 0) {
  			if (stateBlue == "down") {
  				if (rowBlue + 1 == rowRed && colBlue == colRed) {
  					bluePoint -= a[rowBlue][colBlue];
  					break;
  				}
  				else {
  					a[rowBlue][colBlue] = 0;
  					bluePoint += a[rowBlue + 1][colBlue];
  					rowBlue += 1;
  				}
  			}
  			else if (stateBlue == "right") {
  				if (rowBlue == rowRed && colBlue + 1 == colRed) {
  					redPoint -= a[rowRed][colRed];
  					break;
  				}
  				else {
  					a[rowBlue][colBlue] = 0;
  					bluePoint += a[rowBlue][colBlue + 1];
  					colBlue += 1;
  				}
  			}
  			else if (stateBlue == "top") {
  				if (rowBlue - 1 == rowRed && colBlue == colRed) {
  					redPoint -= a[rowRed][colRed];
  					break;
  				}
  				else {
  					a[rowBlue][colBlue] = 0;
  					bluePoint += a[rowBlue - 1][colBlue];
  					rowBlue -= 1;
  				}
  			}
  			else if (stateBlue == "left") {
  				if (rowBlue == rowRed && colBlue - 1 == colRed) {
  					redPoint -= a[rowRed][colRed];
  					break;
  				}
  				else {
  					a[rowBlue][colBlue] = 0;
  					bluePoint += a[rowBlue][colBlue - 1];
  					colBlue -= 1;
  				}
  			}
  		}
  		else if (data == 1 || data == 2) {
  			stateBlue = changeState(data, stateBlue);
  		}

  		data = arrRed[i];
  		if (data == 0) {
  			if (stateRed == "down") {
  				if (rowRed + 1 == rowBlue && colRed == colBlue) {
  					bluePoint -= a[rowBlue][colBlue];
  					break;
  				}
  				else {
  					a[rowRed][colRed] = 0;
  					redPoint += a[rowRed + 1][colRed];
  					rowRed += 1;
  				}
  			}
  			else if (stateRed == "right") {
  				if (rowRed == rowBlue && colRed + 1 == colBlue) {
  					bluePoint -= a[rowBlue][colBlue];
  					break;
  				}
  				else {
  					a[rowRed][colRed] = 0;
  					redPoint += a[rowRed][colRed + 1];
  					colRed += 1;
  				}
  			}
  			else if (stateRed == "top") {
  				if (rowRed - 1 == rowBlue && colRed == colBlue) {
  					bluePoint -= a[rowBlue][colBlue];
  					break;
  				}
  				else {
  					a[rowRed][colRed] = 0;
  					redPoint += a[rowRed - 1][colRed];
  					rowRed -= 1;
  				}
  			}
  			else if (stateRed == "left") {
  				if (rowRed == rowBlue && colRed - 1 == colBlue) {
  					bluePoint -= a[rowBlue][colBlue];
  					break;
  				}
  				else {
  					a[rowRed][colRed] = 0;
  					redPoint += a[rowRed][colRed - 1];
  					colRed -= 1;
  				}
  			}
  		}
  		else if (data == 1 || data == 2) {
  			stateRed = changeState(data, stateRed);
  		}
  	}
  	cout << bluePoint << " " << redPoint << "\n";
  }
}
