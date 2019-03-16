#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("combo.in");
ofstream fout("combo.out");

int pass[3], john[3], master[3];

int main()
{
    int n, ans = 0;

    fin >> n;

    fin >> john[0] >> john[1] >> john[2];
    fin >> master[0] >> master[1] >> master[2];

    for (int i = 1; i <= n ; ++i)
    {
        for (int j = 1; j <= n ; ++j)
        {
            for (int k = 1; k <= n ; ++k)
            {
                bool ok = false;

                pass[0] = i; pass[1] = j; pass[2] = k;

                for (int l = 0; l < 3; ++l)
                {
                    if (!(abs(pass[l] - john[l]) <= 2 || abs(pass[l] - john[l]) >= n - 2))
                    {
                        ok = true;
                    }
                }

                if (!ok) ans++;

                else
                {
                    for (int l = 0; l < 3; ++l)
                    {
                        if (!(abs(pass[l] - master[l]) <= 2 || abs(pass[l] - master[l]) >= n - 2))
                        {
                            ok = false;
                        }
                    }
                }

                if (ok) ans++;
            }
        }
    }

    fout << ans << endl;
}