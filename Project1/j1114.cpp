#include<iostream>
using namespace std;

/*
	��Ŀ������
��һ������Ŀڴ����ܵ��ݻ���40��������ڴ����Ա��һЩ��Ʒ����Щ��Ʒ�������������40��John������n����Ҫ�õ�����Ʒ��ÿ����Ʒ������ֱ���a1��a2����an��John���Դ���Щ��Ʒ��ѡ��һЩ�����ѡ����������������40����ô�����������Ŀڴ���John�Ϳ��Եõ���Щ��Ʒ�����ڵ������ǣ�John�ж����ֲ�ͬ��ѡ����Ʒ�ķ�ʽ��
���룺
����ĵ�һ����������n (1 <= n <= 20)����ʾ��ͬ����Ʒ����Ŀ����������n�У�ÿ����һ��1��40֮������������ֱ����a1��a2����an��ֵ��
�����
�����ͬ��ѡ����Ʒ�ķ�ʽ����Ŀ��
�������룺
3
20
20
20
���������
3
*/

int volume = 40;
int count1 = 0;

void fill(int v, int thing[], int arraysize, int index)
{
	if (index >= arraysize)
		return;
	if (v == thing[index])
	{
		count1++;
	}
	if (v - thing[index] > 0)
	{
		fill(v - thing[index], thing, arraysize, index + 1);
	}
	fill(v, thing, arraysize, index + 1);
	return;
}

int main()
{
	int * thing ;
	int arraysize;
	while (cin >> arraysize)
	{
		thing = new int[arraysize];
		for (int i = 0; i < arraysize; i++)
			cin >> thing[i];
		fill(40, thing, arraysize, 0);
		cout << count1 << endl;
		count1 = 0;
		delete thing;
	}
	return 0;
}