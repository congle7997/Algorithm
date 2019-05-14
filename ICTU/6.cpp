#include <iostream>
using namespace std;
int main() {
  int n;
  cin>>n;
  int a[n][n];
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cin>>a[i][j];
    }
  }

  int top1 = 0;
  int top2 = n;
  int right1 = 1;
  int right2 = n-1;
  int bottom1 = n-1;
  int bottom2 = 0;
  int left1 = n-2;
  int left2 = 0;
  for (int i=0; i<=n/2; i++) {
    for (int j1=top1; j1<top2; j1++) {
      cout<<a[top1][j1]<<" ";
    }
    top1++;
    top2--;
    for (int j2=right1; j2<=right2; j2++) {
      cout<<a[j2][right2]<<" ";
    }
    right1++;
    right2--;
    for (int j3=bottom1-1; j3>=bottom2; j3--) {
      cout<<a[bottom1][j3]<<" ";
    }
    bottom1--;
    bottom2++;
    for (int j4=left1; j4>left2; j4--) {
      cout<<a[j4][left2]<<" ";
    }
    left1--;
    left2++;
    cout<<"\n";
  }
}
