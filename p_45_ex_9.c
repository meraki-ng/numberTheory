/*
********************************************* CHALLENGE 1 ***********************************************
												출처 : NUMBERTHEORY정수론 - 이모션미디어 조민형 지음 p.45 예제 9
															  (a) 14x + 34y = 90 -> (14, 34) | 90 이므로 해가 있다.
														   	  (b) 14x + 35 y = 91 -> (14, 35) | 91 이므로 해가 있다.
															  (c) 14x + 36y = 93 -> (14, 36) |93 이 아니므로 해가 없다.	
														    	     	목표 : ax + by = c에서 새로운 a'x + b'y = c'얻기
************************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

int condition_check(int *, int *, int *);
void error(); 

void main()
{
	int x_coefficient = 14; 
	int y_coefficient = 34; //35, 36
	int constant = 90; //91,93
	int *ptr = &x_coefficient;
	int *ptr2 = &y_coefficient;
	int *ptr3 = &constant;

	int res = condition_check(ptr, ptr2, ptr3);
	switch (res)
	{
	case 1 :
		printf("***새로운 a'x + b'y = c' \n %dx + %dy = %d ", x_coefficient, y_coefficient, constant);
		break;
	case -1 :
		error();
		break;
	}
}
int condition_check(int *ptr, int *ptr2, int *ptr3)
{
	int gcd = 1, count = 0, i = 2;
	if (ptr < ptr2) //지금은 항상 y의 계수가 더 크니깐 이 경우만 생각하자.
	{
		while (i <= *ptr)
		{ 
			if (!((*ptr) % i )& !((*ptr2) % i) & !((*ptr3) % i))
			{
				*ptr = (*(ptr) / i);
				*ptr2 = (*(ptr2 )/ i);
				*ptr3 = (*(ptr3) / i);
				return 1;
			}
			i++;
		}
	}
	return -1;
}

void error()
{
	fprintf(stderr, "해가 없습니다.");
	exit(1);
}