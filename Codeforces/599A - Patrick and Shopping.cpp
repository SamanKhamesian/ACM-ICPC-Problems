#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int d1, d2, d3, a, b;

	cin >> d1 >> d2 >> d3;

	a = min(((d1 * 2) + (d2 * 2)), (d1 + d2 + d3));

	b = min(((d1 + d3) * 2), ((d2 + d3) * 2));

	cout << min(a, b) << endl;
}