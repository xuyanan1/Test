#include<iostream>
using namespace std;

/*
	��Ŀ������
������ѧ��������������ÿ��ѧ�������䣨�����������������ѧ����ƽ�����䣬������С�������λ��
���룺
��һ����һ������n��1<= n <= 100������ʾѧ�������������n��ÿ����1��������ȡֵΪ15��25��
�����
�����ж���������ݣ�����ÿ�����ݣ�
���һ�У����а���һ����������ΪҪ���ƽ�����䣬������С�������λ��
�������룺
2
18
17
���������
17.50
*/

int main()
{
	int sum, age,num;
	double average;
	while (cin >> num)
	{
		sum = 0;
		for (int i = 0; i < num; i++)
		{
			cin >> age;
			sum += age;
		}
		average = double(sum) / num;
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << average << endl;
	}
	return 0;
}