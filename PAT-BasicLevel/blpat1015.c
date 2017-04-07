/*
PAT-Basic-1015 德才论

于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线L的考生也按总分排序，但排在第三类考生之后。

随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0, 100]内的整数。数字间以空格分隔。

输出格式：

输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。

输入样例：
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
输出样例：
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90

*/


#include "stdio.h"
#include "stdlib.h"
#define N 100000

typedef struct student
{
	int stuID;
	int M;//德分
	int T;//才分
}stu;

int comp(const void * a,const void * b)
{
	//如果两总分不相等情况降序
	if ((*(stu *)a).M + (*(stu *)a).T != (*(stu *)b).M + (*(stu *)b).T)	
	{
		return ((*(stu *)b).M + (*(stu *)b).T) - ((*(stu *)a).M + (*(stu *)a).T);
	}
	//如果两总分相等,按M排
	else if((*(stu *)a).M != (*(stu *)b).M)
		return (*(stu *)b).M - (*(stu *)a).M;
	//如果M相等按准考证升序排
	else
		return (*(stu *)a).stuID - (*(stu *)b).stuID;
}

int main(int argc, char const *argv[])
{
	int n,l,h;
	int countP1 = 0;
	int countP2 = 0;
	int countP3 = 0;
	int countP4 = 0;
	stu *p1 = (stu *)malloc(N*sizeof(stu));
	stu *p2 = (stu *)malloc(N*sizeof(stu));
	stu *p3 = (stu *)malloc(N*sizeof(stu));
	stu *p4 = (stu *)malloc(N*sizeof(stu));
	stu temp;
	scanf("%d%d%d",&n,&l,&h);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d%d",&temp.stuID,&temp.M,&temp.T);
		if ((temp.M >= l)&&(temp.T >= l))
		{
			if ((temp.M >= h)&&(temp.T >= h))
			{
				p1[countP1++] = temp;
			}
			else if (temp.M >= h)
			{
				p2[countP2++] = temp;
			}
			else if (temp.M >= temp.T)
			{
				p3[countP3++] = temp;
			}
			else
				p4[countP4++] = temp;
		}
	}
	qsort(p1,countP1,sizeof(stu),comp);
	qsort(p2,countP2,sizeof(stu),comp);
	qsort(p3,countP3,sizeof(stu),comp);
	qsort(p4,countP4,sizeof(stu),comp);

	printf("%d\n",countP1+countP2+countP3+countP4 );
	for (int i = 0; i < countP1; ++i)
	{
		printf("%d %d %d\n",p1[i].stuID,p1[i].M,p1[i].T );
	}
	for (int i = 0; i < countP2; ++i)
	{
		printf("%d %d %d\n",p2[i].stuID,p2[i].M,p2[i].T );
	}
	for (int i = 0; i < countP3; ++i)
	{
		printf("%d %d %d\n",p3[i].stuID,p3[i].M,p3[i].T );
	}
	for (int i = 0; i < countP4; ++i)
	{
		printf("%d %d %d\n",p4[i].stuID,p4[i].M,p4[i].T );
	}

	return 0;
}