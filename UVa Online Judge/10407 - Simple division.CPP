#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <climits>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;

    else return gcd(b, a % b);
}

int main()
{
    int a;

    while (cin >> a, a != 0)
    {
        int minNum = INT_MAX, ans = 0;

        vector<int> num;

        num.push_back(a);

        if (a > 0 && a < minNum) minNum = a;

        while (cin >> a, a != 0)
        {
            num.push_back(a);

            if (a > 0 && a < minNum) minNum = a;
        }

        for (int i = 0; i < num.size(); ++i)
        {
            num[i] -= minNum;

            ans = gcd(max(ans, abs(num[i])), min(ans, abs(num[i])));
        }

        cout << ans << endl;
    }

    return 0;
}