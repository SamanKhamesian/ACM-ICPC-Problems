#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 55

char dir;
int ansI, ansJ;
int n, m, rn, rs;
int preMAX, curMAX;
bool visited[MAX][MAX];
int castle[MAX][MAX], roomNumber[MAX][MAX], roomSize[MAX * MAX];

ifstream fin("castle.in");
ofstream fout("castle.out");

void dfs(int i, int j)
{
    if (!visited[i][j])
    {
        rs++;
        visited[i][j] = true;
        roomNumber[i][j] = rn;

        if (!(castle[i][j] & 1)) dfs(i, j - 1);
        if (!(castle[i][j] & 2)) dfs(i - 1, j);
        if (!(castle[i][j] & 4)) dfs(i, j + 1);
        if (!(castle[i][j] & 8)) dfs(i + 1, j);
    }
}

int main()
{
    fin >> m >> n;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            fin >> castle[i][j];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (!visited[i][j])
            {
                rs = 0;
                rn += 1;

                dfs(i, j);

                roomSize[rn] = rs;

                preMAX = max(preMAX, rs);
            }
        }
    }

    for (int j = 1; j <= m ; ++j)
    {
        for (int i = n; i >= 1 ; i--)
        {
            if (castle[i][j] & 2)
            {
                if (roomNumber[i - 1][j] && (roomNumber[i - 1][j] != roomNumber[i][j]))
                {
                    if (roomSize[roomNumber[i - 1][j]] + roomSize[roomNumber[i][j]] > curMAX)
                    {
                        curMAX = roomSize[roomNumber[i - 1][j]] + roomSize[roomNumber[i][j]];

                        ansI = i;
                        ansJ = j;
                        dir = 'N';
                    }
                }
            }

            if (castle[i][j] & 4)
            {
                if (roomNumber[i][j + 1] && (roomNumber[i][j + 1] != roomNumber[i][j]))
                {
                    if (roomSize[roomNumber[i][j + 1]] + roomSize[roomNumber[i][j]] > curMAX)
                    {
                        curMAX = roomSize[roomNumber[i][j + 1]] + roomSize[roomNumber[i][j]];

                        ansI = i;
                        ansJ = j;
                        dir = 'E';
                    }
                }
            }
        }
    }

    fout << rn << endl << preMAX << endl << curMAX << endl;
    fout << ansI << " " << ansJ << " " << dir << endl;
}