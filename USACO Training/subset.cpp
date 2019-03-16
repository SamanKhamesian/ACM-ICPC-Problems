#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;

ll n, s;
ll dp[500][50];
ifstream fin("subset.in");
ofstream fout("subset.out");

ll count(ll n, ll k)
{
    if (n < 0 || k < 0) return 0;

    else if (n == 0 && k == 0) return 1;

    else if (dp[n][k] != -1) return dp[n][k];

    else return dp[n][k] = count(n, k - 1) + count(n - k, k - 1);
}

int main()
{
    fin >> n;

    memset(dp, -1, sizeof(dp));

    s = ((n) * (n + 1)) / 2;

    if (s % 2) fout << 0 << endl;

    else fout << count(s / 2, n) / 2 << endl;
}