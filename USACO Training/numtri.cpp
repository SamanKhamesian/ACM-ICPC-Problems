#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <fstream>

using namespace std;

#define MAX 1005

int dp[MAX][MAX];

ifstream fin("numtri.in");
ofstream fout("numtri.out");

int main()
{
    int n;

    fin >> n;

    for (int i = 1; i <= n ; ++i)
    {
        for (int j = 1; j <= i ; ++j)
        {
            fin >> dp[i][j];
        }
    }

    for (int k = 1; k <= n ; ++k)
    {
        for (int p = 1; p <= k ; ++p)
        {
            dp[k][p] += max(dp[k - 1][p - 1], dp[k - 1][p]);
        }
    }

    int ans = 0;

    for (int l = 1; l <= n ; ++l)
    {
        ans = max(ans, dp[n][l]);
    }

    fout << ans << endl;
}