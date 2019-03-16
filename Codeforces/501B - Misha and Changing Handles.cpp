#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int numbers, k = 0;

	char members[1000][2][21];

	cin >> numbers;

	for (int i = 0; i < numbers; i++, k++)
	{
		cin.get();

		cin.get(members[k][0], 21, ' ');

		cin.get();

		cin.get(members[k][1], 21, '\n');

		for (int j = 0; j < k; j++)
		{
			if (strcmp(members[k][0] , members[j][1]) == 0)
			{
				strcpy_s(members[j][1] , members[k][1]);

				k--;

				break;
			}
		}
	}

	cout << k << endl;

	for (int i = 0; i < k; i++)
	{
		cout << members[i][0] << " " << members[i][1] << endl;
	}
}