#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 2000002

typedef long long ll;
typedef vector <bool> vb;

int phi[MAX];

ll dpMAX[MAX] = {0};
ll delPhi[MAX] = {0};
vb isPrime(MAX, true);

void initialize()
{
    isPrime[0] = isPrime[1] =  false;

    for (int i = 0; i < MAX; ++i)
    {
        phi[i] = i;
    }
}

void calPhi()
{
    for (int i = 2; i < MAX; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i; j < MAX; j += i)
            {
                phi[j] -= (phi[j] / i);

                isPrime[j] = false;
            }

            isPrime[i] = true;
        }
    }
}

void calDelPhi()
{
    delPhi[2] = phi[2];
    delPhi[3] = phi[3];

    dpMAX[2] = delPhi[2];
    dpMAX[3] = dpMAX[2] + delPhi[3];

    for (int i = 4; i < MAX; ++i)
    {
        delPhi[i] = delPhi[phi[i]] + 1;
        dpMAX[i] = dpMAX[i - 1] + delPhi[i];
    }
}

int main()
{
    initialize();

    calPhi();

    calDelPhi();

    int n;

    cin >> n;

    while (n--)
    {
        int l, h;

        cin >> l >> h;

        cout << dpMAX[h] - dpMAX[l - 1] << endl;
    }
}