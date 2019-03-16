#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int p, m, c, k, r, v;

	cin >> p >> m >> c >> k >> r >> v;

	cout << min(p / k, min(m / r, c / v)) << endl;
}