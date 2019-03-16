#include <iostream>

using namespace std;

int main()
{
	int a1, a2, a3, b1, b2, b3, temp;

	cin >> b1 >> a1 >> b2 >> a2 >> b3 >> a3;

	for (int i = 0; i < 2; i++)
	{
		if (a1 >= a2 && b1 >= b2)
		{
			if (a3 <= a1 - a2 && b1 >= b3)
			{
				cout << "YES" << endl;

				exit(0);
			}

			else if (b3 <= a1 - a2 && b1 >= a3)
			{
				cout << "YES" << endl;

				exit(0);
			}

			else if (a1 >= a3 && b3 <= b1 - b2)
			{
				cout << "YES" << endl;

				exit(0);
			}

			else if (a1 >= b3 && a3 <= b1 - b2)
			{
				cout << "YES" << endl;

				exit(0);
			}

			else
			{
				temp = a2;

				a2 = b2;

				b2 = temp;
			}
		}

		else
		{
			temp = a2;

			a2 = b2;

			b2 = temp;
		}
	}

	cout << "NO" << endl;
}