#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define MAX 20000001

typedef long long ll;
typedef vector<ll> vll;
typedef vector<bool> vb;

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

    swap(primes[1], primes[2]);
}

int main()
{
    ll n, ans;

    findPrime();

    while (cin >> n && n != 0)
    {
        ans = 1;

        ll count_2 = 0, count_5 = 0;

        for (ll i = 2; i <= n; i *= 2)
        {
            count_2++;
        }

        for (ll j = 5; j <= n; j *= 5)
        {
            count_5++;
        }

        for (ll k = 0; k < (count_2 - count_5) ; ++k)
        {
            ans = ((ans * 2) % 10);
        }

        for (ll l = 2; l < primes.size(); ++l)
        {
            ll p = primes[l];

            if (p > n) break;

            else
            {
                for (ll i = p; i <= n ; i *= p)
                {
                    ans = ((ans * p) % 10);
                }
            }
        }

        cout << ans << endl;
    }
}

