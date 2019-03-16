#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct point
{
	int x, y;
};

point m, n, p;

int dist(int ax, int ay, int bx, int by)
{
	return (((ax - bx) * (ax - bx)) + ((ay - by) * (ay - by)));
}

int main()
{
	cin >> m.x >> m.y;
	cin >> n.x >> n.y;
	cin >> p.x >> p.y;

	cout << 3 << endl;

	for (int x = -3000; x <= 3000; x++)
	{
		for (int y = -3000; y <= 3000; y++)
		{
			bool ok = true;
			point a, b;
			int pair_m_c, pair_n_c, pair_p_c, pair_m_n, pair_m_p, pair_n_p;

			pair_m_c = dist(m.x, m.y, x, y);
			pair_n_c = dist(n.x, n.y, x, y);
			pair_p_c = dist(p.x, p.y, x, y);
			pair_m_n = dist(m.x, m.y, n.x, n.y);
			pair_m_p = dist(m.x, m.y, p.x, p.y);
			pair_n_p = dist(n.x, n.y, p.x, p.y);

			if ((x == m.x && y == m.y) || (x == n.x && y == n.y) || (x == p.x && y == p.y)) continue;

			if (pair_p_c == pair_m_n && pair_m_p == pair_n_c && ok)
			{
				a.x = (m.x + x);
				a.y = (m.y + y);

				b.x = (n.x + p.x);
				b.y = (n.y + p.y);

				if (a.x == b.x && a.y == b.y) 
				{
					cout << x << " " << y << endl;
					ok = false;
				}
			}

			if (pair_m_c == pair_n_p && pair_p_c == pair_m_n && ok)
			{
				a.x = (n.x + x);
				a.y = (n.y + y);

				b.x = (m.x + p.x);
				b.y = (m.y + p.y);

				if (a.x == b.x && a.y == b.y)
				{
					ok = false;
					cout << x << " " << y << endl;
				}
			}

			if (pair_m_c == pair_n_p && pair_m_p == pair_n_c && ok)
			{
				a.x = (p.x + x);
				a.y = (p.y + y);

				b.x = (m.x + n.x);
				b.y = (m.y + n.y);

				if (a.x == b.x && a.y == b.y)
				{
					ok = false;
					cout << x << " " << y << endl;
				}
			}
		}
	}

}