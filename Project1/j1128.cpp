#include<iostream>
using namespace std;

/*
	题目描述：
班上有学生若干名，给出每名学生的年龄（整数），求班上所有学生的平均年龄，保留到小数点后两位。
输入：
第一行有一个整数n（1<= n <= 100），表示学生的人数。其后n行每行有1个整数，取值为15到25。
输出：
可能有多组测试数据，对于每组数据，
输出一行，该行包含一个浮点数，为要求的平均年龄，保留到小数点后两位。
样例输入：
2
18
17
样例输出：
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