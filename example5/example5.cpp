
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
	int bx = px - count * sin(radian) - 15;
	int bz = pz + count * cos(radian);
	locateBlock(goldblock, bx, py, bz);
	int x = bx, y = py, z = bz;

	for (; x < (bx + 30); x++)
	{
		for (; z < (bz + 15); z++)
		{
			locateWool(black_wool, x, y, z);
		}
		z = bz;
	}
	x = bx;
	y = py;
	z = bz;
	for (; x < (bx + 40); x++)
	{
		for (; z < (bz + 40); z++)
		{
			if (((bx + 7 - x)*(bx + 7 - x) + (bz + 7 - z) * (bz + 7 - z)) <= 6 * 6 + 1)
			{
				locateBlock(goldblock, x, y, z);
			}
		}

		z = bz;
	}
	locateWool(black_wool, bx + 14, by, bz + 6);
	locateWool(black_wool, bx + 14, by, bz + 7);
	locateWool(black_wool, bx + 14, by, bz + 8);

	locateWool(black_wool, bx + 13, by, bz + 4);
	locateWool(black_wool, bx + 13, by, bz + 5);
	locateWool(black_wool, bx + 13, by, bz + 6);
	locateWool(black_wool, bx + 13, by, bz + 7);
	locateWool(black_wool, bx + 13, by, bz + 8);
	locateWool(black_wool, bx + 13, by, bz + 9);
	locateWool(black_wool, bx + 13, by, bz + 10);

	locateWool(black_wool, bx + 12, by, bz + 4);
	locateWool(black_wool, bx + 12, by, bz + 5);
	locateWool(black_wool, bx + 12, by, bz + 6);
	locateWool(black_wool, bx + 12, by, bz + 7);
	locateWool(black_wool, bx + 12, by, bz + 8);
	locateWool(black_wool, bx + 12, by, bz + 9);
	locateWool(black_wool, bx + 12, by, bz + 10);

	locateWool(black_wool, bx + 11, by, bz + 4);
	locateWool(black_wool, bx + 11, by, bz + 5);
	locateWool(black_wool, bx + 11, by, bz + 6);
	locateWool(black_wool, bx + 11, by, bz + 7);
	locateWool(black_wool, bx + 11, by, bz + 8);
	locateWool(black_wool, bx + 11, by, bz + 9);
	locateWool(black_wool, bx + 11, by, bz + 10);

	locateWool(black_wool, bx + 10, by, bz + 5);
	locateWool(black_wool, bx + 10, by, bz + 6);
	locateWool(black_wool, bx + 10, by, bz + 7);
	locateWool(black_wool, bx + 10, by, bz + 8);
	locateWool(black_wool, bx + 10, by, bz + 9);

	locateWool(black_wool, bx + 9, by, bz + 6);
	locateWool(black_wool, bx + 9, by, bz + 7);
	locateWool(black_wool, bx + 9, by, bz + 8);

	locateWool(black_wool, bx + 8, by, bz + 7);

	locateBlock(goldblock, bx + 14, by, bz + 7);
	locateBlock(goldblock, bx + 19, by, bz + 7);
	locateBlock(goldblock, bx + 24, by, bz + 7);
}