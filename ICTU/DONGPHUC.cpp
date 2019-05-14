#include <iostream>
using namespace std;
int main() {
  long long m, n, t;
  cin>>m>>n>>t;

    if (n % (m+1) == 0) {
      cout<<((n/(m+1))*m)*t;
    } else {
      cout<<(((n/(m+1))*m)+(n%(m+1)))*t;
    }

}
