#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//���������ظ�Ԫ�� ���ص�һ��λ�õ�����
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
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ�" << *it << endl;
	}
}

int main5()
{
	test07();
	system("pause");
	return 0;
}