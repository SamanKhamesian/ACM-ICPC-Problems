#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    ll n, c = 1;

    while (cin >> n && n != 0)
    {
        cout << "Case " << c++ << ": " << (ll)ceil((sqrt((long double)((8 * n) + 9)) + 3) / 2) << endl;
    }
}