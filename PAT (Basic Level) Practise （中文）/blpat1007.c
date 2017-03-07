/*
1007. 素数对猜想 (20)

让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。

输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：
20
输出样例：
4
*/

#include "stdio.h"
#include "math.h"
#define Max 100000

int main(int argc, char const *argv[])
{
	int prime[Max]={1,1};
	int count = 0;
	int i,j,n;
	scanf("%d",&n);
	for (i = 2; i <= sqrt(Max); ++i)
	{
		if (!prime[i])
		{
			for (j = i * i; j < Max; j += i)
			{
				prime[j] = 1;
			}
		}
	}
	for ( i = 2; i <= n; ++i)
	{
		if (prime[i] ==0 && i - j == 2)
		{
			count++;
			j = i;
			continue;
		}
		if (!prime[i])
		{
			j = i;
		}
	}
	printf("%d\n", count);

	return 0;
}