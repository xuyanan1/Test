#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class mouse
{
private:
	int weight;
	string hatcolor;
public:
	mouse(int w, string h)
	{
		weight = w;
		hatcolor = h;
	}
	int getWeight()
	{
		return weight;
	}
	void setWeight(int w)
	{
		weight = w;
		return;
	}
	string getHatColor()
	{
		return hatcolor;
	}
	void setHatColor(string h)
	{
		hatcolor = h;
		return;
	}
	friend bool operator >(mouse a, mouse b)
	{
		return a.weight > b.weight;
	}
	//friend bool greater(mouse a, mouse b)
	//{
		//return a.weight > b.weight;
	//}
};

bool greater(mouse a, mouse b)
{
	return a.getWeight() > b.getWeight();
}

int main()
{
	
	vector<mouse> m;
	int weight;
	string color;
	int num = 0;
	while (cin >> num)
	{
		for (int i = 0; i < num; i++)
		{
			cin >> weight >> color;
			mouse a(weight, color);
			m.push_back(a);
		}
		sort(m.begin(), m.end(), greater);
		vector<mouse>::iterator it;
		for (it = m.begin(); it != m.end(); it++)
			cout << (*it).getHatColor() << endl;
		m.clear();
	}
	//copy(m.begin(), m.end(), ostream_iterator<mouse>(cout, " "));
	
	return 0;


}