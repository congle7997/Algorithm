#include <iostream>
#include "algorithm"
using namespace std;
int main() {
  int k;
  cin>>k;
  int a[k];

  for (int i=0; i<k; i++) {
    cin>>a[i];
  }

  a[k] = 0;
  sort(a, a+k);

  int b[100000], count = 0, index = 0, sum = 0;
  for (int i=0; i<k; i++) {
    count++;
    if (a[i] != a[i+1]) {
      b[index] = count;
      index++;
      count = 0;
      sum++;
    }
  }

  int tinh = 0;
  for (int i=0; i<sum; i++) {
    if (b[i] <= 5) {
      tinh += 100;
    } else {
      tinh += 100 + (b[i]-5);
    }
  }

  cout<<"\n"<<tinh;
}
