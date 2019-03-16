#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b;

	cin >> a >> b;

	if (a.compare(b) == 0) cout << -1 << endl;

	else
	{
		if (a.size() > b.size()) cout << a.size() << endl;

		else cout << b.size() << endl;
	}
}