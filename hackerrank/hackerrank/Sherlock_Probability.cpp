#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int s[100000];

int main() {
	//fstream fs;
	//fs.open("test.txt");
	int t, n, k, i, j, begin = -1, end;
	long long int cnt;
	long long int temp;
	char ch;
	cin >> t;
	while (t--)
	{
		cnt = 0;
		begin = -1;
		cin >> n >> k;
		for (i = 0; i < n; i++)
		{
			cin >> ch;
			if (ch == '1') {
				s[i] = 1;
				if (begin == -1)
					begin = i;
				cnt++;
			}
			else {
				s[i] = 0;
			}
		}
		if (begin == -1) {
			cout << "0/1" << endl;
			continue;
		}
		temp = 0;
		for (end = begin + 1; end <= k + begin && end < n; end++)
		{
			
			if (s[end])
			{
				temp += 2;
			}					
		}
		cnt += temp;
		end--;
		while (1)
		{
			while (1)
			{
				if (s[++end])
					temp += 2;
				if (begin == n - 1)
					break;
				if (s[++begin])
					break;
			}
			if (begin == n - 1)
				break;
			temp -= 2;
			cnt += temp;
		}

		long long int below = pow(n, 2);
		int minValue = min(cnt, below);
		for (i = 2; i <= minValue; i++)
		{
			if (cnt%i == 0 && below%i == 0)
			{
				cnt /= i; below /= i;
				--i;
			}
		}
		cout << cnt << "/" << below << endl;
	}
	//fs.close();
	return 0;
}
