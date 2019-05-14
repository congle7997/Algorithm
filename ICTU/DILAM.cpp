#include "iostream"
#include "algorithm"
using namespace std;
int main() {
  int n;
  cin>>n;
  int arr[n];

  for (int i=0; i<n; i++) {
    cin>>arr[i];
  }

  sort(arr, arr+n);

  int min = 100000;
  for (int i=n-1; i>0; i--) {
    if (arr[i]-arr[i-1] < min) {
      min = arr[i]-arr[i-1];
    }
  }
  cout<<min;
}
