#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 10000000010

long long n, p = 0;

vector <long long> myList;

void merge(long long start, long long mid, long long end)
{
	long long a = 0, b = 0;

	vector <long long> temp;
	vector <long long> A;
	vector <long long> B;

	for (long long i = start; i < mid + 1; i++)
	{
		A.push_back(myList[i]);
	}

	A.push_back(INF);

	for (long long i = mid + 1; i <= end; i++)
	{
		B.push_back(myList[i]);
	}

	B.push_back(INF);

	for (long long i = start; i <= end; i++)
	{
		if (A[a] > B[b])
		{
			temp.push_back(B[b]);

			if (A[a] != INF && B[b] != INF)
			{
				p += ((A.size() - a) - 1);
			}

			b++;
		}

		else
		{
			temp.push_back(A[a]);

			a++;
		}
	}

	for (long long i = 0; i < temp.size(); i++)
	{
		myList[start + i] = temp[i];
	}
}

void inversion(long long start, long long end)
{
	if (start < end)
	{
		long long mid = ((start + end) / 2);

		inversion(start, mid);

		inversion(mid + 1, end);

		merge(start, mid, end);
	}
}

int main()
{
	cin >> n;

	p = 0;

	for (long long i = 0; i < n; i++)
	{
		long long x;

		cin >> x;

		myList.push_back(x);
	}

	inversion(0, n - 1);

	cout << p << endl;
}