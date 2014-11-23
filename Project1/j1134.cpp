#include<iostream>
#include<string>
#include<stdlib.h>
#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<ctype.h>
using namespace std;

/*
	题目描述：
    在情报传递过程中，为了防止情报被截获，往往需要对情报用一定的方式加密，简单的加密算法虽然不足以完全避免情报被破译，但仍然能防止情报被轻易的识别。我们给出一种最简的的加密方法，对给定的一个字符串，把其中从a-y,A-Y的字母用其后继字母替代，把z和Z用a和A替代，则可得到一个简单的加密字符串。
输入：
        可能有多组测试数据。每组测试数据的第一行是字符串的数目n， (也要使用get(s)读取字符串,再用n=atoi(s)获得整数数值)，其余n行每行一个字符串,用gets(s)方式读取这一行字符串.每个字符串长度小于80个字符。
输出：
    对于每组数据，输出每行字符串的加密字符串。
样例输入：
1
Hello! How are you!
样例输出：
Ifmmp! Ipx bsf zpv!
*/


int main()
{
	int n, i;
	char num[9], ss[81];
	while (gets(num))
	{
		n = atoi(num);
		while (n--)
		{
			gets(ss);
			for (i = 0; i < strlen(ss); i++)
			if (isalpha(ss[i]))
			{
				if (ss[i] == 'Z') ss[i] = 'A';
				else if (ss[i] == 'z') ss[i] = 'a';
				else ss[i] += 1;
			}
			puts(ss);
		}
	}
	return 0;
}