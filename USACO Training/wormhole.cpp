#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#define MAX 13

ifstream fin("wormhole.in");
ofstream fout("wormhole.out");

int n, x[MAX], y[MAX], partner[MAX], r[MAX];

bool isCycle()
{
    for (int i = 1; i <= n ; ++i)
    {
        int pos = i;

        for (int j = 0; j < n; ++j)
        {
            pos = r[partner[pos]];
        }

        if (pos != 0) return true;
    }

    return false;
}

int solve()
{
    int i, total = 0;

    for (i = 1; i <= n ; i++)
    {
        if (partner[i] == 0) break;
    }

    if (i > n)
    {
        if (isCycle()) return 1;

        else return 0;
    }

    for (int j = i + 1; j <= n ; ++j)
    {
        if (partner[j] == 0)
        {
            partner[i] = j;
            partner[j] = i;

            total += solve();

            partner[i] = partner[j] = 0;
        }
    }

    return total;
}

int main()
{
    fin >> n;

    for (int i = 1; i <= n; ++i)
    {
        fin >> x[i] >> y[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n ; ++j)
        {
            if (x[j] > x[i] && y[i] == y[j])
            {
                if (r[i] == 0 || x[j] - x[i] < x[r[i]] - x[i])
                {
                    r[i] = j;
                }
            }
        }
    }

    fout << solve() << endl;
}