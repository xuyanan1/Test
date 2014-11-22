#include<iostream>
using namespace std;
/*
��Ŀ������
����һ������ͼ�����е����бߣ��ж����ͼ�Ƿ����ж��㶼����ͨ�ġ�
���룺
ÿ�����ݵĵ�һ������������ n �� m��0<=n<=1000����n ��ʾͼ�Ķ�����Ŀ��m ��ʾͼ�бߵ���Ŀ����� n Ϊ 0 ��ʾ�������������� m �����ݣ�ÿ��������ֵ x �� y��0<x, y <=n������ʾ���� x �� y ����������ı�Ŵ� 1 ��ʼ���㡣���벻��֤��Щ���Ƿ��ظ���
�����
����ÿ���������ݣ�������ж��㶼����ͨ�ģ����"YES"���������"NO"��
�������룺
4 3
1 2
2 3
3 2
3 2
1 2
2 3
0 0
���������
NO
YES
*/

int edge[1000][2] = { 0 };
int node1[1001] = { 0 };
int nodecount, edgecount;

void dfs(int n)
{
	int nodetemp;
	for (int i = 0; i < edgecount; i++)
	{
		nodetemp = -1;
		if (edge[i][0] == n)
		{
			nodetemp=edge[i][1];
		}
		if (edge[i][1] == n)
		{
			nodetemp = edge[i][0];
		}
		if (nodetemp > -1 && node1[nodetemp] == 0)
		{
			node1[nodetemp] = 1;
			dfs(nodetemp);
		}
	}
	return;
}

int main()
{
	
	bool flag = true;
	while (std::cin>>nodecount>>edgecount)
	{
		for (int i = 0; i < 1001; i++)
			node1[i] = 0;
		flag = true;
		if (nodecount == 0 && edgecount == 0)
			break;
		for (int i = 0; i < edgecount; i++)
			cin >> edge[i][0] >> edge[i][1];
		if (nodecount < 2)
		{
			cout << "YES" << endl;
			continue;
		}
		
		node1[1] = 1;
		node1[0] = 1;
		dfs(1);
		for (int i = 1; i <= nodecount; i++)
		{
			if (node1[i] == 0)
				flag = false;
		}

		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}