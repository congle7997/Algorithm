#include<iostream>
using namespace std;

int fib(int n)
{
	/* Declare an array to store Fibonacci numbers. */
	int f[n];   // 1 extra to handle case, n = 0

	/* 0th and 1st number of the series are 0 and 1*/
	f[1] = 1;
	f[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}


	return f[n];
}

int main() {
	int n;
	cin >> n;

	cout << fib(n);
}
