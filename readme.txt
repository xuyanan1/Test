

1031题
题目描述：
    对于一个数n，如果是偶数，就把n砍掉一半；如果是奇数，把n变成 3*n+ 1后砍掉一半，直到该数变为1为止。
    请计算需要经过几步才能将n变到1，具体可见样例。
输入：
    测试包含多个用例，每个用例包含一个整数n,当n为0 时表示输入结束。（1<=n<=10000）
输出：
    对于每组测试用例请输出一个数，表示需要经过的步数,每组输出占一行。
样例输入：
3
1
0
样例输出：
5
0

1109题
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


1110题：
N只小白鼠(1 <= N <= 100)，每只鼠头上戴着一顶有颜色的帽子。现在称出每只白鼠的重量，要求按照白鼠重量从大到小的顺序输出它们头上帽子的颜色。帽子的颜色用“red”，“blue”等字符串来表示。不同的小白鼠可以戴相同颜色的帽子。白鼠的重量用整数表示。
输入：
多案例输入，每个案例的输入第一行为一个整数N，表示小白鼠的数目。
下面有N行，每行是一只白鼠的信息。第一个为不大于100的正整数，表示白鼠的重量，；第二个为字符串，表示白鼠的帽子颜色，字符串长度不超过10个字符。
注意：白鼠的重量各不相同。
输出：
每个案例按照白鼠的重量从大到小的顺序输出白鼠的帽子颜色。


1114题
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


1128题
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


1140题：
题目描述：
会下国际象棋的人都很清楚：皇后可以在横、竖、斜线上不限步数地吃掉其他棋子。如何将8个皇后放在棋盘上（有8 * 8个方格），使它们谁也不能被吃掉！这就是著名的八皇后问题。 
对于某个满足要求的8皇后的摆放方法，定义一个皇后串a与之对应，即a=b1b2...b8，其中bi为相应摆法中第i行皇后所处的列数。已经知道8皇后问题一共有92组解（即92个不同的皇后串）。
给出一个数b，要求输出第b个串。串的比较是这样的：皇后串x置于皇后串y之前，当且仅当将x视为整数时比y小。
输入：
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数b(1 <= b <= 92)
输出：
输出有n行，每行输出对应一个输入。输出应是一个正整数，是对应于b的皇后串。
样例输入：
2
1
92
样例输出：
15863724
84136275

1147题
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

