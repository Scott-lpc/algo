#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//必须容器有序序列
void test08()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	bool ret = binary_search(v.begin(), v.end(), 9);
	if (ret)
	{
		cout << "找到" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

int main6()
{
	test08();
	system("pause");
	return 0;
}

