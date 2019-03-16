#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int num1, num2;

	int n, moves = 0;

	cin >> n;

	char* start = new char[n];

	char* end = new char[n];

	cin >> start;

	cin >> end;

	for (int i = 0; i < n; i++)
	{
		num1 = (int)start[i] - 48;

		num2 = (int)end[i] - 48;

		moves += min(abs(num1 - num2), (10 - abs(num1 - num2)));
	}

	cout << moves;
}