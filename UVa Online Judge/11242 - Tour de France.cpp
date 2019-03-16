#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	int f, r;

	cin >> f;

	while (f != 0)
	{
		cin >> r;

		double m = 0.0;
		vector <double> nums;
		double* fc = new double[f];
		double* rc = new double[r];

		for (int i = 0; i < f; i++)
		{
			cin >> fc[i];
		}

		for (int i = 0; i < r; i++)
		{
			cin >> rc[i];
		}

		for (int i = 0; i < f; i++)
		{
			for (int j = 0; j < r; j++)
			{
				nums.push_back(rc[j] / fc[i]);
			}
		}

		sort(nums.begin(), nums.end());

		for (int i = 1; i < nums.size(); i++)
		{
			m = max(m, nums[i] / nums[i - 1]);
		}

		printf("%.2f\n", m);

		cin >> f;
	}
}

