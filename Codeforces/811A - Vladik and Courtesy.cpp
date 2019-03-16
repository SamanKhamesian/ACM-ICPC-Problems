#include <iostream>

using namespace std;

#define MAX 1000000009

int main()
{
    int a,b;

    cin >> a >> b;

    for (int i = 1; i < MAX; ++i)
    {
        if (i % 2 == 1)
        {
            if (a < i)
            {
                cout << "Vladik" << endl;

                break;
            }

            else a -= i;
        }

        else
        {
            if (b < i)
            {
                cout << "Valera" << endl;

                break;
            }

            else b -= i;
        }

    }
}