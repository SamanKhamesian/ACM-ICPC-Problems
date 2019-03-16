#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

#define MAX 255

ifstream fin("ariprog.in");
ofstream fout("ariprog.out");

int n, m, a = 0, b = 1;

bool sqr[MAX * MAX * 2 + 1];

int main()
{
    fin >> n >> m;

    for (int i = 0; i <= m; ++i)
    {
        for (int j = i; j <= m; ++j)
        {
            sqr[(i * i) + (j * j)] = true;
        }
    }

    int how = 0;
    int maximum = m * m * 2;

    while ((n - 1) * b <= maximum)
    {
        for (a = 0; (a + ((n - 1) * b)) <= maximum ; a++)
        {
            bool ok = true;

            for (int i = a; i <= (a + ((n - 1) * b)) && ok; i += b)
            {
                ok = sqr[i] & ok;
            }

            if (ok)
            {
                fout << a << " " << b << endl;
                how++;
            }
        }

        b++;
    }

    if (how == 0) fout << "NONE" << endl;
}