#include<iostream>
using namespace std;

/*
	��Ŀ������
    ����һ����n�������ż�����Ͱ�n����һ�룻�������������n��� 3*n+ 1�󿳵�һ�룬ֱ��������Ϊ1Ϊֹ��
    �������Ҫ�����������ܽ�n�䵽1������ɼ�������
���룺
    ���԰������������ÿ����������һ������n,��nΪ0 ʱ��ʾ�����������1<=n<=10000��
�����
    ����ÿ��������������һ��������ʾ��Ҫ�����Ĳ���,ÿ�����ռһ�С�
�������룺
3
1
0
���������
5
0
*/

int main()
{
	int n, count;
	while (cin >> n)
	{
		if (n == 0)
			break;
		count = 0;
		while (n > 1)
		{
			if (n % 2 == 0)
				n = n / 2;
			else
			{
				n = (3 * n + 1) / 2;
			}
			count++;
		}
		cout << count << endl;
	}
	return 0;
}