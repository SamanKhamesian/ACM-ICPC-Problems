#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <iomanip>

using namespace std;

#define MAX 110
#define INF 100000000

int n, m, sx, sy, ex, ey;
int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

int direction;
bool graph[MAX][MAX];
bool input[MAX][MAX];
bool visited[MAX][MAX][4];

void initialize()
{
    memset(input, false, sizeof input);
    memset(graph, true, sizeof graph);
    memset(visited, false, sizeof visited);

    for (int i = 0; i <= n ; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i == 0 || j == 0 || i == n || j == m)
            {
                graph[i][j] = false;
            }
        }
    }
}

void makeGraph()
{
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m ; ++j)
        {
            graph[i][j] = input[i - 1][j] && input[i][j - 1] && input[i - 1][j - 1] && input[i][j];
        }
    }
}

bool isOk(int i, int j)
{
    return i > 0 && j > 0 && i < n && j < m && graph[i][j];
}

int bfs()
{
    visited[sx][sy][direction] = true;

    queue<pair <pair <int, int>, pair <int, int> > > queue1;

    queue1.push(make_pair(make_pair(direction, 0), make_pair(sx, sy)));

    while (!queue1.empty())
    {
        int x = queue1.front().second.first;
        int y = queue1.front().second.second;
        int d = queue1.front().first.first;
        int t = queue1.front().first.second;

        if (x == ex && y == ey)
            return t;

        queue1.pop();

        if (!visited[x][y][(d + 1) % 4])
        {
            visited[x][y][(d + 1) % 4] = true;
            queue1.push(make_pair(make_pair(((d + 1) % 4), t + 1), make_pair(x, y)));
        }

        if (!visited[x][y][(d + 3) % 4])
        {
            visited[x][y][(d + 3) % 4] = true;
            queue1.push(make_pair(make_pair(((d + 3) % 4), t + 1), make_pair(x, y)));
        }

        bool go = true;

        for (int i = 1; i <= 3; ++i)
        {
            if (isOk(x + (dirX[d] * i), y + (dirY[d] * i)) && go)
            {
                go = true;

                if (!visited[x + (dirX[d] * i)][y + (dirY[d] * i)][d])
                {
                    visited[x + (dirX[d] * i)][y + (dirY[d] * i)][d] = true;
                    queue1.push(make_pair(make_pair(d, t + 1), make_pair(x + (dirX[d] * i), y + (dirY[d] * i))));
                }
            }
            else go = false;
        }
    }

    return -1;
}

int main()
{
    while (cin >> n >> m && (n != 0 || m!= 0))
    {
        initialize();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                bool cell;
                cin >> cell;
                input[i][j] = !cell;
            }
        }

        makeGraph();

        string s;
        cin >> sx >> sy >> ex >> ey >> s;

        if (s == "north") direction = 0;
        else if (s == "east") direction = 1;
        else if (s == "south") direction = 2;
        else if (s == "west") direction = 3;

        if (!graph[sx][sy])
        {
            cout << -1 << endl;
        }

        else
        {
            cout << bfs() << endl;
        }
    }
}