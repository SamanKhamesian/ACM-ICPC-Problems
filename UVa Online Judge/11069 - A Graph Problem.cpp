#include <iostream>

using namespace std;

typedef long long ll;

ll n, a[77], b[77], c[77];

int main()
{
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 2;

    b[0] = 0;
    b[1] = 1;
    c[0] = c[1] = 0;

    b[2] = b[3] = 1;
    c[2] = c[3] = 1;

    for (int i = 4; i < 77; ++i)
    {
        a[i] = b[i - 2] + (2 * c[i - 2]) + b[i - 4];

        b[i] = c[i - 2] + b[i - 2];
        c[i] = c[i - 2] + b[i - 4];
    }

    while (cin >> n)
    {
        cout << a[n] << endl;
    }
}