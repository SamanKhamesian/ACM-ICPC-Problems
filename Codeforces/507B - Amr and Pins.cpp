#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int result;
	double x1, y1, x2, y2, r, d;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

	if (floor(d / (2 * r)) == (d / (2 * r)))
	{
		result = d / (r * 2);
		cout << result;
	}

	else
	{
		result = floor(d / (2 * r)) + 1;
		cout << result;
	}
}