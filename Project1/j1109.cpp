#include<iostream>
using namespace std;
/*
题目描述：
给定一个无向图和其中的所有边，判断这个图是否所有顶点都是连通的。
输入：
每组数据的第一行是两个整数 n 和 m（0<=n<=1000）。n 表示图的顶点数目，m 表示图中边的数目。如果 n 为 0 表示输入结束。随后有 m 行数据，每行有两个值 x 和 y（0<x, y <=n），表示顶点 x 和 y 相连，顶点的编号从 1 开始计算。输入不保证这些边是否重复。
输出：
对于每组输入数据，如果所有顶点都是连通的，输出"YES"，否则输出"NO"。
样例输入：
4 3
1 2
2 3
3 2
3 2
1 2
2 3
0 0
样例输出：
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