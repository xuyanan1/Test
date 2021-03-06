#include<iostream>
using namespace std;

/*
	题目描述：
有一个神奇的口袋，总的容积是40，用这个口袋可以变出一些物品，这些物品的总体积必须是40。John现在有n个想要得到的物品，每个物品的体积分别是a1，a2……an。John可以从这些物品中选择一些，如果选出的物体的总体积是40，那么利用这个神奇的口袋，John就可以得到这些物品。现在的问题是，John有多少种不同的选择物品的方式。
输入：
输入的第一行是正整数n (1 <= n <= 20)，表示不同的物品的数目。接下来的n行，每行有一个1到40之间的正整数，分别给出a1，a2……an的值。
输出：
输出不同的选择物品的方式的数目。
样例输入：
3
20
20
20
样例输出：
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