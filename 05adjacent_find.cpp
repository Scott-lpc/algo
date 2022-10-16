#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//查找相邻重复元素 返回第一个位置迭代器
void test07()
{
	vector<int>v;
	v.push_back(2);
	v.push_back(1);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);	
	v.push_back(7);
	auto it=adjacent_find(v.begin(), v.end());

	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到" << *it << endl;
	}
}

int main5()
{
	test07();
	system("pause");
	return 0;
}