#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int k = 0; k < t; k++) {
    string s;
    cin >> s;

    int count = 0;
    int x = 1;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'C') {
        count += x;
        x++;
      } else if (s[i] == 'N') {
        x = 1;
      }
    }

    cout << count << endl;
  }
}
