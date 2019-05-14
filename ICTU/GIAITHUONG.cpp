#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	/*in: 5
			1 6 2 1 1
	out: 9*/

	int n;
	cin>>n;
	long a[n];

	for(long int i = 0; i <n; i++){
		cin >>a[i];
	}

	// gan them 1 phan tu nua vao mang de sau con so sanh phan tu cuoi
	a[n] = 0;

	sort(a, a+n);

  long long  min = 1E14, sum = 0, sumAll = 0;
  for(long i = 0; i<n; i++){
    sum += a[i];
    sumAll += a[i];
    if(a[i] != a[i+1]) {
			if(sum < min) {
				min = sum;
			}
			sum = 0;
		}
	}

	cout <<sumAll-min;
}
