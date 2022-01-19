/*
********************************************* CHALLENGE 1 ***********************************************
												��ó : NUMBERTHEORY������ - �̸�ǹ̵�� ������ ���� p.45 ���� 9
															  (a) 14x + 34y = 90 -> (14, 34) | 90 �̹Ƿ� �ذ� �ִ�.
														   	  (b) 14x + 35 y = 91 -> (14, 35) | 91 �̹Ƿ� �ذ� �ִ�.
															  (c) 14x + 36y = 93 -> (14, 36) |93 �� �ƴϹǷ� �ذ� ����.	
														    	     	��ǥ : ax + by = c���� ���ο� a'x + b'y = c'���
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
		printf("***���ο� a'x + b'y = c' \n %dx + %dy = %d ", x_coefficient, y_coefficient, constant);
		break;
	case -1 :
		error();
		break;
	}
}
int condition_check(int *ptr, int *ptr2, int *ptr3)
{
	int gcd = 1, count = 0, i = 2;
	if (ptr < ptr2) //������ �׻� y�� ����� �� ũ�ϱ� �� ��츸 ��������.
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
	fprintf(stderr, "�ذ� �����ϴ�.");
	exit(1);
}