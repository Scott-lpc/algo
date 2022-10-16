#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
//copy(vbegin,vend,v2.begin)
void print6(int val)
{
	cout << val << " ";
}
void test18()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int>v2;
	v2.resize(v1.size());  //×Ô¶¯ÖÃÎª0£¡£¡£¡£¡£¡£¡£¡£¡£¡
	for_each(v2.begin(), v2.end(), print6);
	copy(v1.begin() + 4, v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), print6);
}
int main13()
{
	test18();
	system("pause");
	return 0;
}