#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("crypt1.in");
ofstream fout("crypt1.out");

vector<int> digit;

bool checkDigit(int x)
{
    bool ok = true;

    while (x != 0)
    {
        vector<int>::iterator it = find(digit.begin(), digit.end(), x % 10);

        if (it == digit.end())
        {
            ok = false;

            break;
        }

        x /= 10;
    }

    return ok;
}

int howDigit(int x)
{
    return (int)log10(x * 1.0);
}

int main()
{
    int n, how = 0;

    fin >> n;

    for (int i = 0; i < n; ++i)
    {
        int x;

        fin >> x;

        digit.push_back(x);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                for (int l = 0; l < n; ++l)
                {
                    for (int m = 0; m < n; ++m)
                    {
                        int num = (digit[i] * 100) + (digit[j] * 10) + digit[k];

                        int partial_1 = 0;
                        int partial_2 = 0;

                        partial_1 = num * digit[m];
                        partial_2 = num * digit[l] * 10;

                        int ans = partial_1 + partial_2;

                        if (howDigit(ans) == 3 && howDigit(partial_1) == 2 && howDigit(partial_2 / 10) == 2)
                        {
                            if (checkDigit(ans) && checkDigit(partial_1) && checkDigit(partial_2 / 10))
                            {
                                how++;
                            }
                        }
                    }
                }
            }
        }
    }

    fout << how << endl;
}