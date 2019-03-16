#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	double firstDigit[10] = { 0 };

	double k, n, p = 2;

	cin >> k >> n;

	for (int i = 0; i < n; i++)
	{
		int x;

		cin >> x;

		firstDigit[x / 1000]++;
	}

	for (int i = 0; i < 10; i++)
	{
		p += ceil(firstDigit[i] / k);
	}

	cout << p << endl;
}