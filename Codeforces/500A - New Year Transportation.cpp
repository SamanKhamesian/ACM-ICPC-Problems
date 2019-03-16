#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	long n, t;
	int a[30000];
	cin >> n >> t;

	for (int j = 1; j < n; j++)
	{
		cin >> a[j];
	}
	
	for (int i = 1; i < n; i += a[i])
	{
		if (i + a[i] == t)
		{
			cout<<"YES";
			exit(0);
		}
	}

	cout<<"NO";
}