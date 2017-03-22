/*
1008. 数组元素循环右移问题 (20)

一个数组A中存有N（N>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（M>=0）个位置，即将A中的数据由（A0 A1……AN-1）变换为（AN-M …… AN-1 A0 A1……AN-M-1）（最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

输入格式：每个输入包含一个测试用例，第1行输入N ( 1<=N<=100)、M（M>=0）；第2行输入N个整数，之间用空格分隔。

输出格式：在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

输入样例：
6 2
1 2 3 4 5 6
输出样例：
5 6 1 2 3 4
*/

#include "stdio.h"

int main(int argc, char const *argv[])
{
	int N,M,temp;
	int flag = 1;
	scanf("%d %d",&N,&M);
	// M可能大于N
	while(M > N)
		M -= N;
	int input[N];
	for (int i = 0; i < N; ++i)
	{
		scanf("%d",&input[i]);
	}
	// 将数组看为ab两部分，先全逆序，再部分倒序
	for (int i = 0; i < N/2; ++i)
	{
		temp = input[i];
		input[i] = input[N-i-1];
		input[N-i-1] = temp;
	}
	for (int i = 0; i < M/2; ++i)
	{
		temp = input[i];
		input[i] = input[M-i-1];
		input[M-i-1] = temp;
	}
	for (int i = M; i < (N-M)/2 + M; ++i)
	{
		temp = input[i];
		input[i] = input[N+M-i-1];
		input[N+M-i-1] = temp;
	}
	//输出
	for (int i = 0; i < N; ++i)
	{
		if (flag == 1)
		{
			printf("%d",input[i] );
			flag =0;
			continue;
		}
		printf(" %d",input[i] );
	}
	return 0;
}