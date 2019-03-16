#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

ofstream fout ("barn1.out");
ifstream fin ("barn1.in");

int m, c, s, ans, total, pre, now, x, temp;

int main()
{
    fin >> m >> s >> c;

    vector<int> num;
    vector<int> dif;
    ans = 99999999;

    for (int i = 0; i < c; ++i)
    {
        fin >> x;

        num.push_back(x);
    }

    sort(num.begin(), num.end());

    pre = num[0];
    temp = total = 0;
    for (int j = 1; j < c; ++j)
    {
        total += (num[j] - pre);

        dif.push_back(num[j] - pre);

        pre = num[j];
    }

    sort(dif.begin(), dif.end());
    reverse(dif.begin(), dif.end());

    if (m == 1)
    {
        fout << num[c - 1] - num[0] + 1 << endl;
    }

    else
    {
        for (int k = 1; k < min(m, c); ++k)
        {
            temp += dif[k - 1];

            ans = min(ans, total - temp + k + 1);
        }

        fout << ans << endl;
    }

    return 0;
}