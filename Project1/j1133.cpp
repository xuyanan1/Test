#include<iostream>
using namespace std;
#pragma warning(disable:4996)
/*
��Ŀ������
������ѧ�Ա������ĳɼ�ʩ��ƽ��ѧ�ּ����ƣ�GPA�����Ƚ�ѧ����ʵ�ʿ��ָ��ݲ�ͬ��ѧ�ƵĲ�ͬѧ�ְ�һ���Ĺ�ʽ���м��㡣
��ʽ���£�
ʵ�ʳɼ� ����
90����100 4.0
85����89 3.7
82����84 3.3
78����81 3.0
75����77 2.7
72����74 2.3
68����71 2.0
64����67 1.5
60����63 1.0
60���� 0
1��һ�ſγ̵�ѧ�ּ���=�ÿμ���*�ÿ�ѧ��
2����������=����ѧ�Ƽ���֮��/���пγ�ѧ��֮��
��Ҫ�����д�������ĳ��A���������㣨GPA����
���룺
��һ�� �ܵĿγ���n��n<10����
�ڶ��� ��Ӧ�γ̵�ѧ�֣�����ѧ�ּ��ÿո��������
������ ��Ӧ�γ̵�ʵ�ʵ÷֣�
�˴�������������־�Ϊ������
�����
�����һ�У��������㣬��ȷ��С�����2λС������printf("%.2f",GPA);��
�������룺
5
4 3 4 2 3
91 88 72 69 56
���������
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