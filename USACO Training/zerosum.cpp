#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

int n;
vector< vector<char> > comb;

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

void bf(vector<char> a, int x)
{
    a.push_back(char(x + '0'));

    if (x == n)
    {
        comb.push_back(a);
    }

    else
    {
        a.push_back(' ');
        bf(a, x + 1);
        a.pop_back();
        a.push_back('+');
        bf(a, x + 1);
        a.pop_back();
        a.push_back('-');
        bf(a, x + 1);
        a.pop_back();
    }
}

int isOk(vector<char> x, int pos, int b)
{
    if (pos < 1)
    {
        return b;
    }

    else if (x[pos] == '+')
    {
        return isOk(x, pos - 2, x[pos - 1] - '0') + b;
    }

    else if (x[pos] ==  '-')
    {
        return isOk(x, pos - 2, x[pos - 1] - '0') - b;
    }

    else
    {
        stack<int> temp;
        temp.push(b);

        while (pos - 1 >= 0 && x[pos] == ' ')
        {
            temp.push(x[pos - 1] - '0');
            pos -= 2;
        }

        int z = 0;

        while (!temp.empty())
        {
            z = (z * 10) + temp.top();

            temp.pop();
        }

        return isOk(x, pos, z);
    }
}

void cal()
{
    for (int i = 0; i < comb.size(); ++i)
    {
        if (isOk(comb[i], (2 * n) - 3, n) == 0)
        {
            for (int j = 0; j < comb[i].size(); ++j)
            {
                fout << comb[i][j];
            }

            fout << endl;
        }
    }
}

int main()
{
    fin >> n;

    vector<char> a;

    bf(a, 1);

    cal();
}