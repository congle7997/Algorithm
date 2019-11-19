#include<iostream>
#include<string>
#include<algorithm>
//#include<fstream>
using namespace std;
string a, b, res = "";
string MIN = "9999999999";
string MAX = "0";
long long n, m, k;

void enter()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;

	n = a.length();
	m = b.length();
	k = m + n;
}

void backtrack(long long i, long long j, string res)
{
	if (res.length() == k)
	{
		MIN = min(MIN, res);
		MAX = max(MAX, res);
	}
	if (i < n)
		backtrack(i + 1, j, res + a[i]);
	if (j < m)
		backtrack(i, j + 1, res + b[j]);
	return;
}

int main()
{
	enter();
	backtrack(0, 0, "");
	cout << MIN << endl << MAX;
	return 0;
}
    