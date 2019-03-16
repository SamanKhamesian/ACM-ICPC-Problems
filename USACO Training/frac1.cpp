#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <map>
#include <queue>

using namespace std;

ifstream fin("frac1.in");
ofstream fout("frac1.out");

int gcd(int x, int y)
{
    if (x == 0) return y;

    else return gcd(y % x, x);
}

vector< pair< float, pair<int, int> > > frac;

int main()
{
    int n;

    fin >> n;

    frac.push_back({0.0, {0 , 1}});
    frac.push_back({1.0 , {1, 1}});

    for (int i = 1; i < n; ++i)
    {
        for (int j = i + 1; j <= n ; ++j)
        {
            if (gcd(i, j) == 1)
            {
                frac.push_back({ (float)i / j , {i, j}});
            }
        }
    }

    sort(frac.begin(), frac.end());

    for (int k = 0; k < frac.size(); ++k)
    {
        fout << frac[k].second.first << "/" << frac[k].second.second << endl;
    }
}