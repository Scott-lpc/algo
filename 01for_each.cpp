#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//普通函数
void print01(int val)
{
	cout << val <<" ";
}
//仿函数
class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print01);  //函数名
	cout << endl;

	for_each(v.begin(), v.end(), print02());  //函数对象
}
int main1()
{
	test01();
	system("pause");
	return 0;
}