#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

#define CONST 1000000
#define MAX 2000000000

int main()
{
	for (int x = 1; x <= 2000; x++)
	{
		if (x * x * x * x > MAX) break;

		for (int y = x; y <= 2000 - x; y++)
		{
			if (x * y * y * y > MAX) break;

			for (int z = y; z <= 2000 - x - y; z++)
			{
				if (x * y * z * z > MAX) break;

				else
				{
					int a, b, t;

					a = x + y + z;
					b = x * y * z;

					if (b > CONST && ((a * CONST) % (b - CONST)) == 0)
					{
						t = ((a * CONST) / (b - CONST));

						if (t <= (2000 - x - y - z) && t >= z && (x + y + z + t) * CONST == (x * y * z * t))
						{
							double xx = x / 100.0;
							double yy = y / 100.0;
							double zz = z / 100.0;
							double tt = t / 100.0;

							printf("%.2f %.2f %.2f %.2f\n", xx, yy, zz, tt);
						}
					}
				}
			}
		}
	}
}