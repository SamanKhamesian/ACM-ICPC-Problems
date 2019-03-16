#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

#define MAX 51

int cot = 1;
typedef long long ll;
typedef vector<ll> vll;

ll dp[MAX][MAX];

void cal()
{
    dp[0][0] = 0;
    dp[1][0] = dp[1][1] = 1;

    for (int i = 2; i < MAX; ++i)
    {
        dp[i][0] = dp[i][i] = 1;

        for (int j = 1; j < i; ++j)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
}

void print_ans(int n, string a, string b)
{
    cout << "Case " << cot++ << ": ";

    if (n == 1) cout << a << "+" << b << endl;

    else
    {
        cout << a << "^" << n << "+";

        for (int i = 1; i < n; ++i)
        {
            cout << dp[n][i] << "*" << a;

            if (n - i != 1) cout << "^" << n - i;

            cout << "*" << b;

            if (i != 1) cout << "^" << i;

            cout << "+";
        }

        cout << b << "^" << n << endl;
    }
}

int main()
{
    int t;

    cin >> t;

    cal();

    while(t--)
    {
        string s;

        cin >> s;

        string a = "", b = "";

        int n = 0;
        unsigned long inx = s.find('+');
        unsigned long iny = s.find('^');

        for (int i = 1; i < s.size(); ++i)
        {
            if (i < inx)
                a += s[i];

            else if (i > inx && i < iny && s[i] != ')')
                b += s[i];

            else if (i > iny)
            {
                n = (n * 10) + (int)((s[i] - '0'));
            }
        }

        print_ans(n, a, b);
    }
}
