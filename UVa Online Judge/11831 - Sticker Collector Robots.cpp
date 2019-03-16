#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

ofstream fout("f.out");

int main()
{
	int n, m, intro;

	while (cin >> n >> m >> intro, n != 0 && m != 0 && intro != 0)
	{
		int x = 0, y = 0;
		bool found = false;

		int orientation, how = 0;

		string s, go;

		vector<string> land;

		for (int i = 0; i < n; i++)
		{
			cin >> s;

			land.push_back(s);
		}

		cin >> go;

		for (int i = 0; i < n && !found; i++)
		{
			for (int j = 0; j < m && !found; j++)
			{
				switch (land[i][j])
				{
				case 'N':
					orientation = 0;
					x = i;
					y = j;
					found = true;
					break;

				case 'S':
					orientation = 2;
					x = i;
					y = j;
					found = true;
					break;

				case 'L':
					orientation = 1;
					x = i;
					y = j;
					found = true;
					break;

				case 'O':
					orientation = 3;
					x = i;
					y = j;
					found = true;
					break;

				default :
					break;
				}
			}
		}

		for (int i = 0; i < intro; i++)
		{
			switch (go[i])
			{
			case 'D':
				orientation = (orientation + 1) % 4;
				break;

			case 'E':
				orientation = ((orientation - 1) < 0) ? 3 : orientation - 1;
				break;

			case 'F':

				switch (orientation)
				{
				case 0:
					if (x - 1 >= 0 && land[x - 1][y] != '#') x--;
					break;

				case 1:
					if (y + 1 < m && land[x][y + 1] != '#') y++;
					break;

				case 2:
					if (x + 1 < n && land[x + 1][y] != '#') x++;
					break;

				case 3:
					if (y - 1 >= 0 && land[x][y - 1] != '#') y--;
					break;
				}

				if (land[x][y] == '*')
				{
					how++;

					land[x][y] = '.';
				}
				break;
			}
		}

		cout << how << endl;
	}
}