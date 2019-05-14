#include "iostream"
#include "algorithm"
using namespace std;

int main() {
  int n, x;
  cin>>n>>x;
  int a[n];

  for (int i=0; i<n; i++) {
    cin>>a[i];
    a[i] = a[i]%x;
  }

  sort(a, a+n);

  int dem = 1;
  for (int i=0; i<n-1; i++) {
    if (a[i] != a[i+1]) {
      dem++;
    }
  }
  cout<<dem;


}
