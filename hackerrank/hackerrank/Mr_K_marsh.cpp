#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include "string.h"
using namespace std;
char land[500][500];
int m, n;
int maxcnt = 0;
#define UP 0x10
#define DOWN 0x100
#define LEFT 0x1000
#define RIGHT 0x10000
#define TEST



int valid(int x1, int y1, int x2, int y2)
{
	if (x2 == x1 || y2 == y1)
		return 0;
	for (int j = y1; j <= y2; j++)
	{
		if (land[x1][j] == 120)
			return UP;
	}
	for (int i = x1 + 1; i <= x2; i++)
	{
		if (land[i][y1] == 120)
			return LEFT;
	}
	for (int j = y1 + 1; j <= y2; j++)
	{
		if (land[x2][j] == 120)
			return DOWN;
	}
	for (int i = x1 + 1; i < x2; i++)
	{
		if (land[i][y2] == 120)
			return RIGHT;
	}
	if (maxcnt < 2 * (x2 - x1 + 1) + 2 * (y2 - y1 - 1))
		maxcnt = 2 * (x2 - x1 + 1) + 2 * (y2 - y1 - 1);
	return 1;
}


int main() {
	
#ifdef TEST
	fstream fs;
	fs.open("test.txt");
#endif
	memset(land, 0, sizeof(land));
#ifdef TEST
	fs >> m >> n;
#endif
#ifndef TEST
	cin >> m >> n;
#endif
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
#ifdef TEST
			fs >> land[i][j];
#endif
#ifndef TEST
			cin >> land[i][j];
#endif
		}
	}
	int a, b, c, d, temp, k, s;
	for (a = 0; a < m - 1; a++)
	{
		for (b = 0; b < n - 1; b++)
		{
			c = a + 1;
			d = b + 1;			
			while (!((c == m - 1) && (d == n - 1)))
			{
				if (land[c][b] == 120 || land[a][d] == 120 || land[a][b] == 120)
					goto B;
				for (s = d; s < n; s++)
				{
					valid(a, b, c, s);
				}
				for (k = c; k < m; k++)
				{
					valid(a, b, k, d);
				}
				c += (c < m - 1) ? 1 : 0;
				d += (d < n - 1) ? 1 : 0;
			}
		B:
			;
		}
	A:
		;
	}
	if (maxcnt == 0)
		cout << "impossible" << endl;
	else 
		cout << maxcnt << endl;
#ifdef TEST
	fs.close();
	system("pause");
#endif
	return 0;
}
