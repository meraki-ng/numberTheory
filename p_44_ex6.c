#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
**************************** CHALLENGE 6 ****************************
	��ó : NUMBERTHEORY������ - �̸�ǹ̵�� ������ ���� p.44 ���� 6
		p.43 �������� 1 �� p.11 ���� 2 �̿��Ͽ�
	gcd(343, 280)= 7���� 343x + 280y = 7�� Ǯ���϶�
*********************************************************************
*/

void func(int, int, int, int *, int *);
void gcd_check(int, int, int, int *, int *);
void condition_check(int, int, int *, int *); //ã�� �ذ� �������� Ȯ��
void range_error(int, int);
int t_func(int, int, int, int, int);

int main()
{
	int a =343, b = 280;
	int gcd = 7;
	int x = CHAR_MAX + 1, y;
	int *ptr = &x;
	int *ptr2 = &y;

	gcd_check(a, b, gcd, ptr, ptr2);

	if (x != (CHAR_MAX + 1))
	{
		printf("ã�� �ش� x = %d, y = %d", x, y);
		int i, res;
		// t = 1 ~ t = 100
		for (i = 0; i < 100; i++)
		{
			res = t_func(a, b, x, y, i + 1);
			printf("\n������ t = %d�� ���Ͽ� ����ϸ� %d\n", i+1, res);
		}
	}
	else range_error(CHAR_MIN, CHAR_MAX);

}
void func(int a, int b, int gcd, int *ptr, int *ptr2)
{
	int i,j;

	for (i = CHAR_MIN; i <= CHAR_MAX; i++)
	{
		for (j = CHAR_MIN; j <= CHAR_MAX; j++)
		{
			if (gcd == (a*i) + (b*j))
			{
				condition_check(i, j, ptr, ptr2);
				return;
			}
		}
	}
}

int t_func(int a, int b, int x, int y, int t)
{
	return  (a * (x + b * t)) + (b * (y - a * t));
}

void gcd_check(int a, int b, int gcd, int *ptr, int *ptr2)
{
	if (a == 0 && b == 0)
	{
		fprintf(stderr, "(0,0)�� ���ǵ� �� �����ϴ�.");
		exit(1);
	}
	else
	{
		if ((a % gcd) == 0 && (b % gcd) == 0) func(a, b, gcd, ptr, ptr2);
		else
		{
			fprintf(stderr, "(%d, %d)�� %d�� �ִ������� �ƴմϴ�.", a, b, gcd);
			exit(1);
		}
	}
}
void condition_check(int x, int y, int *ptr, int *ptr2)
{
	//���⼭�� ������ Ʋ���������� �׷��� ������!
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