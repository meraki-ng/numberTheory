#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
*********************CHALLENGE 2*********************
		for�� ������ ���ϳ� ���� 1��ɷȴ� ��_��
				 �������� 2���� ����������
			   ax+by=c(a,b!=0, a,b,c=���)
			���� ���� : -128 ~ +127 (char ����)
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
			if (c == (a*x) + (b*y))   printf("\n x=%3d �϶�, y=%3d", x, y);
		}
	}
	return 0;
}