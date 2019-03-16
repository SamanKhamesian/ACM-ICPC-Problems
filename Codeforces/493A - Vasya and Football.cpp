#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int fouls, time, number;
	char team, card;

	char away[30];
	char home[30];

	int a[100] = { 0 };
	int h[100] = { 0 };

	int ta[91] = { 0 };
	int th[91] = { 0 };

	cin >> home;
	cin >> away;

	cin >> fouls;

	for (int i = 0; i < fouls; i++)
	{
		cin >> time;
		cin >> team;
		cin >> number;
		cin >> card;

		if (team == 'h')
		{
			if (card == 'y' && h[number] == 0)
			{
				h[number]++;
			}

			else if (card == 'y' && h[number] == 1)
			{
				h[number]++;

				th[time] = number;
			}

			else if (card == 'r' && h[number] < 2)
			{
				h[number] += 2;

				th[time] = number;
			}
		}

		else
		{
			if (card == 'y' && a[number] == 0)
			{
				a[number]++;
			}

			else if (card == 'y' && a[number] == 1)
			{
				a[number]++;

				ta[time] = number;
			}

			else if (card == 'r' && a[number] < 2)
			{
				a[number] += 2;

				ta[time] = number;
			}
		}
	}

	for (int i = 0; i < 91; i++)
	{
		if (ta[i] != 0)
		{
			cout << away << " " << ta[i] << " " << i << endl;
		}

		if (th[i] != 0)
		{
			cout << home << " " << th[i] << " " << i << endl;
		}
	}
}