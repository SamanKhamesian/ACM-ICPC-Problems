#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int n, d, r;

int main()
{
	while (cin >> n >> d >> r, n != 0 || d != 0 || r != 0)
	{
		int sum = 0;

		int* morning = new int[n];
		int* evening = new int[n];

		for (int i = 0; i < n; i++) cin >> morning[i];
		for (int i = 0; i < n; i++) cin >> evening[i];

		sort(morning, morning + n);
		sort(evening, evening + n);

		for (int i = 0; i < n; i++) sum += (morning[i] + evening[n - i - 1] > d) ? ((morning[i] + evening[n - i - 1] - d) * r) : 0;

		cout << sum << endl;
	}
}