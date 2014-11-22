#include<iostream>
#include<queue>
#include<stack>
using namespace std;

/*
	说明：该程序可以解决问题，但使用了树，进行广度优先遍历，计算量太大，内存占用过多，导致时间超时。
*/

/*
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


class can
{
	
public:
	static int maxA, maxB,c;
	int a, b;
	int count;
	can(int a1, int b1,int c)
	{
		a = a1;
		b = b1;
		count = c;
	}
	can(const can &c)
	{
		a = c.a;
		b = c.b;
		count = c.count;
	}
	void filla()
	{
		a = maxA;
	}
	void fillb()
	{
		b = maxB;
	}
	void emptya()
	{
		a = 0;
	}
	void emptyb()
	{
		b = 0;
	}
	void pourab()
	{
		if (a + b > maxB)
		{
			a = a + b - maxB;
			b = maxB;
		}
		else
		{
			b = a + b;
			a = 0;
		}
	}
	void pourba()
	{
		if (a + b > maxA)
		{
			b = a + b - maxA;
			a = maxA;
		}
		else
		{
			a = a + b;
			b = 0;
		}
	}
};
int can::maxA = 0;
int can::maxB = 0;
int can::c = 0;

int manage(int maxa, int maxb, int goal)
{
	queue<can> q;
	can::maxA = maxa;
	can::maxB = maxb;
	can::c = 0;
	can c(0, 0, 0);
	q.push(c);
	while (!q.empty())
	{
		c = q.front();
		if (c.b == goal)
			return c.count;
		c.filla();
		c.count=(++can::c);
		q.push(c);
		c = q.front();
		c.fillb();
		c.count = (++can::c);
		q.push(c);
		c = q.front();
		c.emptya();
		c.count = (++can::c);
		q.push(c);
		c = q.front();
		c.emptyb();
		c.count = (++can::c);
		q.push(c);
		c = q.front();
		c.pourab();
		c.count = (++can::c);
		q.push(c);
		c = q.front();
		c.pourba();
		c.count = (++can::c);
		q.push(c);
		q.pop();
	}
	return -1;
}

int father(int n)
{
	if (n == 0)
		return 0;
	if (n % 6 == 0)
		return n / 6 - 1;
	return n / 6;
}

bool printsuccess(int count)
{
	stack<int> s;
	while (count != 0)
	{
		s.push(count % 6);
		count = father(count);
	}
	while (!s.empty())
	{
		switch (s.top())
		{
		case 1:
			cout << "fill A" << endl;
			break;
		case 2:
			cout << "fill B" << endl;
			break;
		case 3:
			cout << "empty A" << endl;
			break;
		case 4:
			cout << "empty B" << endl;
			break;
		case 5:
			cout << "pour A B" << endl;
			break;
		case 0:
			cout << "pour B A" << endl;
			break;
		default:
			break;
		}
		s.pop();
	}	
	cout << "success" << endl;
		return true;
}

int main()
{
	int mA, mB, g;
	int turn=0;
	
	while (cin >> mA >> mB >> g)
	{
		turn = manage(mA, mB, g);
		//cout << turn << endl;
		if (turn != -1)
			printsuccess(turn);
		else
			cout << "false" << endl;
	}
	return 0;
}