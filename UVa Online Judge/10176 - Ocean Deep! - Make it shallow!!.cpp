#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

#define m 131071

bool isOK(string s)
{
    int makeIt = 0;
    bool ans = false;

    for (int i = (int)s.size() - 2; i >= 0 ; i--)
    {
        makeIt = (((makeIt % m) * 2) % m);

        if (s[i] == '1') makeIt = (((makeIt % m) + 1) % m);
    }

    if (makeIt == 0) ans = true;

    return ans;
}

int main()
{
    string s;

    while (cin >> s)
    {
        while (s[s.size() - 1] != '#')
        {
            string temp;

            cin >> temp;

            s += temp;
        }

        isOK(s) ? cout << "YES" << endl : cout << "NO" << endl;
    }
}