#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;

	int a[109];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n, greater<int>());

	if (a[0] == 0)
	{
		cout << 1;
	}
	else
	{
		int res = n, x = n;
		for (int i = 0; i < n - 1; i++)
		{
			if (a[i] >= x)
			{
				x--;
				continue;
			}
			else if (a[i] == 0)
			{
				break;
			}
			else
			{
				res -= x - (a[i] + 1);
				x = a[i];
			}
		}

		cout << res;
	}
}
