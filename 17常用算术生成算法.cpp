#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;

void test22()
{
	vector<int>v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}
	//参数3为一个起始累加值
	int num=accumulate(v.begin(), v.end(),0);
	cout << num << endl;
}
//fill t填充指定元素
void print17(int val)
{
	cout << val << " ";
}
void test23()
{
	vector<int>v;
	v.resize(10);  //这样为0

	fill(v.begin(), v.end(), 100);
	for_each(v.begin(), v.end(), print17);
}

int main17()
{
	test22();
	test23();
	system("pause");
	return 0;
}