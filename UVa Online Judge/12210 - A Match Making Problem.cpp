#include <iostream>
#include <algorithm>

using namespace std;

int b, s, how, ans, t = 1;

int main()
{
	while (cin >> b >> s, b != 0 || s != 0)
	{
		int* bachelor = new int[b];
		int* spinster = new int[s];

		for (int i = 0; i < b; i++) cin >> bachelor[i];
		for (int i = 0; i < s; i++) cin >> spinster[i];

		sort(bachelor, bachelor + b);

		cout << "Case " << t++ << ": ";

		if (b > s) cout << b - s << " " << bachelor[0] << endl;

		else cout << 0 << endl;
	}
}
