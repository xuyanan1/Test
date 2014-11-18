#include<iostream>
using namespace std;

/*
	���¹���������˶���������ʺ�����ںᡢ����б���ϲ��޲����سԵ��������ӡ���ν�8���ʺ���������ϣ���8 * 8�����񣩣�ʹ����˭Ҳ���ܱ��Ե�������������İ˻ʺ����⡣ 
	����ĳ������Ҫ���8�ʺ�İڷŷ���������һ���ʺ�a��֮��Ӧ����a=b1b2...b8������biΪ��Ӧ�ڷ��е�i�лʺ��������������Ѿ�֪��8�ʺ�����һ����92��⣨��92����ͬ�Ļʺ󴮣���
	����һ����b��Ҫ�������b���������ıȽ��������ģ��ʺ�x���ڻʺ�y֮ǰ�����ҽ�����x��Ϊ����ʱ��yС��
	���룺
	��1���ǲ������ݵ�����n���������n�����롣ÿ���������ռ1�У�����һ��������b(1 <= b <= 92)
	�����
	�����n�У�ÿ�������Ӧһ�����롣���Ӧ��һ�����������Ƕ�Ӧ��b�Ļʺ󴮡�
*/

#define N 8
int sum[100][9]; //���ڴ洢���ɵ�����
int d = 0;       //��ʶsum�洢�˶��ٸ�����
int b[9];        //��ʶÿһ��Ӧ�ô���һ�п�ʼ����

//����a�������±�Ϊindex����x-8�е�һ������Ҫ������������أ����û���򷵻�-1
int generate(int a[], int index, int x)
{
	if (index > 8)
		return -1;

		int indexj = 1;
		bool exist = false;
		int val;
		for (val = x; val < 9; val++)
		{
			indexj = 1;
			while (indexj < index)
			{
				//������Ҫ�����������֣�1����ͬ�У����ݽṹ�����Ѿ����㣻2����ͬ�У�������a�����е���ֻ�ܳ���һ�Σ�3��4�����ܳ����ڶԽ�����
				if (a[indexj] == val || (index - indexj) == val - a[indexj] || (index - indexj) == a[indexj]-val) 
					break;
				indexj++;
			}
			if (indexj == index)
			{
				exist = true;
				break;
			}
		}
		if (exist)
			return val;
		else
			return -1;
}

//���ڰѸ��ҵ��ķ���Ҫ������зŵ�sum�д洢����
void write1(int a[])
{
	for (int i = 1; i < 9; i++)
		sum[d][i] = a[i];
	d++;
	return;
}

//�õݹ��˼·����������
bool generate1(int a[], int index)
{
	if (index == 9)
	{
		write1(a);
		return true;
	}
	while (b[index]<9)
	{
		int val = generate(a, index, b[index]);
		if (val > -1)
		{
			a[index] = val;
			b[index] = val + 1;
			generate1(a, index + 1);
		}
		else
			break;
	}
	b[index] = 1;
		return true;
}



int main()
{
	for (int i = 0; i < 9; i++)
		b[i] = 1;                 //��ʼ��b ��ʾÿһ�ж��ӵ�1�п�ʼ�����Ƿ�����Ҫ��
	int a[9];                    //��ʱ������������
	generate1(a, 1);
	int query;
	int times;
	cin >> times;
	for (int i = 0; i < times; i++)
	{
		cin >> query;
		for (int j = 1; j < 9; j++)
			cout << sum[query - 1][j];
		cout << endl;
	}
	return 0;
}