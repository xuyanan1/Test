#include<iostream>
using namespace std;

/*
	会下国际象棋的人都很清楚：皇后可以在横、竖、斜线上不限步数地吃掉其他棋子。如何将8个皇后放在棋盘上（有8 * 8个方格），使它们谁也不能被吃掉！这就是著名的八皇后问题。 
	对于某个满足要求的8皇后的摆放方法，定义一个皇后串a与之对应，即a=b1b2...b8，其中bi为相应摆法中第i行皇后所处的列数。已经知道8皇后问题一共有92组解（即92个不同的皇后串）。
	给出一个数b，要求输出第b个串。串的比较是这样的：皇后串x置于皇后串y之前，当且仅当将x视为整数时比y小。
	输入：
	第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数b(1 <= b <= 92)
	输出：
	输出有n行，每行输出对应一个输入。输出应是一个正整数，是对应于b的皇后串。
*/

#define N 8
int sum[100][9]; //用于存储生成的序列
int d = 0;       //标识sum存储了多少个序列
int b[9];        //标识每一行应该从哪一列开始测试

//测试a数组中下标为index，从x-8中第一个满足要求的数，并返回，如果没有则返回-1
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
				//不满足要求的情况有四种，1不能同行，数据结构本身已经满足；2不能同列，即数组a中所有的数只能出现一次；3和4，不能出现在对角线上
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

//用于把刚找到的符合要求的序列放到sum中存储起来
void write1(int a[])
{
	for (int i = 1; i < 9; i++)
		sum[d][i] = a[i];
	d++;
	return;
}

//用递归的思路，生成序列
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
		b[i] = 1;                 //初始化b 表示每一行都从第1列开始测试是否满足要求
	int a[9];                    //临时保存生成序列
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