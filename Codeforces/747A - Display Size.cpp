#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n, i;

	cin >> n;

	int temp = (int)sqrt(n);

	for (i = temp; (n % i); i--);

	cout << i << " " << n / i << endl;
}