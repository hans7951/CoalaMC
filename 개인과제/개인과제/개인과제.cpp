#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

BlockID red_Block = createWool(COLOR_RED);

BlockID orange_Block = createWool(COLOR_ORANGE);

BlockID yellow_Block = createWool(COLOR_YELLOW);

BlockID lime_Block = createWool(COLOR_LIME);

BlockID green_Block = createWool(COLOR_GREEN);

BlockID light_blue_Block = createWool(COLOR_LIGHT_BLUE);

BlockID blue_Block = createWool(COLOR_BLUE);

BlockID purple_Block = createWool(COLOR_PURPLE);

BlockID white_Block = createWool(COLOR_WHITE);

void drawLine(int color, float x1, float y1, float z1, float x2, float y2, float z2)
{
	BlockID block = 0;
	switch (color)
	{
	case 1:
		block = red_Block;
		break;
	case 2:
		block = orange_Block;
		break;
	case 3:
		block = yellow_Block;
		break;
	case 4:
		block = lime_Block;
		break;
	case 5:
		block = green_Block;
		break;
	case 6:
		block = light_blue_Block;
		break;
	case 7:
		block = blue_Block;
		break;
	case 8:
		block = purple_Block;
		break;
	case 9:
		block = white_Block;
		break;
	}

	float bx = x1, by = y1, bz = z1, max;
	max = abs(x1 - x2);

	if (abs(x1 - x2) < abs(y1 - y2))
		max = abs(y1 - y2);

	if (abs(y1 - y2) < abs(z1 - z2))
		max = abs(z1 - z2);



	if (max == abs(x1 - x2))
	{
		bx = (x1 < x2 ? x1 : x2);
		for (; bx < (x1 < x2 ? x2 : x1); bx++) {
			by = ((bx - x1) / (x1 - x2)) * (y1 - y2) + y1;
			bz = ((bx - x1) / (x1 - x2)) * (z1 - z2) + z1;
			locateWool(block, bx, by, bz);
		}
	}
	else if (max == abs(y1 - y2))
	{
		by = (y1 < y2 ? y1 : y2);
		for (; by < (y1 < y2 ? y2 : y1); by++) {
			bx = ((by - y1) / (y1 - y2)) * (x1 - x2) + x1;
			bz = ((by - y1) / (y1 - y2)) * (z1 - z2) + z1;
			locateWool(block, bx, by, bz);
		}
	}
	else
	{
		bz = (z1 < z2 ? z1 : z2);
		for (; bz < (z1 < z2 ? z2 : z1); bz++)
		{
			by = ((bz - z1) / (z1 - z2)) * (y1 - y2) + y1;
			bx = ((bz - z1) / (z1 - z2)) * (x1 - x2) + x1;
			locateWool(block, bx, by, bz);
		}
	}
}



int main()
{
	float bx1 = 0, by1 = 0, bz1 = 0, bx2 = 0, by2 = 0, bz2 = 0;
	printf("첫번째 좌표를 입력해주세요");
	scanf_s("%f %f %f", &bx1, &by1, &bz1);
	printf("\n두번째 좌표를 입력해주세요");
	scanf_s("%f %f %f", &bx2, &by2, &bz2);


	if (abs(bx1 - bx2) < 3 || abs(by1 - by2) < 3 || abs(bz1 - bz2) < 3)
	{
		printf("범위가 너무 작습니다!");
		exit(1);
	}


	float rx = (bx1 + bx2) / 2, ry = (by1 + by2) / 2, rz = (bz1 + bz2) / 2;

	float edge = abs(bx1 - bx2);

	if (abs(bx1 - bx2) > abs(by1 - by2) || abs(bz1 - bz2) > abs(by1 - by2))
	{
		edge = abs(by1 - by2);
	}

	if (abs(by1 - by2) > abs(bz1 - bz2) || abs(bx1 - bx2) > abs(bz1 - bz2))
	{
		edge = abs(bz1 - bz2);
	}

	float location[3][4][3] = { 0, };


	location[0][0][0] = rx + ((edge / 2) - 1);
	location[0][0][1] = ry + edge / ((1 + sqrt(5.0)));
	location[0][0][2] = rz;

	location[0][1][0] = rx + ((edge / 2) - 1);
	location[0][1][1] = ry - edge / ((1 + sqrt(5.0)));
	location[0][1][2] = rz;

	location[0][2][0] = rx - ((edge / 2) - 1);
	location[0][2][1] = ry + edge / ((1 + sqrt(5.0)));
	location[0][2][2] = rz;

	location[0][3][0] = rx - ((edge / 2) - 1);
	location[0][3][1] = ry - edge / ((1 + sqrt(5.0)));
	location[0][3][2] = rz;

	location[1][0][0] = rx;
	location[1][0][1] = ry + ((edge / 2) - 1);
	location[1][0][2] = rz + edge / ((1 + sqrt(5.0)));

	location[1][1][0] = rx;
	location[1][1][1] = ry + ((edge / 2) - 1);
	location[1][1][2] = rz - edge / ((1 + sqrt(5.0)));

	location[1][2][0] = rx;
	location[1][2][1] = ry - ((edge / 2) - 1);
	location[1][2][2] = rz + edge / ((1 + sqrt(5.0)));

	location[1][3][0] = rx;
	location[1][3][1] = ry - ((edge / 2) - 1);
	location[1][3][2] = rz - edge / ((1 + sqrt(5.0)));

	location[2][0][0] = rx + edge / ((1 + sqrt(5.0)));
	location[2][0][1] = ry;
	location[2][0][2] = rz + ((edge / 2) - 1);

	location[2][1][0] = rx + edge / ((1 + sqrt(5.0)));
	location[2][1][1] = ry;
	location[2][1][2] = rz - ((edge / 2) - 1);

	location[2][2][0] = rx - edge / ((1 + sqrt(5.0)));
	location[2][2][1] = ry;
	location[2][2][2] = rz + ((edge / 2) - 1);

	location[2][3][0] = rx - edge / ((1 + sqrt(5.0)));
	location[2][3][1] = ry;
	location[2][3][2] = rz - ((edge / 2) - 1);

	int a1, b1, a2, b2;
	srand(time(NULL));
	int random = (rand() % 8) + 1;
	a1 = 0;
	for (; a1 < 3; a1++)
	{
		b1 = 0;
		for (; b1 < 4; b1++)
		{
			a2 = 0;
			for (; a2 < 3; a2++)
			{
				b2 = 0;
				for (; b2 < 4; b2++)
				{
					drawLine(random, location[a1][b1][0], location[a1][b1][1], location[a1][b1][2], location[a2][b2][0], location[a2][b2][1], location[a2][b2][2]);
				}
			}
		}
	}
}
