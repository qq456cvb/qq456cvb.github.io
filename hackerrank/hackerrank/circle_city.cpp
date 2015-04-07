#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

/* gloabal variables */
int t = 0;


int main() {
	//fstream fs;
	//fs.open("test.txt");
	int r, l, cnt;
	cin >> t;
	while (t--)
	{
		cnt = 0;
		cin >> r >> l;
		int x, y;
		double temp_x = sqrt(r);
		x = floor(temp_x);
		if (x == temp_x)
			l -= 4;
		else
			x++;
		y = 1;
		while (x >= y)
		{
			while ((long long)pow(x, 2) + (long long)pow(y, 2) > (long long)r)
			{
				x--;
			}
			if ((long long)pow(x, 2) + (long long)pow(y, 2) == (long long)r && x != 0)
			{
				cnt += 2;
				if (x == y)
					cnt -= 1;
				else if (x < y)
					cnt -= 2;
			}				
			y++;
		}
		if (4 * cnt > l)
			cout << "impossible" << endl;
		else
			cout << "possible" << endl;
	}
	//fs.close();
	//system("pause");

	return 0;
}
