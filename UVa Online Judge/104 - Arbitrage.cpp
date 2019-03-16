#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int n;
vector<int> ans;
vector<bool> visited;
float dist[25][25];

void initialize()
{
    ans.resize(n + 2);
    
    visited.clear();
    visited.resize((unsigned)n + 1, false);
    
    memset(dist, 0, sizeof dist);
}

void backtrack(int start, int curr, float money)
{
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;

            if (money * dist[curr][i] * dist[i][start] > 1.01)
            {
                vector<int> temp;

                temp.push_back(start);

                for (int j = 1; j <= n; ++j)
                {
                    if (visited[j] && j != start) temp.push_back(j);
                }

                temp.push_back(start);

                if (temp.size() < ans.size())
                {
                    ans = temp;
                }
            }

            backtrack(start, i, money * dist[curr][i]);
            visited[i] = false;
        }
    }
}

int main()
{
    while (cin >> n)
    {
        initialize();

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i == j) continue;

                cin >> dist[i][j];
            }
        }

        for (int k = 1; k <= n; ++k)
        {
            visited.clear();
            visited.resize((unsigned)n + 1, false);

            visited[k] = true;

            backtrack(k, k, 1.0);
        }

        if (ans.size() == n + 2) cout << "no arbitrage sequence exists" << endl;

        else
        {
            for (int l = 0; l < ans.size(); ++l)
            {
                cout << ans[l] << " ";
            }

            cout << endl;
        }
    }
}