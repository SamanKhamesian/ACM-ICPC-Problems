#include <iostream>
#include <algorithm>
using namespace std;

void bubblesort(int[], int);

int main()
{
	int n = 0, k = 0, maximum = 0, counter = 0;

	cin >> n >> k;

	int* a = new int[n];
	int* b = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}

	sort(a, a + n);

	for (int i = 0; i < n; i++)
	{
		if (maximum + a[i] <= k)
		{
			maximum += a[i];
			counter++;
		}
	}

	int* c = new int[counter];

	for (int i = 0; i < counter; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] == b[j])
			{
				c[i] = j + 1;
				b[j] = 0;
				break;
			}
		}
	}

	cout << counter << endl;

	for (int i = 0; i < counter; i++)
	{
		cout << c[i] << " ";
	}

}

