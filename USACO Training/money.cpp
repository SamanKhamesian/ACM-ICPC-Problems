#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

long long n, v;
vector<long long> coinValue;
vector<long long> saveSpace;

ifstream fin("money.in");
ofstream fout("money.out");

long long fasterWay()
{
    saveSpace[0] = 1;

    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j <= v ; j++)
        {
            if (j - coinValue[i] >= 0)
            {
                saveSpace[j] += saveSpace[j - coinValue[i]];
            }
        }
    }

    return saveSpace[v];
}

int main()
{
    fin >> n >> v;

    coinValue.resize(n);
    saveSpace.resize(v + 1, 0);

    for (long long i = 0; i < n; ++i)
    {
        fin >> coinValue[i];
    }

    sort(coinValue.begin(), coinValue.end());

    fout << fasterWay() << endl;
}