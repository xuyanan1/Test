#include<iostream>
#include<string>
#include<stdlib.h>
#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<ctype.h>
using namespace std;

/*
	��Ŀ������
    ���鱨���ݹ����У�Ϊ�˷�ֹ�鱨���ػ�������Ҫ���鱨��һ���ķ�ʽ���ܣ��򵥵ļ����㷨��Ȼ��������ȫ�����鱨�����룬����Ȼ�ܷ�ֹ�鱨�����׵�ʶ�����Ǹ���һ�����ĵļ��ܷ������Ը�����һ���ַ����������д�a-y,A-Y����ĸ��������ĸ�������z��Z��a��A�������ɵõ�һ���򵥵ļ����ַ�����
���룺
        �����ж���������ݡ�ÿ��������ݵĵ�һ�����ַ�������Ŀn�� (ҲҪʹ��get(s)��ȡ�ַ���,����n=atoi(s)���������ֵ)������n��ÿ��һ���ַ���,��gets(s)��ʽ��ȡ��һ���ַ���.ÿ���ַ�������С��80���ַ���
�����
    ����ÿ�����ݣ����ÿ���ַ����ļ����ַ�����
�������룺
1
Hello! How are you!
���������
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