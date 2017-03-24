/*
1013. 数素数 (20)

令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

*/


#include "stdio.h"
#define NumOfPrime 10001
#define NumOfMax 120001

int main(int argc, char const *argv[])
{
	int m,n,k=0,prime[NumOfPrime];
	_Bool check[NumOfMax] = {1,1};
	//打印素数表
	for (int i = 2; i < NumOfMax && k < NumOfPrime; ++i)
	{
		if (!check[i])
		{
			prime[k++] = i;			
		}
		for (int j = 0; j < k && i * prime[j] < NumOfMax; j ++)
		{
			check[i*prime[j]] = 1;
			if (i%prime[j] == 0)
			{
				break;
			}
		}
	}

	int count = 0;
	scanf("%d%d",&m,&n);
	for (int i = m - 1; i < n; ++i)
	{
		if (count<9)
		{
			if (count)
			{
				printf(" ");
			}
			printf("%d",prime[i] );
			count++;
		}
		else
		{
			printf(" %d\n",prime[i] );
			count = 0;
		}	

	}

	return 0;
}
