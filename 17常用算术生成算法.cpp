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
	//����3Ϊһ����ʼ�ۼ�ֵ
	int num=accumulate(v.begin(), v.end(),0);
	cout << num << endl;
}
//fill t���ָ��Ԫ��
void print17(int val)
{
	cout << val << " ";
}
void test23()
{
	vector<int>v;
	v.resize(10);  //����Ϊ0

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