/*
1004. 成绩排名 (20)
读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
输入格式：每个测试输入包含1个测试用例，格式为
第1行：正整数n
第2行：第1个学生的姓名 学号 成绩
第3行：第2个学生的姓名 学号 成绩
… … …
第n+1行：第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。
输入样例：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
输出样例：
Mike CS991301
Joe Math990112
*/

#include "stdio.h"
#include "string.h"

int main()
{
	int max = -1, min = 101, score,i,n;
	char maxname[10],minname[10],maxnum[10],minnum[10],name[10],num[10];
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
		scanf("%s",name);
		scanf("%s",num);
		scanf("%d",&score);
		if (score > max)
		{
			max = score;
			strcpy(maxname,name);
			strcpy(maxnum,num);
		}
		if (score < min)
		{
			min = score;
			strcpy(minname,name);
			strcpy(minnum,num);
		}
	}

	printf("%s %s\n", maxname,maxnum);
	printf("%s %s\n", minname,minnum);

	return 0;
}