#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define MAX 1000010

typedef long long ll;
typedef vector <ll> vll;
typedef vector <bool> vb;

vll numDiff(MAX, 0), mu(MAX, 0),M(MAX, 0);
vb isPrime(MAX, true), seqFree(MAX, true);

void calPrime()
{
    seqFree[0] = false;
    seqFree[1] = true;

    isPrime[0] = isPrime[1] = false;

    for (ll i = 2; i < MAX; ++i)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j < MAX; j += (i * i))
            {
                seqFree[j] = false;
            }

            for (ll k = i * i; k < MAX; k += i)
            {
                isPrime[k] = false;
            }

            for (ll l = i; l < MAX; l += i)
            {
                numDiff[l]++;
            }
        }
    }
}

void calAns()
{
    mu[1] = M[1] = 1;

    for (int i = 2; i < MAX; ++i)
    {
        mu[i] = (!seqFree[i]) ? 0 : (numDiff[i] % 2 == 0) ? 1 : -1;

        M[i] = M[i - 1] + mu[i];
    }
}
int main()
{
    calPrime();

    calAns();

    ll n;

    while (cin >> n && n != 0)
    {
        cout << setw(8) << n << setw(8) << mu[n] << setw(8) << M[n] << endl;
    }
}