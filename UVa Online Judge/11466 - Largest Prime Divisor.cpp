#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX 20000001

typedef long long ll;
typedef vector<ll> vll;
typedef vector<bool> vb;

ll n;
vll primes;
vb isPrime(MAX, true);

void findPrime()
{
    isPrime[0] = isPrime[1] = false;

    for (ll i = 2; i < MAX; ++i)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j < MAX; j += i)
            {
                isPrime[j] = false;
            }

            primes.push_back(i);
        }
    }
}

ll findLargestFactor()
{
    int count = 0;
    ll largestFactor = n, primes_index = 0, pf = primes[primes_index];

    while (pf * pf <= n)
    {
        largestFactor = pf;

        if (n % pf == 0)
        {
            count++;

            while (n % pf == 0)
            {
                n /= pf;
            }
        }

        pf = primes[++primes_index];
    }

    if (n != 1)
    {
        count++;
        largestFactor = n;
    }

    return (count == 1) ? (ll)-1 : largestFactor;
}

int main()
{
    findPrime();

    while (cin >> n, n != 0)
    {
        n = abs(n);

        if (n == 1) cout << -1 << endl;

        else cout << findLargestFactor() << endl;
    }
}