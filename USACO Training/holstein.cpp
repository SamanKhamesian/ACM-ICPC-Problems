#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

int v, g, ans_size = 1000;

vector<int> vit, twos;
vector< vector<int> > feed;
vector< set<int> > comb;

ifstream fin("holstein.in");
ofstream fout("holstein.out");

bool isOk(vector<int> a)
{
    bool pk = true;

    for (int i = 0; i < v; ++i)
    {
        if (a[i] < vit[i])
        {
            pk = false;
            break;
        }
    }

    return pk;
}

set<int> cal(int k)
{
    set<int> s;
    vector<int> temp(v, 0);

    for (int i = g - 1; i >= 0; i--)
    {
        if (k != 0 && k - twos[i] >= 0)
        {
            k -= twos[i];

            s.insert(i + 1);

            for (int j = 0; j < v; ++j)
            {
                temp[j] += feed[i][j];
            }
        }
    }

    if (isOk(temp) && s.size() <= ans_size)
    {
        comb.clear();
        ans_size = (int) s.size();
        return s;
    }

    else
    {
        s.clear();
        return s;
    }
};

int main()
{
    fin >> v;

    vit.resize(v);

    for (int i = 0; i < v; ++i)
    {
        fin >> vit[i];
    }

    fin >> g;

    for (int l = 0; l < g; ++l)
    {
        twos.push_back((int)pow(2.0, l * 1.0));
    }

    for (int i = 0; i < g; ++i)
    {
        vector<int> t(v);

        for (int j = 0; j < v; ++j)
        {
            fin >> t[j];
        }

        feed.push_back(t);
    }

    for (int k = 1; k < (int)pow(2.0, g * 1.0) ; ++k)
    {
        set<int> t = cal(k);

        if (t.size() != 0)
        {
            comb.push_back(t);
        }
    }

    sort(comb.begin(), comb.end());

    fout << comb[0].size();

    for (set<int>::iterator m = comb[0].begin(); m != comb[0].end(); ++m)
    {
        fout << " " << *m;
    }

    fout << endl;
}