#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

vector<int> num;
vector<int> ans;

ifstream fin("sort3.in");
ofstream fout("sort3.out");

int main()
{
    int n, t;
    fin >> n;

    num.resize((unsigned) n);

    for (int i = 0; i < n; ++i)
    {
        fin >> num[i];
    }

    t = 0;
    ans = num;

    sort(ans.begin(), ans.end());

    for (int i = 0; i < n; ++i)
    {
        if (ans[i] != num[i])
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (ans[j] == num[i] && ans[i] == num[j])
                {
                    t++;
                    swap(num[i], num[j]);
                }
            }
        }
    }

    for (int k = 0; k < n; ++k)
    {
        if (ans[k] != num[k] && num[k] == 1)
        {
            t += 2;
        }
    }

    fout << t << endl;
}