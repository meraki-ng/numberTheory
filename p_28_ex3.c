/*
***************************************** CHALLENGE 1 *******************************************
		출처 : NUMBERTHEORY정수론 - 이모션미디어 조민형 지음 p.28 예제 3
					91이 소수인가 확인 문제
	보조정리3. n이 합성수(ompositite)이면, n은 1 < d <= sqrt(n)를 만족하는 약수 d를 가지고 있다.
****************************************************************************************************
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N_NUM 91 // p.28 ex. sqrt(269), sqrt(289)확인 완료

void prime(int, int *);
int prime2(int, int);

int main()
{
	int *ptr = (int *)calloc(N_NUM - 2, sizeof(char)); // 1 < primeTable < n_num
	prime(sqrt(N_NUM), ptr); //소수점 버림.

	//calloc 빈 공간 모두 0으로 초기화.
	for (int i = 0; i < ptr[i] != 0; i++)
	{
		if (!prime2(N_NUM, ptr[i]))
		{
			printf("%d는 %d(으)로 나눠지므로 소수가 아닙니다.\n", N_NUM, ptr[i]);
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
	//자연수에서 2는  1과 자기자신만을 약수로 가지는 수가 소수의 정의이기 때문에 무조건 소수이다.
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
