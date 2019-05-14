#include <iostream>
using namespace std;
int main() {
  int a, b, v;
  cin>>a>>b>>v;

  int m = 0;
  int n = 0;

  if (a >= v) {
    cout<<"1";
  } else {
    do {
      m += a-b;
      n++;
      if (m+a >= v) {
        cout<<n+1;
        break;
      }
    } while (m+a <= v);
  }
}
