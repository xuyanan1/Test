#include<iostream>
using namespace std;

/*
题目描述：
In the movie "Die Hard 3", Bruce Willis and Samuel L. Jackson were confronted with the following puzzle. They were given a 3-gallon jug and a 5-gallon jug and were asked to fill the 5-gallon jug with exactly 4 gallons. This problem generalizes that puzzle.
You have two jugs, A and B, and an infinite supply of water. There are three types of actions that you can use: (1) you can fill a jug, (2) you can empty a jug, and (3) you can pour from one jug to the other. Pouring from one jug to the other stops when the first jug is empty or the second jug is full, whichever comes first. For example, if A has 5 gallons and B has 6 gallons and a capacity of 8, then pouring from A to B leaves B full and 3 gallons in A.
A problem is given by a triple (Ca,Cb,N), where Ca and Cb are the capacities of the jugs A and B, respectively, and N is the goal. A solution is a sequence of steps that leaves exactly N gallons in jug B. The possible steps are
fill A
fill B
empty A
empty B
pour A B
pour B A
success
where "pour A B" means "pour the contents of jug A into jug B", and "success" means that the goal has been accomplished.
You may assume that the input you are given does have a solution.
输入：
Input to your program consists of a series of input lines each defining one puzzle. Input for each puzzle is a single line of three positive integers: Ca, Cb, and N. Ca and Cb are the capacities of jugs A and B, and N is the goal. You can assume 0 < Ca <= Cb and N <= Cb <=1000 and that A and B are relatively prime to one another.
输出：
Output from your program will consist of a series of instructions from the list of the potential output lines which will result in either of the jugs containing exactly N gallons of water. The last line of output for each puzzle should be the line "success". Output lines start in column 1 and there should be no empty lines nor any trailing spaces.
样例输入：
3 5 4
5 7 3
样例输出：
fill B
pour B A
empty A
pour B A
fill B
pour B A
success
fill A
pour A B
fill A
pour A B
empty B
pour A B
success
*/

/*
	解题思路
	>输入的三个数：a,b,n;
	> 由题不定方程ax+by=n必定有解
	> 如果b=n，则fill B即可，否则用试探法求出这样的两组解（a1，b1）及（a2，b2），其中a1 >0，b1<0；a1是满足方程的最小正整数；a2<0，b2>0，a2是满足条件的最大负整数；
	> (i)  如果|a1|+|b1|<|a2|+|b2|-1,则fill A a1次，每次fill A后,pour到B，如果B满则empty B,再将A中剩下的pour到B，这样empty B |b1|次以后，即可得解；（因为a*a1+b*b1=n）
	> (ii)如果|a1|+|b1|>=|a2|+|b2|-1,则fill B b2次，每次fill B后,pour到A，如果A满则empty A,再将B中剩下的pour到A，这样经过empty A |a2|-1次以后，再将A装滿，B中剩下的就是n了；
*/
void get(int &a1, int &b1, int &a2, int &b2,int a,int b,int goal)
{
	a1 = 0;
	a2 = 0;
	b1 = 0;
	b2 = 0;
	int temp;
	while ((temp=a1*a - b1*b) != goal)
	{
		if (temp > goal)
			b1++;
		else
			a1++;
	}
	while ((temp = b2*b-a2*a) != goal)
	{
		if (temp > goal)
			a2++;
		else
			b2++;
	}
	return;
}

int main()
{
	int maxa, maxb, goal;                         //maxa是a容器的容积，maxb是b容器的容积，goal是要得到的体积
	int a, b;                                     //a,b分别是两个容器实际操作时液体的体积
	int a1, a2, b1, b2;                           //这四个数是用来保存ax+by=n的解的
	while (cin >> maxa >> maxb >> goal)
	{
		a = 0;
		b = 0;
		if (maxa == goal)
		{
			std::cout << "fill A\nsuccess\n";
			continue;
		}	
		if (maxb == goal)
		{
			std::cout << "fill B\nsuccess\n";
			continue;
		}
		get(a1, b1, a2, b2, maxa, maxb, goal);          //用来获取a1,a2,b1,b2
		//std::cout << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
		if ((a1 + b1) < (a2 + b2 - 1))
		{
			while (b != goal)
			{
				if (a == 0)
				{
					std::cout << "fill A" << endl;
					a = maxa;
				}
				std::cout << "pour A B" << endl;
				if (a + b>maxb)
				{
					a = a + b - maxb;
					b = maxb;
				}
				else
				{
					b = a + b;
					a = 0;
				}
				if (b == goal)                            //每次对b进行操作时都要判断一下结果是否满足条件了，防止多余的步骤
					break;
				if (b == maxb)
				{
					std::cout << "empty B" << endl;
					b = 0;
					std::cout << "pour A B" << endl;
					b = a;
					a = 0;
				}
			}
		}
		else
		{
			while (b != goal)
			{
				if (b == 0)
				{
					b = maxb;
					std::cout << "fill B" << endl;
				}
				std::cout << "pour B A" << endl;
				if (a + b > maxa)
				{
					b = a + b - maxa;
					a = maxa;
				}
				else
				{
					a = a + b;
					b = 0;
				}
				if (b == goal)                     //每次对b进行操作时都要判断一下结果是否满足条件了，防止多余的步骤
					break;
				if (a == maxa)
				{
					std::cout << "empty A" << endl;
					a = 0;
					std::cout << "pour B A" << endl;
					if (a + b > maxa)
					{
						b = a + b - maxa;
						a = maxa;
					}
					else
					{
						a = a + b;
						b = 0;
					}
				}
			}
		}
		std::cout << "success" << endl;
	}
}