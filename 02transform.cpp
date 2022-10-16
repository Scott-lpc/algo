#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Transform
{
public:
	int operator()(int v)
	{
		return v;
	}
};
class print03
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>vt;
	vt.resize(v.size()); //需要先定义大小！！！！！

	transform(v.begin(), v.end(), vt.begin(), Transform());

	for_each(vt.begin(), vt.end(), print03());
}

int main2()
{
	test02();
	system("pause");
	return 0;
}