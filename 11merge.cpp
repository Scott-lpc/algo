#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//merge(v1begin,v1end,v2begin,v2end,v3begin)
void print4(int val)
{
	cout << val << " ";
}
void test16()
{
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	v3.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), v3.end(), print4);
}

int main11()
{
	test16();
	system("pause");
	return 0;
}