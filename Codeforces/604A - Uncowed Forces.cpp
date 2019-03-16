#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

double M(int x, int m, int w)
{
	double a = (0.3 * x);

	double b = (((1.0 - (m / 250.0)) * x) - (50.0 * w));

	if (a > b)
	{
		return round(a);
	}

	else
	{
		return round(b);
	}
}

int main()
{
	int h1 = 0, h2 = 0, score = 0;

	int m[5] = { 0, 0, 0, 0, 0 };
	int w[5] = { 0, 0, 0, 0, 0 };

	int x[5] = { 500, 1000, 1500, 2000, 2500 };

	for (int i = 0; i < 5; i++)
	{
		cin >> m[i];
	}

	for (int i = 0; i < 5; i++)
	{
		cin >> w[i];
	}

	cin >> h1 >> h2;

	for (int i = 0; i < 5; i++)
	{
		score += (M(x[i], m[i], w[i]));
	}
	
	score += (h1 * 100);

	score -= (h2 * 50);

	cout << score << endl;
}