#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 21

int A, B, C;
bool visited[MAX][MAX][MAX];
vector <int> ans;

ifstream fin("milk3.in");
ofstream fout("milk3.out");

void solve(int a, int b, int c)
{
    if (!visited[a][b][c])
    {
        visited[a][b][c] = true;

        if (c != 0)
        {
            int temp = 0;

            while (c != 0 && b != B)
            {
                b++;
                c--;
                temp++;
            }

            c += temp;
            b -= temp;

            solve(a, b + temp, c - temp);

            temp = 0;

            while (c != 0 && a != A)
            {
                a++;
                c--;
                temp++;
            }

            c += temp;
            a -= temp;

            solve(a + temp, b, c - temp);
        }

        if (b != 0)
        {
            int temp = 0;

            while (b != 0 && c != C)
            {
                b--;
                c++;
                temp++;
            }

            c -= temp;
            b += temp;

            solve(a, b - temp, c + temp);

            temp = 0;

            while (b != 0 && a != A)
            {
                b--;
                a++;
                temp++;
            }

            a -= temp;
            b += temp;

            solve(a + temp, b - temp, c);
        }

        if (a != 0)
        {
            int temp = 0;

            while (a != 0 && c != C)
            {
                a--;
                c++;
                temp++;
            }

            a += temp;
            c -= temp;

            solve(a - temp, b, c + temp);

            temp = 0;

            while (a != 0 && b != B)
            {
                a--;
                b++;
                temp++;
            }

            a += temp;
            b -= temp;

            solve(a - temp, b + temp, c);
        }

        else ans.push_back(c);
    }
}

int main()
{
    int a, b, c;

    fin >> a >> b >> c;

    A = a;
    B = b;
    C = c;

    solve(0, 0, c);

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); ++i)
    {
        if (i == 0) fout << ans[i];

        else fout << " " << ans[i];
    }

    fout << endl;
}