#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

ofstream fout ("skidesign.out");
ifstream fin ("skidesign.in");

int main()
{
    long long n;
    fin >> n;

    long long bound[84] = {0};

    for (long long i = 0; i < n; ++i)
    {
        long long hill;

        fin >> hill;

        for (long long j = 0; j < 84; ++j)
        {
            if (hill < j)
            {
                bound[j] += ((j - hill)*(j - hill));
            }

            else if (hill > j + 17)
            {
                bound[j] += ((hill - (j + 17))*(hill - (j + 17)));
            }
        }
    }

    long long ans = bound[0];

    for (int k = 1; k <= 83; ++k)
    {
        ans = min(ans, bound[k]);
    }

    fout << ans << endl;
}