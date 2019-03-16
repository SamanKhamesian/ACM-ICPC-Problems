#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("sprime.in");
ofstream fout("sprime.out");

int n;

int primes[] = {2, 3, 5, 7};

bool isPrime(int x)
{
    for (int i = 2; i * i <= x ; ++i)
    {
        if (x % i == 0) return false;
    }

    return true;
}

void solve(int x, int digit)
{
    if (digit == n) fout << x << endl;

    else
    {
        for (int i = 0; i <= 9 ; ++i)
        {
            int next = (x * 10) + i;

            if (isPrime(next)) solve(next, digit + 1);
        }
    }
}

int main()
{
    fin >> n;

    for (int i = 0; i < 4; ++i)
    {
        solve(primes[i], 1);
    }
}