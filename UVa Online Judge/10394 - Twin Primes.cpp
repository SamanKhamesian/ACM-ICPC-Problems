#include <iostream>
#include <vector>

using namespace std;

#define LMT 18409202
#define MAX 100001

long long n, p = 3;
vector<bool> isPrime;
vector<pair <long long, long long >> ans;

void setPrime()
{
    ans.push_back({0, 0});
    isPrime.resize(LMT, true);

    isPrime[0] = isPrime[1] = false;

    for (long long i = 3; ans.size() < MAX; i += 2)
    {
        if (isPrime[i])
        {
            if(i - p == 2)
            {
                ans.push_back({p, i});
            }

            for (long long j = i * i; j < LMT; j += i)
            {
                isPrime[j] = false;
            }

            p = i;
        }
    }
}

int main()
{
    setPrime();

    while (cin >> n)
    {
        printf("(%lld, %lld)\n", ans[n].first, ans[n].second);
    }
}