#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
**************************** CHALLENGE 6 ****************************
	출처 : NUMBERTHEORY정수론 - 이모션미디어 조민형 지음 p.44 예제 6
		p.43 보조정리 1 과 p.11 정의 2 이용하여
	gcd(343, 280)= 7에서 343x + 280y = 7을 풀이하라
*********************************************************************
*/

void func(int, int, int, int *, int *);
void gcd_check(int, int, int, int *, int *);
void condition_check(int, int, int *, int *); //찾은 해가 정수인지 확인
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
		printf("찾은 해는 x = %d, y = %d", x, y);
		int i, res;
		// t = 1 ~ t = 100
		for (i = 0; i < 100; i++)
		{
			res = t_func(a, b, x, y, i + 1);
			printf("\n임의의 t = %d에 대하여 계산하면 %d\n", i+1, res);
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
		fprintf(stderr, "(0,0)은 정의될 수 없습니다.");
		exit(1);
	}
	else
	{
		if ((a % gcd) == 0 && (b % gcd) == 0) func(a, b, gcd, ptr, ptr2);
		else
		{
			fprintf(stderr, "(%d, %d)는 %d의 최대공약수가 아닙니다.", a, b, gcd);
			exit(1);
		}
	}
}
void condition_check(int x, int y, int *ptr, int *ptr2)
{
	//여기서는 정수가 틀림없겠지만 그래도 해주자!
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