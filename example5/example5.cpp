
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

#include <math.h>

#ifndef M_PI
#define M_PI       3.14159265358979323846
#endif 

int main()
{
	int px, py, pz;
	BlockID goldblock = createBlock(BLOCK_GOLD);
	WoolID black_wool = createWool(COLOR_BLACK);
	getPlayerLocation(&px, &py, &pz);
	double dir = getPlayerDirection();
	double radian = dir * M_PI / 180.;
	int count = 10;
	int by = py;
	int bx = px - count * sin(radian);
	int bz = pz + count * cos(radian);
	locateBlock(goldblock, bx, py, bz);
	int x = bx, y = py, z = bz;
	printf("%f", dir);

	if (fabs(sin(radian)) < fabs(cos(radian)))
	{
		bx = bx - 15;
		x = bx;
		for (; x < (bx + 30); x++)
		{
			for (; y < (by + 15); y++)
			{
				locateWool(black_wool, x, y, z);
			}
			y = by;
		}
		x = bx;
		y = py;
		for (; x < (bx + 40); x++)
		{
			for (; y < (by + 40); y++)
			{
				if (((bx + 7 - x)*(bx + 7 - x) + (by + 7 - y) * (by + 7 - y)) <= 6 * 6 + 1)
				{
					locateBlock(goldblock, x, y, z);
				}
			}

			y = by;
		}
		locateWool(black_wool, bx + 14, by + 6, bz);
		locateWool(black_wool, bx + 14, by + 7, bz);
		locateWool(black_wool, bx + 14, by + 8, bz);

		locateWool(black_wool, bx + 13, by + 4, bz);
		locateWool(black_wool, bx + 13, by + 5, bz);
		locateWool(black_wool, bx + 13, by + 6, bz);
		locateWool(black_wool, bx + 13, by + 7, bz);
		locateWool(black_wool, bx + 13, by + 8, bz);
		locateWool(black_wool, bx + 13, by + 9, bz);
		locateWool(black_wool, bx + 13, by + 10, bz);

		locateWool(black_wool, bx + 12, by + 4, bz);
		locateWool(black_wool, bx + 12, by + 5, bz);
		locateWool(black_wool, bx + 12, by + 6, bz);
		locateWool(black_wool, bx + 12, by + 7, bz);
		locateWool(black_wool, bx + 12, by + 8, bz);
		locateWool(black_wool, bx + 12, by + 9, bz);
		locateWool(black_wool, bx + 12, by + 10, bz);

		locateWool(black_wool, bx + 11, by + 4, bz);
		locateWool(black_wool, bx + 11, by + 5, bz);
		locateWool(black_wool, bx + 11, by + 6, bz);
		locateWool(black_wool, bx + 11, by + 7, bz);
		locateWool(black_wool, bx + 11, by + 8, bz);
		locateWool(black_wool, bx + 11, by + 9, bz);
		locateWool(black_wool, bx + 11, by + 10, bz);

		locateWool(black_wool, bx + 10, by + 5, bz);
		locateWool(black_wool, bx + 10, by + 6, bz);
		locateWool(black_wool, bx + 10, by + 7, bz);
		locateWool(black_wool, bx + 10, by + 8, bz);
		locateWool(black_wool, bx + 10, by + 9, bz);

		locateWool(black_wool, bx + 9, by + 6, bz);
		locateWool(black_wool, bx + 9, by + 7, bz);
		locateWool(black_wool, bx + 9, by + 8, bz);

		locateWool(black_wool, bx + 8, by + 7, bz);

		locateBlock(goldblock, bx + 14, by + 7, bz);
		locateBlock(goldblock, bx + 19, by + 7, bz);
		locateBlock(goldblock, bx + 24, by + 7, bz);
		return 0;
	}
	if (fabs(sin(radian)) > fabs(cos(radian)))
	{
		bz = bz - 15;
		z = bz;
		for (; z < (bz + 30); z++)
		{
			for (; y < (by + 15); y++)
			{
				locateWool(black_wool, x, y, z);
			}
			y = by;
		}
		z = bz;
		y = py;
		for (; z < (bz + 40); z++)
		{
			for (; y < (by + 40); y++)
			{
				if (((bz + 7 - z)*(bz + 7 - z) + (by + 7 - y) * (by + 7 - y)) <= 6 * 6 + 1)
				{
					locateBlock(goldblock, x, y, z);
				}
			}

			y = by;
		}
		locateWool(black_wool, bx, by + 6, bz + 14);
		locateWool(black_wool, bx, by + 7, bz + 14);
		locateWool(black_wool, bx, by + 8, bz + 14);

		locateWool(black_wool, bx, by + 4, bz + 13);
		locateWool(black_wool, bx, by + 5, bz + 13);
		locateWool(black_wool, bx, by + 6, bz + 13);
		locateWool(black_wool, bx, by + 7, bz + 13);
		locateWool(black_wool, bx, by + 8, bz + 13);
		locateWool(black_wool, bx, by + 9, bz + 13);
		locateWool(black_wool, bx, by + 10, bz + 13);

		locateWool(black_wool, bx, by + 4, bz + 12);
		locateWool(black_wool, bx, by + 5, bz + 12);
		locateWool(black_wool, bx, by + 6, bz + 12);
		locateWool(black_wool, bx, by + 7, bz + 12);
		locateWool(black_wool, bx, by + 8, bz + 12);
		locateWool(black_wool, bx, by + 9, bz + 12);
		locateWool(black_wool, bx, by + 10, bz + 12);

		locateWool(black_wool, bx, by + 4, bz + 11);
		locateWool(black_wool, bx, by + 5, bz + 11);
		locateWool(black_wool, bx, by + 6, bz + 11);
		locateWool(black_wool, bx, by + 7, bz + 11);
		locateWool(black_wool, bx, by + 8, bz + 11);
		locateWool(black_wool, bx, by + 9, bz + 11);
		locateWool(black_wool, bx, by + 10, bz + 11);

		locateWool(black_wool, bx, by + 5, bz + 10);
		locateWool(black_wool, bx, by + 6, bz + 10);
		locateWool(black_wool, bx, by + 7, bz + 10);
		locateWool(black_wool, bx, by + 8, bz + 10);
		locateWool(black_wool, bx, by + 9, bz + 10);

		locateWool(black_wool, bx, by + 6, bz + 9);
		locateWool(black_wool, bx, by + 7, bz + 9);
		locateWool(black_wool, bx, by + 8, bz + 9);

		locateWool(black_wool, bx, by + 7, bz + 8);

		locateBlock(goldblock, bx, by + 7, bz + 14);
		locateBlock(goldblock, bx, by + 7, bz + 19);
		locateBlock(goldblock, bx, by + 7, bz + 24);
		return 0;
	}

}