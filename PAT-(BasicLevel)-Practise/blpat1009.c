/*
1009. 说反话 (20)

输入格式：测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多余的空格。

输出格式：每个测试用例的输出占一行，输出倒序后的句子。

输入样例：
Hello World Here I Come
输出样例：
Come I Here World Hello

*/

#include "stdio.h"

int main(int argc, char const *argv[])
{
	char input[80];
	int length = 0,end;
	gets(input);
	for (int i = 0; input[i] != '\0'; ++i)
	{
		length++;
	}
	end = length;
	for (int i = length; i >= 0; i--)
	{
		if (input[i] == ' ')
		{
			for (int j = i + 1; j < end; ++j)
			{
				printf("%c",input[j] );
			}
			printf(" ");
			end = i;
		}
	}
	for (int i = 0; i < end; ++i)
	{
		printf("%c",input[i] );
	}
	return 0;
}