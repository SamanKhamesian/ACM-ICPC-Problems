#include <iostream>

using namespace std;

int main()
{
	int n, m, r = 0,re = 0, sum = 0;

	cin >> n >> m;

	sum += n;

	while (n >= m)
	{
		while (n > 0)
		{
			r += n % m;

			n /= m;

			sum += n;
		}

		n = r;

		r = 0;
	}
	
	cout << sum << endl;
}