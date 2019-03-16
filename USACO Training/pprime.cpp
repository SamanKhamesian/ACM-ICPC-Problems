#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

ifstream fin("pprime.in");
ofstream fout("pprime.out");

inline bool isPrime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0) return false;
    }

    return true;
}

int main()
{
    int l, h;
    
    fin >> l >> h;

    if ((int)log10(h) + 1 >= 1)
    {
        for (int i = 2; i <= 9; i++)
        {
            if (i >= l && i <= h && isPrime(i)) fout << i << endl;
        }
    }

    if ((int)log10(h) + 1 >= 2)
    {
        for (int i = 1; i <= 9; i += 2)
        {
            int temp = (i * 10) + i;

            if (temp >= l && temp <= h && isPrime(temp)) fout << temp << endl;
        }
    }

    if ((int)log10(h) + 1 >= 3)
    {
        for (int i = 1; i <= 9; i += 2)
        {
            for (int j = 0; j <= 9; ++j)
            {
                int temp = (i * 100) + (j * 10) + i;

                if (temp >= l && temp <= h && isPrime(temp)) fout << temp << endl;
            }
        }
    }

    if ((int)log10(h) + 1 >= 4)
    {
        for (int i = 1; i <= 9; i += 2)
        {
            for (int j = 0; j <= 9; ++j)
            {
                int temp = (i * 1000) + (j * 100) + (j * 10) + i;

                if (temp >= l && temp <= h && isPrime(temp)) fout << temp << endl;
            }
        }
    }

    if ((int)log10(h) + 1 >= 5)
    {
        for (int i = 1; i <= 9; i += 2)
        {
            for (int j = 0; j <= 9; ++j)
            {
                for (int k = 0; k <= 9; ++k)
                {
                    int temp = (i * 10000) + (j * 1000) + (k * 100) + (j * 10) + i;

                    if (temp >= l && temp <= h && isPrime(temp)) fout << temp << endl;
                }
            }
        }
    }

    if ((int)log10(h) + 1 >= 6)
    {
        for (int i = 1; i <= 9; i += 2)
        {
            for (int j = 0; j <= 9; ++j)
            {
                for (int k = 0; k <= 9; ++k)
                {
                    int temp = (i * 100000) + (j * 10000) + (k * 1000) + (k * 100) + (j * 10) + i;

                    if (temp >= l && temp <= h && isPrime(temp)) fout << temp << endl;
                }
            }
        }
    }

    if ((int)log10(h) + 1 >= 7)
    {
        for (int i = 1; i <= 9; i += 2)
        {
            for (int j = 0; j <= 9; ++j)
            {
                for (int k = 0; k <= 9; ++k)
                {
                    for (int m = 0; m <= 9; ++m)
                    {
                        int temp = (i * 1000000) + (j * 100000) + (k * 10000) + (m * 1000) + (k * 100) + (j * 10) + i;

                        if (temp >= l && temp <= h && isPrime(temp)) fout << temp << endl;
                    }
                }
            }
        }
    }

    if ((int)log10(h) + 1 >= 8)
    {
        for (int i = 1; i <= 9; i += 2)
        {
            for (int j = 0; j <= 9; ++j)
            {
                for (int k = 0; k <= 9; ++k)
                {
                    for (int m = 0; m <= 9; ++m)
                    {
                        int temp =
                                (i * 10000000) + (j * 1000000) + (k * 100000) + (m * 10000) + (m * 1000) + (k * 100) +
                                (j * 10) + i;

                        if (temp >= l && temp <= h && isPrime(temp)) fout << temp << endl;
                    }
                }
            }
        }
    }
}