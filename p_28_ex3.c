/*
***************************************** CHALLENGE 1 *******************************************
						��ó : NUMBERTHEORY������ - �̸�ǹ̵�� ������ ���� p.28 ���� 3
																	91�� �Ҽ��ΰ� Ȯ�� ����
			��������3. n�� �ռ���(ompositite)�̸�, n�� 1 < d <= sqrt(n)�� �����ϴ� ��� d�� ������ �ִ�.
****************************************************************************************************
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N_NUM 91 // p.28 ex. sqrt(269), sqrt(289)Ȯ�� �Ϸ�

void prime(int, int *);
int prime2(int, int);

int main()
{
	int *ptr = (int *)calloc(N_NUM - 2, sizeof(char)); // 1 < primeTable < n_num
	prime(sqrt(N_NUM), ptr); //�Ҽ��� ����.

	//calloc �� ���� ��� 0���� �ʱ�ȭ.
	for (int i = 0; i < ptr[i] != 0; i++)
	{
		if (!prime2(N_NUM, ptr[i]))
		{
			printf("%d�� %d(��)�� �������Ƿ� �Ҽ��� �ƴմϴ�.\n", N_NUM, ptr[i]);
			break;
		}
	}
	free(ptr);
	return 0;
}

void prime(int n, int *ptr)
{
	int count = 0;
	int k = 0;
	//�ڿ������� 2��  1�� �ڱ��ڽŸ��� ����� ������ ���� �Ҽ��� �����̱� ������ ������ �Ҽ��̴�.
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0) count++;
		}
		if (count == 0)
		{
			ptr[k] = i;
			k++;
		}
		count = 0;
	}
}

int prime2(int n, int ptr)
{
	return n % ptr;
}