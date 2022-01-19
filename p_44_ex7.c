#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
**************************** CHALLENGE 2 ****************************
	출처 : NUMBERTHEORY정수론 - 이모션미디어 조민형 지음 p.44 예제 7
************************************************************************
*/

void func(int, int, int, int *, int *);
void condition_check(int, int, int *, int *); //찾은 해가 정수인지 확인
void range_error(int, int);
void t_func(int, int, int, int, int *, int *, int);

int main()
{
	int a = 5, b = 6;
	int c = 17;
	int x = CHAR_MAX + 1, y;
	int *ptr = &x;
	int *ptr2 = &y;
	int x1, y1;
	func(a, b,  c, ptr, ptr2);
	
	if (x != (CHAR_MAX + 1))
	{
		x1 = x;
		y1 = y;
		printf("\n [대입 범위 %d에서 %d까지] %dx + %dy = %d에서 찾은 해는 x = %d y = %d입니다.\n", CHAR_MIN, CHAR_MAX,  a, b, c, x, y);
		int i;
		// t = -20 ~ t = 20 
		printf("\n x = %d , y = %d 이므로, [ t 대입 범위 -20 ~ 20 ]에 대해\n ", x, y);
		for (i = -20; i <= 20; i++)
		{
			t_func(a, b, x1, y1, ptr, ptr2, i);
			printf("\n t = %d에 대하여 해는( %d , %d )\n", i, x, y);
		}
	}
	else range_error(CHAR_MIN, CHAR_MAX);
}
void func(int a, int b, int c, int *ptr, int *ptr2)
{
	int i,j;

	for (i = CHAR_MIN; i <= CHAR_MAX; i++)
	{
		for (j = CHAR_MIN; j <= CHAR_MAX; j++)
		{
			if (c == (a*i) + (b*j))
			{
				condition_check(i, j, ptr, ptr2);
				return;
			}
		}
	}
}

void t_func(int a, int b, int x, int y, int* ptr, int* ptr2, int t)
{
	*ptr = x + b * t;
	*ptr2 = y - a * t;
}

void condition_check(int x, int y, int *ptr, int *ptr2)
{
	if (x - (int)x == 0 && y - (int)y == 0)
	{
		*ptr = x;
		*ptr2 = y;
	}
	else
	{
		fprintf(stderr, "x = %d, y = %d는 정수여야합니다", x, y);
		exit(1);
	}
}

void range_error(int min_range, int max_range)
{
	fprintf(stderr, "대입 범위 %d ~ %d 에서는 해를 찾지 못했습니다.", min_range, max_range);
	exit(1);
}