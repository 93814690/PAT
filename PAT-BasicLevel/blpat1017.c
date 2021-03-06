/*
1017. A除以B (20)

本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。

输入格式：

输入在1行中依次给出A和B，中间以1空格分隔。

输出格式：

在1行中依次输出Q和R，中间以1空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3

*/

#include "stdio.h"
#include "string.h"
#define MAXLEN 1000

int main(int argc, char const *argv[])
{
	char A[MAXLEN];
	int B,ALength,temp=0,mark=0;
	scanf("%s%d",A,&B);
	ALength = strlen(A);
	for (int i = 0; i < ALength; ++i)
	{
		temp = temp * 10 + (A[i] - 48);
		if (temp >= B)
		{
			printf("%d",temp/B );
			mark = 1;
		}else if (mark)
		{
			printf("0");
		}
		temp %= B;
	}

	if (mark == 0)
	{
		printf("0");
	}
	printf(" %d",temp );

	return 0;
}