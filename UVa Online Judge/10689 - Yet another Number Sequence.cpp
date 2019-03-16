#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, m, f, n, t;

    cin >> t;

    while (t--)
    {
        cin >> a >> b >> n >> m;

        switch (m)
        {
            case 1:
                n = n % 60;
                break;
            case 2:
                n = n % 300;
                break;
            case 3:
                n = n % 1500;
                break;
            case 4:
                n = n % 15000;
                break;

            default:
                break;
        }

        m = (int)pow(10.0, m * 1.0);

        if (n == 0)
        {
            cout << (a % m) << endl;
        }

        else if (n == 1)
        {
            cout << (b % m) << endl;
        }

        else
        {
            for (int i = 2; i <= n; ++i)
            {
                f = ((a % m) + (b % m) % m);

                a = b;

                b = f;
            }

            cout << (f % m) << endl;
        }
    }
}