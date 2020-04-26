#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <stdio.h>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	while (true)
	{
		string s;
		cin >> s;
		if (s == "*")
		{
			break;
		}

		string temp = "";
		int res = 0;
		int i = 0;
		bool flag = false;
		while (i < s.length())
		{
			temp += s[i];

			if (s.length() % temp.length() == 0)
			{
				int k = i + 1;
				while (k + temp.length() <= s.length())
				{
					if (temp == s.substr(k, temp.size()))
					{
						res++;
						k += temp.length();
						if (k == s.length())
						{
							flag = true;
							break;
						}
					}
					else
					{
						res = 0;
						break;
					}
				}
				if (flag)
				{
					break;
				}
			}

			i++;
		}

		cout << res + 1 << endl;
	}
}