#include <iostream>

using namespace std;

typedef long long ll;

ll answer[41] = {0};

int main()
{
    answer[0] = 1;
    answer[1] = 1;
    answer[2] = 5;

    for (int i = 3; i < 41; ++i)
    {
        answer[i] = answer[i - 1] + 4*answer[i - 2] + 2*answer[i - 3];
    }

    int t;

    cin >> t;

    while (t--)
    {
        int n;

        cin >> n;

        cout << answer[n] << endl;
    }
}