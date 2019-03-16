#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 1000001

vector <int> numDiff(MAX, 0);

void numDif()
{
    for (int i = 2; i < MAX ; ++i)
    {
        if (numDiff[i] == 0)
        {
            for (int j = i; j < MAX; j += i)
            {
                numDiff[j]++;
            }
        }
    }
}

int main()
{
    numDif();

    int n;

    while (cin >> n && n != 0)
    {
        cout << n << " : " << numDiff[n] << endl;
    }
}