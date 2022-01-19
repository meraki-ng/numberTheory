#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
*********************CHALLENGE 2*********************
		for문 이해의 축하날 빠밤 1년걸렸다 ㅜ_ㅜ
				 미지수가 2개인 일차방정식
			   ax+by=c(a,b!=0, a,b,c=상수)
			대입 범위 : -128 ~ +127 (char 범위)
*****************************************************
*/

int main()
{

	int a = 343, b = 280, c = 7;
	int x, y;

	for (x = CHAR_MIN; x <= CHAR_MAX; x++)
	{
		for (y = CHAR_MIN; y <= CHAR_MAX; y++)
		{
			if (c == (a*x) + (b*y))   printf("\n x=%3d 일때, y=%3d", x, y);
		}
	}
	return 0;
}