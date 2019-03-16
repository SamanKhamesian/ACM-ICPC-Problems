#include <iostream>

using namespace std;

int main()
{
	bool x;
	int n, counter = 0, max = -1000, ones = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x;

		if (x)
		{
			counter--;
			ones++;
		}
		else
			counter++;

		if (counter > max)
		{
			max = counter;
		}

		if (counter < 0)
		{
			counter = 0;
		}
	}
		
	cout << ones + max << endl;
	
}