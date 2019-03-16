#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int main()
{
	bool first = false;

	int c, s;
	int counter = 1;

	while (cin >> c >> s)
	{
		double avg = 0, imp = 0;

		double b[25][2];
		double* a = new double[2 * c];

		for (int i = 0; i < 25; i++)
		{
			b[i][0] = b[i][1] = -1;
		}

		for (int i = 0; i < c * 2; i++)
		{
			a[i] = 0;
		}

		for (int i = 0; i < s; i++)
		{
			cin >> a[i];

			avg += a[i];

			b[i][0] = a[i];
		}

		avg /= c;

		sort(a, a + (2 * c));

		vector< pair < double, double > > box;
		
		for (int i = 0; i < c; i++)
		{
			box.push_back(make_pair(a[i], a[(2 * c) - i - 1]));

			imp += (fabs(a[i] + a[(2 * c) - i - 1] - avg));
		}

		int wh = 0;

		for (int i = 0; i < 2 * c; i++)
		{
			double x = b[i][0];

			for (int j = 0; j < box.size(); j++)
			{
				double first = 0, second = 0;

				first = box[j].first;

				second = box[j].second;

				if (x == first || x == second)
				{
					box.erase(box.begin() + j);

					for (int k = 0; k < 2 * c; k++)
					{
						if (b[k][0] == first && b[k][1] == -1)
						{
							b[k][1] = wh;

							break;
						}
					}

					for (int k = 0; k < 2 * c; k++)
					{
						if (b[k][0] == second && b[k][1] == -1)
						{
							b[k][1] = wh;

							break;
						}
					}

					wh++;

					break;
				}
			}
		}

		cout << "Set #" << counter << endl;

		for (int i = 0; i < c; i++)
		{
			printf("%2d:", i);

			for (int j = 0; j < 2 * c; j++)
			{
				if (b[j][1] == i)
				{
					cout << " " << b[j][0];
				}
			}

			cout << endl;
		}

		printf("IMBALANCE = %.5lf\n\n", imp);

		counter++;
	}
}