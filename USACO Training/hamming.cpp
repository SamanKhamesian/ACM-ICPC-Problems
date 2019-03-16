#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int d, n, b;
vector<int> ans;

ifstream fin("hamming.in");
ofstream fout("hamming.out");

bool hammingDistance(int x, int y)
{
    int diff = 0;

    while (x != 0 || y != 0)
    {
        if (((x % 2) ^ (y % 2)))
        {
            diff++;
        }

        x /= 2;
        y /= 2;
    }

    return diff >= d;
}

bool hammingDistanceIsOK(int x)
{
    for (int i = 0; i < ans.size(); ++i)
    {
        if (!hammingDistance(x, ans[i]))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    fin >> n >> b >> d;

    ans.push_back(0);

    for (int i = 1; i < (int)pow(2.0, b * 1.0) && ans.size() < n; ++i)
    {
        if (hammingDistanceIsOK(i))
        {
            ans.push_back(i);
        }
    }

    int j, i = 0;

    while (i < ans.size())
    {
        fout << ans[i];

        i++;

        for (j = i; j < ans.size() && i + 9 > j; ++j)
        {
            fout << " " << ans[j];
        }

        i = j;

        fout << endl;
    }
}
