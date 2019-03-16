#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

ofstream fout("a.out");

bool sr = false;

char robot;
int t, n, m, x, y;

vector <string> graph;

int dirX[] = { -1, 0, 1, 0 };
int dirY[] = { 0, 1, 0, -1 };

char dir[] = { 'N', 'E', 'S', 'W' };

bool safe(int a, int b)
{
	if (a < n && b < m && a >= 0 && b >= 0 && graph[a][b] == ' ') return true;

	else return false;
}

void move(char command)
{
	switch (command)
	{
		case 'R':
		{
					robot = (robot + 1) % 4;
					break;
		}

		case 'L':
		{
					robot = ((robot - 1) + 4) % 4;
					break;
		}

		case 'F':
		{
					if (safe(x + dirX[robot], y + dirY[robot]))
					{
						x += dirX[robot];
						y += dirY[robot];
					}

					break;
		}

		default:
			break;
	}
}

int main()
{
	cin >> t;

	while (t--)
	{
		robot = 0;

		graph.clear();

		cin >> n >> m;

		string a;

		getline(cin, a);

		for (int i = 0; i < n; i++)
		{
			string a;

			getline(cin, a);

			graph.push_back(a);
		}

		bool ok = false;

		string command;

		cin >> x >> y;

		x--;

		y--;

		getline(cin, command);

		while (true)
		{
			cin >> command;

			for (int i = 0; i < command.size(); i++)
			{
				if (command[i] != 'Q') move(command[i]);

				else 
				{
					ok = true;

					break;
				}
			}

			if (ok)
			{
				if (sr) cout << endl;

				else sr = true;

				cout << x + 1 << " " << y + 1 << " " << dir[robot] << endl;

				ok = false;

				break;
			}
		}
	}
}