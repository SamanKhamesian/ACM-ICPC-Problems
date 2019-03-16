#include <iostream>

using namespace std;

int main()
{
    int p, s;

    while (cin >> s >> p)
    {
        int time = (p - s);

        if (time <= 0) cout << 0 << endl;

        else if (time > 0 && time < 300) cout << 1 << endl;

        else if (time >= 300 && time < 900) cout << 2 << endl;

        else if (time >= 900 && time < 1800) cout << 3 << endl;

        else cout << 4 << endl;
    }
}