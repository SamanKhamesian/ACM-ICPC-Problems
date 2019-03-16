#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define MAX 1000001
typedef long long ll;
typedef vector <ll> vll;

vll dp(MAX);

void cal()
{
    dp[3] = 0;

    for (int i = 4; i < MAX; ++i)
    {
        dp[i] = dp[i - 1];

        ll temp = 0;

        if (i % 2 == 0)
        {
            temp = (ll)((((i - 4) / 2) + 1) * (((i - 4) / 2) + 1));

            dp[i] += temp;
        }

        else
        {
            temp = (ll)(((i - 1) * (i - 3)) / 4);

            dp[i] += temp;
        }
    }
}

int main()
{
    int n;

    cal();

    while (cin >> n && n >= 3)
    {
        cout << dp[n] << endl;
    }
}