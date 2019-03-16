#include <iostream>
using namespace std;
int main()
{
    int cou = 1, t;
    while (cin >> t && t != 0)
        cout << "Case " << cou++ << ": " << t / 2 << endl;
}