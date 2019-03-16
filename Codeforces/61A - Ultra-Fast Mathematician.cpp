#include <iostream>
#include <string>

using namespace std;

int main()
{
	string num1, num2;

	cin >> num1;

	cin >> num2;

	for (int i = 0; i < num1.size(); i++)
	{
		int x, y;

		x = (int)(num1[i] - '0');

		y = (int)(num2[i] - '0');

		cout << ((x + y) % 2);
	}
}