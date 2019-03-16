#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

#define MAX 101

int n;
int weight[MAX][MAX];
vector<set <int> > controls(MAX);
vector< vector<int> > graph(MAX);

ifstream fin("concom.in");
ofstream fout("concom.out");

void initialize()
{
    for (int i = 0; i < MAX; ++i)
    {
        controls[i].insert(i);
    }
}

void directControl()
{
    for (int i = 0; i < MAX; ++i)
    {
        for (int j = 0; j < graph[i].size(); ++j)
        {
            int child = graph[i][j];

            if (weight[i][child] > 50) controls[i].insert(child);
        }
    }
}

void indirectControl()
{
    for (int l = 0; l < MAX; ++l)
    {
        for (int i = 0; i < MAX; ++i)
        {
            bool ok;

            do
            {
                ok = true;

                int sz = controls.size();

                for (int j = 0; j < MAX; ++j)
                {
                    int how = 0;

                    for (set<int>::iterator k = controls[i].begin(); k != controls[i].end(); ++k)
                    {
                        how += weight[*k][j];
                    }

                    if (how > 50)
                    {
                        controls[i].insert(j);
                    }
                }

                if (sz != controls.size()) ok = false;

            } while (!ok);
        }
    }
}

int main()
{
    fin >> n;

    initialize();

    for (int i = 0; i < n; ++i)
    {
        int x, y, z;

        fin >> x >> y >> z;

        graph[x].push_back(y);
        weight[x][y] = z;
    }

    directControl();

    indirectControl();

    for (int i = 0; i < MAX; ++i)
    {
        if (controls[i].size() > 0)
        {
            for (set<int>::iterator j = controls[i].begin(); j != controls[i].end(); ++j)
            {
                if (*j != i) fout << i << " " << *j << endl;
            }
        }
    }
}