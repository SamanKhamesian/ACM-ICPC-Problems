#include <iostream>

using namespace std;

int main()
{
	int n, counter = 0, domino, previous = 2;

	cin >> n;

	for (int i = 0; i <n ; i++)
	{
		cin >> domino;

		if (domino != previous)
		{
			counter++;
		}

		previous = domino;
	}

	cout << counter;

}