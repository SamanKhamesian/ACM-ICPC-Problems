#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
	bool ok = true;

	string x, z;

	cin >> x >> z;

	for (int i = 0; i < x.size() && ok; i++)
	{
		if (x[i] < z[i]) ok = false;
	}

	if (ok) cout << z << endl;

	else cout << -1 << endl;
}