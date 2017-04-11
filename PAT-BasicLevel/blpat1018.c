/*
1018. 锤子剪刀布 (20)

大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：


现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：

输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。

输出格式：

输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B

*/

#include "stdio.h"


int main(int argc, char const *argv[])
{
	int xwin=0,ywin=0,xb=0,xc=0,xj=0,yb=0,yc=0,yj=0,n;
	char x,y;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf(" %c %c",&x,&y);
		if (x == 'B' && y == 'C')
		{
			xwin++;
			xb++;
			continue;
		}
		if (x == 'C' && y == 'J')
		{
			xwin++;
			xc++;
			continue;
		}
		if (x == 'J' && y == 'B')
		{
			xwin++;
			xj++;
			continue;
		}
		if (y == 'B' && x == 'C')
		{
			ywin++;
			yb++;
			continue;
		}
		if (y == 'C' && x == 'J')
		{
			ywin++;
			yc++;
			continue;
		}
		if (y == 'J' && x == 'B')
		{
			ywin++;
			yj++;
			continue;
		}
	}
	printf("%d %d %d\n",xwin,n-xwin-ywin,ywin );
	printf("%d %d %d\n",ywin,n-xwin-ywin,xwin );
	if (xb >= xc && xb >= xj)
	{
		printf("B ");
	}else if (xc >= xj)
	{
		printf("C ");
	}else
	printf("J ");
	if (yb >= yc && yb >= yj)
	{
		printf("B");
	}else if (yc >= xj)
	{
		printf("C");
	}else
	printf("J");

	return 0;
}