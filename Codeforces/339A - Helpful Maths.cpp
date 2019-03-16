#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int size = 0;

	char problem[100];

	cin.getline(problem, 100, '\n');

	size = (strlen(problem) + 1) / 2;

	int* solution = new int[size];

	for (int i = 0; i < strlen(problem); i += 2)
	{
		solution[i / 2] = (int)problem[i] - 48;
	}

	sort(solution, solution + size);

	for (int i = 0; i < strlen(problem); i += 2)
	{
		problem[i] = (char)solution[i / 2] + 48;
	}

	cout << problem;
}