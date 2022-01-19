#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
**************************** CHALLENGE 2 ****************************
	��ó : NUMBERTHEORY������ - �̸�ǹ̵�� ������ ���� p.44 ���� 7
************************************************************************
*/

void func(int, int, int, int *, int *);
void condition_check(int, int, int *, int *); //ã�� �ذ� �������� Ȯ��
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
		printf("\n [���� ���� %d���� %d����] %dx + %dy = %d���� ã�� �ش� x = %d y = %d�Դϴ�.\n", CHAR_MIN, CHAR_MAX,  a, b, c, x, y);
		int i;
		// t = -20 ~ t = 20 
		printf("\n x = %d , y = %d �̹Ƿ�, [ t ���� ���� -20 ~ 20 ]�� ����\n ", x, y);
		for (i = -20; i <= 20; i++)
		{
			t_func(a, b, x1, y1, ptr, ptr2, i);
			printf("\n t = %d�� ���Ͽ� �ش�( %d , %d )\n", i, x, y);
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
		fprintf(stderr, "x = %d, y = %d�� ���������մϴ�", x, y);
		exit(1);
	}
}

void range_error(int min_range, int max_range)
{
	fprintf(stderr, "���� ���� %d ~ %d ������ �ظ� ã�� ���߽��ϴ�.", min_range, max_range);
	exit(1);
}