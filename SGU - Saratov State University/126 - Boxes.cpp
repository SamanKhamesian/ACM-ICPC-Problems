#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int A, int B)
{
	A = A % B;

	if (A == 0) return B;

	else return gcd(B, A);
}

int main()
{
	long long a, b, one = 0, how = 0;

	cin >> a >> b;

	long long A = max(a, b);
	long long B = min(a, b);

	if (B == 0)
	{
		cout << 0 << endl;

		return 0;
	}

	else
	{
		long long G = gcd(A, B);

		long long T = ((A + B) / G);

		for (int i = 0; i < 63; i++)
		{
			one += (T & 1);

			T /= 2;
		}

		if (one == 1)
		{
			while (A != B)
			{
				A -= B;

				B *= 2;

				how++;

				long long temp = max(A, B);

				B = min(A, B);

				A = temp;
			}

			cout << how + 1 << endl;
		}

		else
		{
			cout << -1 << endl;
		}
	}
 }