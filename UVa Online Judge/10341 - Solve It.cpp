#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define EPS 0.00000001

double p, q, r, s, t, u;

double function(double x)
{
	double ans = (p * exp(-x)) + (q * sin(x)) + (r * cos(x)) + (s * tan(x)) + (t * x * x) + u;

	return ans;
}

double binarySearch()
{
	double low = 0.0, high = 1.0, mid;

	while (low + EPS < high)
	{
		mid = (low + high) / 2.0;

		double f0, f1;

		f0 = function(low);

		f1 = function(mid);

		if (f0 * f1 <= 0) high = mid;

		else low = mid;
	}

	return (low + high) / 2.0;
}

int main()
{
	while (cin >> p >> q >> r >> s >> t >> u)
	{
		double f0, f1;

		f0 = function(0.0);

		f1 = function(1.0);

		if (f0 * f1 > 0) cout << "No solution" << endl;

		else printf("%.4lf\n", binarySearch());
	}
}