#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
void print5(int val)
{
	cout << val << " ";
}
void test17()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(23);
	v.push_back(45);
	for_each(v.begin(), v.end(), print5);
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), print5);
}

int main12()
{
	test17();
	system("pause");
	return 0;
}