#include<iostream>
using namespace std;
#pragma warning(disable:4996)
/*
题目描述：
北京大学对本科生的成绩施行平均学分绩点制（GPA）。既将学生的实际考分根据不同的学科的不同学分按一定的公式进行计算。
公式如下：
实际成绩 绩点
90——100 4.0
85——89 3.7
82——84 3.3
78——81 3.0
75——77 2.7
72——74 2.3
68——71 2.0
64——67 1.5
60——63 1.0
60以下 0
1．一门课程的学分绩点=该课绩点*该课学分
2．总评绩点=所有学科绩点之和/所有课程学分之和
现要求你编写程序求出某人A的总评绩点（GPA）。
输入：
第一行 总的课程数n（n<10）；
第二行 相应课程的学分（两个学分间用空格隔开）；
第三行 对应课程的实际得分；
此处输入的所有数字均为整数。
输出：
输出有一行，总评绩点，精确到小数点后2位小数。（printf("%.2f",GPA);）
样例输入：
5
4 3 4 2 3
91 88 72 69 56
样例输出：
2.52
*/

int main()
{
	int grade[10], credit[10];
	int lessonnum,creditsum;
	double gpa[10], g, gpa1[10][2] = { { 60, 0 }, { 63, 1.0 }, { 67, 1.5 }, { 71, 2.0 }, { 74, 2.3 }, { 77, 2.7 }, { 81, 3.0 }, { 84, 3.3 }, { 89, 3.7 }, {100,4.0} };
	//freopen("1.txt", "r", stdin);
	while (cin >> lessonnum)
	{
		for (int i = 0; i < lessonnum; i++)
			cin >> credit[i];
		for (int i = 0; i < lessonnum; i++)
			cin >> grade[i];

		int j;
		for (int i = 0; i < lessonnum; i++)
		{
			j = 0;
			while (grade[i]>gpa1[j][0])
			{
				j++;
			}
			gpa[i] = gpa1[j][1];
		}
		g = 0;
		creditsum = 0;
		for (int i = 0; i < lessonnum; i++)
		{
			g = g + gpa[i] * credit[i];
			creditsum += credit[i];
		}
			
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << g / creditsum << endl;
		
	}
	return 0;

}