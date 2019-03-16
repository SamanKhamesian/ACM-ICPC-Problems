#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159265

int main()
{
	int f = 0;

	float n, result, R, r, param;

	cin >> n >> R >> r;

	result = 180.0 / (asin(r / (R - r)) * 180.0 / PI);

	f = result;

	if ((n == 1 && r <= R && 2 * r >= R) || n <= f)
	{
		cout << "YES" << endl;
	}

	else
	{
		cout << "NO" << endl;
	}

	return 0;
}