#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//����������������
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
		cout << "�ҵ�" << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}

int main6()
{
	test08();
	system("pause");
	return 0;
}

