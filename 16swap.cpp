#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void print16(int val)
{
	cout << val << " ";
}
void test21()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(20);
	v.push_back(40);
	v.push_back(20);
	v.push_back(70);
	vector<int>v2;
	v2.push_back(100);
	v2.push_back(200);
	v2.push_back(300);
	v2.push_back(400);
	for_each(v.begin(), v.end(), print16);
	swap(v, v2);
	for_each(v.begin(), v.end(), print16);
}

int main16()
{
	test21();
	system("pause");
	return 0;
}